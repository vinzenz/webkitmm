/* $Id: generate_defs_gda.cc 1017 2007-02-14 23:03:00Z arminb $ */

/* generate_defs_gda.h
 *
 * Copyright (C) 2001 The Free Software Foundation
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
#include <libgda/libgda.h>
//#include <libgda/gda-server-recordset-model.h>

int main (int argc, char *argv[])
{
    gda_init("generate_extra_defs", "0.1", argc, argv);

    std::cout << get_defs(GDA_TYPE_CLIENT)
                 << get_defs(GDA_TYPE_COLUMN)
                 << get_defs(GDA_TYPE_COLUMN_INDEX)
                 << get_defs(GDA_TYPE_CONNECTION)
                 << get_defs(GDA_TYPE_CONNECTION_EVENT)
                 << get_defs(GDA_TYPE_DATA_MODEL_ARRAY)
		 << get_defs(GDA_TYPE_DATA_MODEL_ROW)
		 << get_defs(GDA_TYPE_DATA_MODEL_ITER)
//                 << get_defs(GDA_TYPE_DATA_MODEL_INDEX)
                 << get_defs(GDA_TYPE_DATA_MODEL)
		 << get_defs(GDA_TYPE_DATA_PROXY)
                 << get_defs(GDA_TYPE_DICT)
                 << get_defs(GDA_TYPE_DICT_TYPE)
                 << get_defs(GDA_TYPE_DICT_AGGREGATE)
                 << get_defs(GDA_TYPE_DICT_CONSTRAINT)
                 << get_defs(GDA_TYPE_DICT_DATABASE)
                 << get_defs(GDA_TYPE_DICT_FIELD)
//                 << get_defs(GDA_TYPE_DATA_MODEL_COLUMN_ATTRIBUTES)
//                 << get_defs(GDA_TYPE_EXPORT)
                 << get_defs(GDA_TYPE_GRAPH)
                 << get_defs(GDA_TYPE_OBJECT)
                 << get_defs(GDA_TYPE_PARAMETER)
                 << get_defs(GDA_TYPE_PARAMETER_LIST)
//                 << get_defs(GDA_TYPE_RECORDSET)
                 << get_defs(GDA_TYPE_QUERY)
                 << get_defs(GDA_TYPE_QUERY_OBJECT)
                 << get_defs(GDA_TYPE_QUERY_FIELD)
                 << get_defs(GDA_TYPE_QUERY_TARGET)
                 << get_defs(GDA_TYPE_QUERY_CONDITION)
                 << get_defs(GDA_TYPE_QUERY_JOIN)
                 << get_defs(GDA_TYPE_QUERY_FIELD_AGG)
                 << get_defs(GDA_TYPE_QUERY_FIELD_ALL)
                 << get_defs(GDA_TYPE_QUERY_FIELD_FIELD)
                 << get_defs(GDA_TYPE_QUERY_FIELD_FUNC)
                 << get_defs(GDA_TYPE_QUERY_FIELD_VALUE);
//                 << get_defs(GDA_TYPE_SERVER_CONNECTION)
//                 << get_defs(GDA_TYPE_SERVER_PROVIDER)
//                 << get_defs(GDA_TYPE_SERVER_RECORDSET_MODEL)
//                 << get_defs(GDA_TYPE_SERVER_RECORDSET)
//                 << get_defs(GDA_TYPE_SERVER)
    return 0;
}
