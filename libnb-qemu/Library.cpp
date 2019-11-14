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

#include "Library.h"
#include "Trampoline.h"

Library::Library(const std::string& name, uint32_t address)
     : name_(name),
       address_(address)
{
}

Library::~Library()
{
}

void *Library::get_handle() const
{
  return reinterpret_cast<void *>(address_);
}

void Library::add_trampoline(const std::shared_ptr<Trampoline>& tramp)
{
  trampolines_[tramp->get_name()] = tramp;
}

std::shared_ptr<Trampoline> Library::get_trampoline(const std::string& name) const
{
  std::map<std::string, std::shared_ptr<Trampoline>>::const_iterator it = trampolines_.find(name);
  if (it != trampolines_.end())
    return it->second;
  return nullptr;
}
