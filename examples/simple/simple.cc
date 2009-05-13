/*******************************************************************************
 *
 *  Copyright (c) 2008 Jonathon Jongsma
 *
 *  This file is part of webkitmm
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>
 *
 *******************************************************************************/
#include <webkitmm.h>
#include <gtkmm.h>

int main (int argc, char** argv)
{
    Gtk::Main kit (argc, argv);
    if (!Glib::thread_supported ())
        Glib::thread_init ();
    WebKit::WebView web_view;
    web_view.open ("http://gnome.org");
    Gtk::Window w;
    w.set_default_size (800, 600);
    w.add (web_view);
    w.show_all ();
    Gtk::Main::run (w);
}

