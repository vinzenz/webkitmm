/* $Id: config.h 808 2005-10-20 06:54:43Z murrayc $ */
// -*- C++ -*- //

/* config.h
 *
 * Copyright 2003      libgdamm Development Team
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

#ifndef _LIBGDAMM_CONFIG_H
#define _LIBGDAMM_CONFIG_H

#include <libgdamm/providerinfo.h>
#include <libgdamm/datasourceinfo.h>
#include <libgdamm/datamodel.h>
#include <glibmm.h>

namespace Gnome
{

namespace Gda
{

namespace Config
{


Glib::ustring get_value_string(const Glib::ustring& path);
int get_value_int(const Glib::ustring& path);
double get_value_float(const Glib::ustring& path);
bool get_value_boolean(const Glib::ustring& path);
void set_value(const Glib::ustring& path, const Glib::ustring& new_value);
void set_value(const Glib::ustring& path, int new_value);
void set_value(const Glib::ustring& path, double new_value);
void set_value(const Glib::ustring& path, bool new_value);

void remove_section(const Glib::ustring& path);
void remove_key(const Glib::ustring& path);
bool has_section(const Glib::ustring& path);
bool has_key(const Glib::ustring& path);

Glib::ListHandle<Glib::ustring> list_sections(const Glib::ustring& path);
Glib::ListHandle<Glib::ustring> list_keys(const Glib::ustring& path);
Glib::ustring get_type(const Glib::ustring& path);


/// For instance, void on_listen(const Glib::ustring& path);
typedef sigc::slot<void, const Glib::ustring&> SlotListener;

guint add_listener(const Glib::ustring& path, const SlotListener& slot);
void remove_listener(guint id);

struct ProviderInfoTraits
{
  typedef Gnome::Gda::ProviderInfo       CppType;
  typedef const GdaProviderInfo*  CType;
  typedef GdaProviderInfo*        CTypeNonConst;

  static CType   to_c_type      (const CppType& obj) { return obj.gobj(); }
  static CType   to_c_type      (CType ptr) { return ptr; }
  static CppType to_cpp_type    (CType ptr) { return CppType(const_cast<CTypeNonConst>(ptr), true); }
  static void    release_c_type (CType ptr) { gda_provider_info_free(const_cast<CTypeNonConst>(ptr)); }
};

typedef Glib::ListHandle<ProviderInfo, ProviderInfoTraits> ListHandle_ProviderInfo;
ListHandle_ProviderInfo get_providers();

ProviderInfo get_provider_by_name(const Glib::ustring& name);

struct DataSourceInfoTraits
{
  typedef Gnome::Gda::DataSourceInfo       CppType;
  typedef const GdaDataSourceInfo*  CType;
  typedef GdaDataSourceInfo*        CTypeNonConst;

  static CType   to_c_type      (const CppType& obj) { return obj.gobj(); }
  static CType   to_c_type      (CType ptr) { return ptr; }
  static CppType to_cpp_type    (CType ptr) { return CppType(const_cast<CTypeNonConst>(ptr), true); }
  static void    release_c_type (CType ptr);
};


typedef Glib::ListHandle<DataSourceInfo, DataSourceInfoTraits> ListHandle_DataSourceInfo;
ListHandle_DataSourceInfo get_data_sources();

DataSourceInfo find_data_source(const Glib::ustring& name);

Glib::RefPtr<DataModel> get_data_source_model();
void save_data_source(const Glib::ustring& name, const Glib::ustring& provider,
                      const Glib::ustring& cnc_string, const Glib::ustring& description,
                      const Glib::ustring& username, const Glib::ustring& password,
                      bool is_global = false);
void save_data_source(const DataSourceInfo& dsn_info);
void remove_data_source(const Glib::ustring& name);


} // namespace Config

} // namespace Gda
} // namespace Gnome


#endif /* _LIBGDAMM_CONFIG_H */

