_CONVERSION(`WebKitWebView*',`WebView&',`*Glib::wrap($3)')
_CONVERSION(`WebView&',`WebKitWebView*',`($3).gobj()')
_CONVERSION(`WebKitWebFrame*',`Glib::RefPtr<WebFrame>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<WebHistoryItem>&',`WebKitWebHistoryItem*',`($3)->gobj()')
_CONVERSION(`WebKitWebHistoryItem*',`Glib::RefPtr<WebHistoryItem>',`Glib::wrap($3)')

# Enums
_CONV_ENUM(WebKit,NavigationResponse)

# Lists


# For signals:
