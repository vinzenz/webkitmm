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
#include <webkitmm/init.h>
#include <webkitmm/webview.h>
#include <gtkmm.h>

class BrowserWindow : public Gtk::Window
{
public:
    BrowserWindow () :
        m_back_button (Gtk::Stock::GO_BACK)
        , m_fwd_button (Gtk::Stock::GO_FORWARD)
        , m_reload_button (Gtk::Stock::REFRESH)
        , m_stop_button (Gtk::Stock::STOP)
    {
        add (m_layout);
        m_layout.pack_start (m_toolbar, Gtk::PACK_SHRINK);
        m_layout.pack_start (m_web_view);
        m_toolbar.pack_start (m_back_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_fwd_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_reload_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_stop_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_location_entry);
        m_location_entry.signal_activate ().connect (sigc::mem_fun(this,
                                                                   &BrowserWindow::on_location_activated));
        set_title("webkitmm");
    }

    ~BrowserWindow () {}

    void on_location_activated ()
    {
        Glib::ustring uri, scheme;
        uri = m_location_entry.get_text ();
        scheme = Glib::uri_parse_scheme (uri);
        if (scheme.empty ())
            uri = "http://" + uri;
        m_web_view.open (uri);
    }

private:
    WebKit::WebView m_web_view;
    Gtk::Button m_back_button, m_fwd_button, m_reload_button, m_stop_button;
    Gtk::Entry m_location_entry;
    Gtk::HBox m_toolbar;
    Gtk::VBox m_layout;
};

int main (int argc, char** argv) {
    Gtk::Main kit (argc, argv);
    WebKit::init ();
    BrowserWindow w;
    w.set_default_size(600, 400);
    w.show_all();
    Gtk::Main::run(w);
    return 0;
}
