/*
 * nb-qemu
 * 
 * Copyright (c) 2019 Michael Goffioul
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#define LOG_TAG "libnb-qemu"
#define LOG_NDEBUG 0

#include <map>
#include <memory>
#include <android-base/strings.h>
#include <log/log.h>
#include "Library.h"
#include "QemuBridge.h"
#include "QemuCore.h"
#include "QemuCpu.h"
#include "QemuMemory.h"
#include "Trampoline.h"

using android::base::Split;
using android::base::EndsWith;
using android::base::StartsWith;

class QemuBridgeImpl
{
public:
    QemuBridgeImpl() {}
    ~QemuBridgeImpl() {}

public:
    bool initialize();
    bool is_path_supported(const std::string& path) const;
    void *load_library(const std::string& filename);
    void *get_trampoline(void *lib_handle, const std::string& name, const std::string& shorty);
    const char *get_error();

private:
    uint32_t initialize_;
    uint32_t load_library_;
    uint32_t get_library_symbol_;
    uint32_t allocate_thread_;
    uint32_t get_error_;

    std::map<void *, std::shared_ptr<Library>> libraries_;
    std::map<std::string, std::shared_ptr<Library>> named_libraries_;

    std::mutex mutex_;
};
static std::shared_ptr<QemuBridgeImpl> impl_;

bool QemuBridgeImpl::initialize()
{
    if (QemuCore::initialize()) {
        initialize_ = QemuCore::lookup_symbol("nb_qemu_initialize");
        ALOGV("QemuBridge::initialize_: %p", reinterpret_cast<void *>(initialize_));
        load_library_ = QemuCore::lookup_symbol("nb_qemu_loadLibrary");
        ALOGV("QemuBridge::load_library_: %p", reinterpret_cast<void *>(load_library_));
        get_library_symbol_ = QemuCore::lookup_symbol("nb_qemu_getLibrarySymbol");
        ALOGV("QemuBridge::get_library_symbol_: %p", reinterpret_cast<void *>(get_library_symbol_));
        allocate_thread_ = QemuCore::lookup_symbol("nb_qemu_allocateThread");
        ALOGV("QemuBridge::allocate_thread_: %p", reinterpret_cast<void *>(allocate_thread_));
        get_error_ = QemuCore::lookup_symbol("nb_qemu_getError");
        ALOGV("QemuBridge::get_error_: %p", reinterpret_cast<void *>(get_error_));
        if (initialize_) {
            QemuCpu::get()->call(initialize_);
            return true;
        }
    }
    return false;
}

bool QemuBridgeImpl::is_path_supported(const std::string& path) const
{
    if (path.empty())
        return false;

    for (auto& s : Split(path, ":")) {
        if (EndsWith(s, "/arm") || EndsWith(s, "/armeabi-v7a") || EndsWith(s, "/fake-libs"))
            continue;
        else
            return false;
    }

    return true;
}

void *QemuBridgeImpl::load_library(const std::string& filename)
{
    std::lock_guard<std::mutex> lock(mutex_);
    std::map<std::string, std::shared_ptr<Library>>::const_iterator it = named_libraries_.find(filename);

    if (it != named_libraries_.end()) {
        return it->second->get_handle();
    }

    if (load_library_) {
        size_t length = filename.length();
        QemuMemory::Malloc p(length + 1);
        uint32_t ret = 0;

        if (p) {
            p.memcpy(filename.c_str(), length + 1);
            ret = QemuCpu::get()->call(load_library_, p.get_address());
        }

        if (ret) {
            std::shared_ptr<Library> lib(new Library(filename, ret));

            libraries_[lib->get_handle()] = lib;
            named_libraries_[filename] = lib;
            ALOGI("Loaded library %s", filename.c_str());

            return lib->get_handle();
        }
    }

    return nullptr;
}

void *QemuBridgeImpl::get_trampoline(void *lib_handle, const std::string& name, const std::string& shorty)
{
    std::lock_guard<std::mutex> lock(mutex_);
    std::map<void *, std::shared_ptr<Library>>::const_iterator it = libraries_.find(lib_handle);

    if (it == libraries_.end()) {
        ALOGE("Invalid library handle: %p", lib_handle);
        return nullptr;
    }

    std::shared_ptr<Library> lib = it->second;
    std::shared_ptr<Trampoline> tramp = lib->get_trampoline(name);

    if (tramp) {
        return tramp->get_handle();
    }

    if (get_library_symbol_) {
        size_t length = name.length();
        QemuMemory::Malloc p(length + 1);
        uint32_t ret = 0;

        if (p) {
            p.memcpy(name.c_str(), length + 1);
            ret = QemuCpu::get()->call(get_library_symbol_, lib->get_address(), p.get_address());
        }

        if (ret) {
            tramp.reset(new Trampoline(name, ret, shorty, StartsWith(name, "Java_")));
            lib->add_trampoline(tramp);
            ALOGI("Loaded trampoline %s from %s", name.c_str(), lib->get_name().c_str());

            return tramp->get_handle();
        }
    }

    return nullptr;
}

const char *QemuBridgeImpl::get_error()
{
  static std::string s_error;

  if (get_error_) {
      QemuMemory::String q_error(QemuCpu::get()->call(get_error_));
      s_error = q_error.c_str();
  }

  return s_error.c_str();
}

namespace QemuBridge {

bool initialize()
{
    QemuBridgeImpl *impl = new QemuBridgeImpl();

    if (impl->initialize()) {
        impl_.reset(impl);
        return true;
    }
    else {
        delete impl;
        return false;
    }
}

bool is_supported(const std::string& /* libpath */)
{
    // Not implemented
    return false;
}

bool is_path_supported(const std::string& path)
{
    return impl_->is_path_supported(path);
}

void *load_library(const std::string& filename)
{
    return impl_->load_library(filename);
}

void *get_trampoline(void *lib_handle, const std::string& name, const std::string& shorty)
{
    return impl_->get_trampoline(lib_handle, name, shorty);
}

const char *get_error()
{
  return impl_->get_error();
}

}
