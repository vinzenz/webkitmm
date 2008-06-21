// -*- c++ -*-
#ifndef _LIBGDAMM_INIT_H
#define _LIBGDAMM_INIT_H
/* $Id: init.h 497 2003-10-12 09:50:16Z murrayc $ */

/* init.h
 *
 * Copyright 2001      Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm.h>


namespace Gnome
{

namespace Gda
{

void init(const Glib::ustring& app_id, const Glib::ustring& version, int nargs, gchar *args[]);

} //namespace Gda
} //namespace Gnome

#endif //_LIBGDAMM_INIT_H

