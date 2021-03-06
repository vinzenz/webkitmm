/* init.cc
 *
 * Copyright 2008 Jonathon Jongsma
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

#include <glibmm/init.h>
#include <glibmm/thread.h>
#include <webkitmm/wrap_init.h>


namespace WebKit
{

void init()
{
  Glib::init(); //Sets up the g type system and the Glib::wrap() table.
  if(!Glib::thread_supported()) Glib::thread_init();
  wrap_init(); //Tells the Glib::wrap() table about the libgnomecanvasmm classes.
}


} //namespace WebKit
