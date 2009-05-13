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
        m_layout.pack_start (m_scroller);
        m_scroller.add (m_web_view);
        m_scroller.set_policy (Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
        m_toolbar.set_spacing (6);
        m_toolbar.set_border_width (6);
        m_toolbar.pack_start (m_back_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_fwd_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_reload_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_stop_button, Gtk::PACK_SHRINK);
        m_toolbar.pack_start (m_location_entry);
        set_title ("webkitmm");

        m_location_entry.signal_activate ().connect
            (sigc::mem_fun (this, &BrowserWindow::on_location_activated));
        m_web_view.signal_title_changed ().connect
            (sigc::mem_fun (this, &BrowserWindow::on_title_changed));
        m_web_view.signal_load_committed ().connect
            (sigc::mem_fun (this, &BrowserWindow::update_uri));
        m_web_view.signal_load_finished ().connect
            (sigc::mem_fun (this, &BrowserWindow::update_uri));
        m_back_button.signal_clicked ().connect
            (sigc::mem_fun (m_web_view, &WebKit::WebView::go_back));
        m_fwd_button.signal_clicked ().connect
            (sigc::mem_fun (m_web_view, &WebKit::WebView::go_forward));
        m_reload_button.signal_clicked ().connect
            (sigc::mem_fun (m_web_view, &WebKit::WebView::reload));
        m_stop_button.signal_clicked ().connect
            (sigc::mem_fun (m_web_view, &WebKit::WebView::stop_loading));
    }

    ~BrowserWindow () {}

    void open (Glib::ustring uri)
    {
        switch (uri[0])
        {
            // assume it's a local file if it's of the form ./foo or /foo
            case '.':
                uri.erase (uri.begin ());
                uri = Glib::get_current_dir () + uri;
                // fall through
            case '/':
                uri = "file://" + uri;
                break;

            // else assume it's a web address and try loading via http
            default:
                // prepend 'http://' if user didn't enter a uri scheme
                Glib::ustring scheme = Glib::uri_parse_scheme (uri);
                if (scheme.empty ())
                    uri = "http://" + uri;
        }

        m_web_view.open (uri);
    }

private:
    void on_location_activated ()
    {
        Glib::ustring uri;
        uri = m_location_entry.get_text ();
        open (uri);
    }

    void on_title_changed (const Glib::RefPtr<WebKit::WebFrame>& frame, const Glib::ustring& title)
    {
        set_title (title);
    }

    void update_uri (const Glib::RefPtr<WebKit::WebFrame>& frame)
    {
        g_return_if_fail (frame);
        // update the location bar
        m_location_entry.set_text(frame->get_uri());
    }

private:
    WebKit::WebView m_web_view;
    Gtk::Button m_back_button, m_fwd_button, m_reload_button, m_stop_button;
    Gtk::Entry m_location_entry;
    Gtk::HBox m_toolbar;
    Gtk::VBox m_layout;
    Gtk::ScrolledWindow m_scroller;
};

int main (int argc, char** argv) {
    Gtk::Main kit (argc, argv);
    if (!Glib::thread_supported ())
        Glib::thread_init ();
    WebKit::init ();
    BrowserWindow w;
    if (argc > 1)
        w.open (argv[1]);
    w.set_default_size(600, 400);
    w.show_all();
    Gtk::Main::run(w);
    return 0;
}
