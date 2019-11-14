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

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <string>
#include <map>

class Trampoline;

class Library
{
public:
  Library(const std::string& name, uint32_t address);
  ~Library();

  void *get_handle() const;
  const std::string& get_name() const { return name_; }
  uint32_t get_address() const { return address_; }
  void add_trampoline(const std::shared_ptr<Trampoline>& tramp);
  std::shared_ptr<Trampoline> get_trampoline(const std::string& name) const;

private:
  std::string name_;
  uint32_t address_;
  std::map<std::string, std::shared_ptr<Trampoline>> trampolines_;
};

#endif
