#define LOG_TAG "libnb-qemu"

#include <dlfcn.h>
#include <log/log.h>
#include <mutex>
#include "QemuCore.h"
#include "OsBridge.h"

enum {
    HANDLER_EGL,
    HANDLER_GLESV1_CM,
    HANDLER_GLESV3,
    HANDLER_OPENSLES,
    HANDLER_ANDROID,
    HANDLER_MAX,
};

struct HandlerInfo {
    int start;
    int length;
    const char *lib;
    QemuCore::svc_handler_t handler;
};

static std::mutex g_mutex_;
static struct HandlerInfo g_handlers_[HANDLER_MAX] = {
    [HANDLER_EGL] = { 0x0100, 81, "libnb-qemu-EGL.so", nullptr },
    [HANDLER_GLESV1_CM] = { 0x0400, 257, "libnb-qemu-GLESv1_CM.so", nullptr },
    [HANDLER_GLESV3] = { 0x1000, 399, "libnb-qemu-GLESv3.so", nullptr },
    [HANDLER_OPENSLES] = { 0x0600, 53, "libnb-qemu-OpenSLES.so", nullptr },
    [HANDLER_ANDROID] = { 0x0700, 54, "libnb-qemu-android.so", nullptr }
};

static QemuCore::svc_handler_t get_handler_for_svc(int num) {
    for (int i = 0; i < HANDLER_MAX; i++) {
        int offset = num - g_handlers_[i].start;
        if (offset >= 0 && offset < g_handlers_[i].length) {
            if (g_handlers_[i].handler == nullptr) {
                void *lib_handle = dlopen(g_handlers_[i].lib, RTLD_LAZY);
                if (lib_handle) {
                    g_handlers_[i].handler = reinterpret_cast<QemuCore::svc_handler_t>(dlsym(lib_handle, "nb_handle_svc"));
                }
                LOG_ALWAYS_FATAL_IF(g_handlers_[i].handler == nullptr,
                                    "Unable to load SVC handler from %s", g_handlers_[i].lib);
            }
            return g_handlers_[i].handler;
        }
    }
    LOG_ALWAYS_FATAL("Unknow SVC %08x", num);
}

static void handle_svc(void *cpu_env, int num) {
    get_handler_for_svc(num)(cpu_env, num);
}

namespace OsBridge {

bool initialize() {
    QemuCore::register_svc_handler(handle_svc);
    return true;
}

}
