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

#ifndef TRAMPOLINE_H_
#define TRAMPOLINE_H_

#include <string>
#include <ffi.h>

class Trampoline
{
public:
  Trampoline(const std::string& name, uint32_t address, const std::string& signature);
  virtual ~Trampoline();

  void *get_handle() const;
  const std::string& get_name() const { return name_; }
  uint32_t get_address() const { return address_; }
  const std::string& get_signature() const { return signature_; }

protected:
  virtual void call(void *ret, void **args);
  virtual void *get_call_argument(int index, void *arg);

private:
  static void call_trampoline(ffi_cif *cif, void *ret, void **args, void *self);

private:
  std::string name_;
  uint32_t address_;
  std::string signature_;
  void *host_address_;
  ffi_closure *closure_;
  ffi_cif cif_;
  ffi_type *rtype_;
  ffi_type **argtypes_;
  int nargs_;
  int nstackargs_;
  int stacksize_;
  int *stackoffsets_;
};

class JNITrampoline : public Trampoline
{
public:
  JNITrampoline(const std::string& name, uint32_t address, const std::string& shorty);

protected:
  void *get_call_argument(int index, void *arg) override;

private:
  std::string shorty_;
};

class JNILoadTrampoline : public Trampoline
{
public:
  JNILoadTrampoline(const std::string& name, uint32_t address);

protected:
  void *get_call_argument(int index, void *arg) override;
};

#endif
