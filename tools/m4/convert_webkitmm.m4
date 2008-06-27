_CONVERSION(`WebKitWebView*',`WebView&',`*Glib::wrap($3)')
_CONVERSION(`WebView&',`WebKitWebView*',`($3).gobj()')
_CONVERSION(`WebKitWebFrame*',`Glib::RefPtr<WebFrame>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<WebFrame>',`WebKitWebFrame*',`($3)->gobj()')
_CONVERSION(`Glib::RefPtr<NetworkRequest>',`WebKitNetworkRequest*',`($3)->gobj()')

_CONVERSION(`const Glib::RefPtr<WebSettings>&',`WebKitWebSettings*',`($3)->gobj()')
_CONVERSION(`WebKitWebSettings*',`Glib::RefPtr<WebSettings>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<WebHistoryItem>&',`WebKitWebHistoryItem*',`($3)->gobj()')
_CONVERSION(`WebKitWebHistoryItem*',`Glib::RefPtr<WebHistoryItem>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<WebBackForwardList>&',`WebKitWebBackForwardList*',`($3)->gobj()')
_CONVERSION(`WebKitWebBackForwardList*',`Glib::RefPtr<WebBackForwardList>',`Glib::wrap($3)')

#FIXME: copied from gtkmm, but added GTK:: namespace -- is there a better way?
#TargetList
_CONVERSION(`const Glib::RefPtr<Gtk::TargetList>&',`GtkTargetList*',__CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`Glib::RefPtr<Gtk::TargetList>&',`GtkTargetList*',__CONVERT_REFPTR_TO_P($3))
_CONVERSION(`GtkTargetList*',`Glib::RefPtr<Gtk::TargetList>',`Glib::wrap($3)')
_CONVERSION(`GtkTargetList*',`Glib::RefPtr<const Gtk::TargetList>',`Glib::wrap($3)')


# Enums
_CONV_ENUM(WebKit,NavigationResponse)

# Lists


# For signals:
