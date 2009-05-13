/* generate_defs_webkit.h
 *
 * Copyright (C) 2008 Jonathon Jongsma
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
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

#include "glibmm_generate_extra_defs/generate_extra_defs.h"
#include <webkit/webkit.h>

int main (int argc, char *argv[])
{
    g_type_init();
    g_thread_init(NULL);

    std::cout
        << get_defs(WEBKIT_TYPE_DOWNLOAD)
        << get_defs(WEBKIT_TYPE_NETWORK_REQUEST)
        << get_defs(WEBKIT_TYPE_SOUP_AUTH_DIALOG)
        << get_defs(WEBKIT_TYPE_WEB_BACK_FORWARD_LIST)
        << get_defs(WEBKIT_TYPE_WEB_FRAME)
        << get_defs(WEBKIT_TYPE_WEB_HISTORY_ITEM)
        << get_defs(WEBKIT_TYPE_WEB_INSPECTOR)
        << get_defs(WEBKIT_TYPE_WEB_NAVIGATION_ACTION)
        << get_defs(WEBKIT_TYPE_WEB_POLICY_DECISION)
        << get_defs(WEBKIT_TYPE_WEB_SETTINGS)
        << get_defs(WEBKIT_TYPE_WEB_WINDOW_FEATURES)
        << get_defs(WEBKIT_TYPE_WEB_VIEW)
        ;
    return 0;
}
