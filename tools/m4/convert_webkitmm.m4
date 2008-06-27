_CONVERSION(`WebKitWebView*',`WebView&',`*Glib::wrap($3)')
_CONVERSION(`WebView&',`WebKitWebView*',`($3).gobj()')
_CONVERSION(`WebKitWebFrame*',`Glib::RefPtr<WebFrame>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<WebFrame>',`WebKitWebFrame*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<WebFrame>&',`WebKitWebFrame*',__CONVERT_REFPTR_TO_P)

_CONVERSION(`Glib::RefPtr<NetworkRequest>',`WebKitNetworkRequest*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<NetworkRequest>&',`WebKitNetworkRequest*',__CONVERT_REFPTR_TO_P)

_CONVERSION(`const Glib::RefPtr<WebSettings>&',`WebKitWebSettings*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`WebKitWebSettings*',`Glib::RefPtr<WebSettings>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<WebHistoryItem>&',`WebKitWebHistoryItem*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`WebKitWebHistoryItem*',`Glib::RefPtr<WebHistoryItem>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<WebBackForwardList>&',`WebKitWebBackForwardList*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`WebKitWebBackForwardList*',`Glib::RefPtr<WebBackForwardList>',`Glib::wrap($3)')

#FIXME: copied from gtkmm, but added GTK:: namespace -- Move to gtkmm eventually
#TargetList
_CONVERSION(`const Glib::RefPtr<Gtk::TargetList>&',`GtkTargetList*',__CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`Glib::RefPtr<Gtk::TargetList>&',`GtkTargetList*',__CONVERT_REFPTR_TO_P($3))
_CONVERSION(`GtkTargetList*',`Glib::RefPtr<Gtk::TargetList>',`Glib::wrap($3)')
_CONVERSION(`GtkTargetList*',`Glib::RefPtr<const Gtk::TargetList>',`Glib::wrap($3)')


# Enums
_CONV_ENUM(WebKit,NavigationResponse)

# Lists


# For signals:
