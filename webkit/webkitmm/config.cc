/* $Id: config.cc 1078 2007-06-10 17:47:20Z murrayc $ */
// -*- C++ -*- // this is for the .hg, I realize gensig puts one in

/* config.cc
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

#include <libgdamm/config.h>
#include <libgda/gda-config.h>

namespace Gnome
{

namespace Gda
{

namespace Config
{

void DataSourceInfoTraits::release_c_type(CType ptr)
{
  gda_data_source_info_free(const_cast<CTypeNonConst>(ptr));
}

Glib::ustring get_value_string(const Glib::ustring& path)
{
  return Glib::convert_return_gchar_ptr_to_ustring (gda_config_get_string(path.c_str()));
}

int get_value_int(const Glib::ustring& path)
{
  return gda_config_get_int(path.c_str());
}

double get_value_float(const Glib::ustring& path)
{
  return gda_config_get_float(path.c_str());
}

bool get_value_bool(const Glib::ustring& path)
{
  return gda_config_get_boolean(path.c_str());
}

void set_value(const Glib::ustring& path, const Glib::ustring& new_value)
{
  gda_config_set_string(path.c_str(), new_value.c_str());
}

void set_value(const Glib::ustring& path, int new_value)
{
  gda_config_set_int(path.c_str(), new_value);
}

void set_value(const Glib::ustring& path, double new_value)
{
  gda_config_set_float(path.c_str(), new_value);
}

void set_value(const Glib::ustring& path, bool new_value)
{
  gda_config_set_boolean(path.c_str(), new_value);
}


void remove_section(const Glib::ustring& path)
{
  gda_config_remove_section(path.c_str());
}

void remove_key(const Glib::ustring& path)
{
  gda_config_remove_key(path.c_str());
}

bool has_section(const Glib::ustring& path)
{
  return gda_config_has_section(path.c_str());
}

bool has_key(const Glib::ustring& path)
{
  return gda_config_has_key(path.c_str());
}

Glib::ListHandle<Glib::ustring> list_sections(const Glib::ustring& path)
{
  return Glib::ListHandle<Glib::ustring>(gda_config_list_sections(path.c_str()), Glib::OWNERSHIP_DEEP);
}

Glib::ListHandle<Glib::ustring> list_keys(const Glib::ustring& path)
{
   return Glib::ListHandle<Glib::ustring>(gda_config_list_keys(path.c_str()), Glib::OWNERSHIP_DEEP);
}

Glib::ustring get_type(const Glib::ustring& path)
{
  return gda_config_get_type(path.c_str());
}

guint add_listener(const Glib::ustring& path, const SlotListener& slot)
{
  //TODO: Add SignalProxy
  return 0;
}
void remove_listener(guint id)
{
  gda_config_remove_listener(id);
}

ListHandle_ProviderInfo get_providers()
{
  return ListHandle_ProviderInfo( gda_config_get_provider_list(), Glib::OWNERSHIP_NONE);
}

ProviderInfo get_provider_by_name(const Glib::ustring& name)
{
  return Glib::wrap( gda_config_get_provider_by_name(name.c_str()), true /* take_copy */ );
}

ListHandle_DataSourceInfo get_data_sources()
{
  return ListHandle_DataSourceInfo( gda_config_get_data_source_list(), Glib::OWNERSHIP_DEEP); //Deep because we must delete both the list and the elements.
}

DataSourceInfo find_data_source(const Glib::ustring& name)
{
  //We own the result:
  return Glib::wrap( gda_config_find_data_source(name.c_str()) );
}

Glib::RefPtr<DataModel> get_data_source_model()
{
  // This doesn't need an extra reference, 
  // because it is a new object.
  return Glib::wrap( gda_config_get_data_source_model() );
}

void save_data_source(const Glib::ustring& name, const Glib::ustring& provider,
                      const Glib::ustring& cnc_string, const Glib::ustring& description,
                      const Glib::ustring& username, const Glib::ustring& password, bool is_global)
{
  gda_config_save_data_source(name.c_str(), provider.c_str(), cnc_string.c_str(), description.c_str(), username.c_str(), password.c_str(), is_global);
}


void save_data_source(const DataSourceInfo& dsn_info)
{
  gda_config_save_data_source_info(const_cast<GdaDataSourceInfo*>(dsn_info.gobj())); //TODO: Patch libgda to use const.
}

void remove_data_source(const Glib::ustring& name)
{
  gda_config_remove_data_source(name.c_str());
}






} // namespace Config

} // namespace Gda
} // namespace Gnome

