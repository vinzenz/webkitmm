/* $Id: libgdamm.h 1042 2007-03-09 22:15:06Z arminb $ */
/* libgdamm - a C++ wrapper for libgda
 *
 * Copyright 1999-2001 Free Software Foundation
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

#ifndef LIBGDAMM_H
#define LIBGDAMM_H

//extern "C" {
//#include <gtk/gtk.h>
//}

/* libgdamm version.  */
extern const int libgdamm_major_version;
extern const int libgdamm_minor_version;
extern const int libgdamm_micro_version;

#include <glibmm.h>

#include <libgdamm/init.h>
#include <libgdamm/client.h>
#include <libgdamm/config.h>
#include <libgdamm/connection.h>
#include <libgdamm/datamodel.h>
#include <libgdamm/connectionevent.h>
#include <libgdamm/datamodelarray.h>
#include <libgdamm/datamodelquery.h>
#include <libgdamm/query.h>
#include <libgdamm/queryfieldagg.h>
#include <libgdamm/queryfieldall.h>
#include <libgdamm/queryfieldfield.h>
#include <libgdamm/queryfieldvalue.h>
#include <libgdamm/serveroperation.h>

#endif /* #ifndef LIBGDAMM_H */
