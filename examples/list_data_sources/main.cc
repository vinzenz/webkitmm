/* main.cc
 *
 * Copyright (C) 2008 Jonathon Jongsma
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */


#include <libgdamm.h>
#include <iostream>


int main (int argc, char** argv)
{
  try
  {
    //Initialize libgdamm:
    Gnome::Gda::init("libgdamm example", "0.1", argc, argv);

    Glib::RefPtr<Gnome::Gda::Client> gda_client = Gnome::Gda::Client::create();
    if(gda_client)
    {
      //Get the list of providers:
      typedef std::list<Gnome::Gda::ProviderInfo> type_list_of_provider_info;
      type_list_of_provider_info providers = Gnome::Gda::Config::get_providers();

      std::cout << "Number of providers = " << providers.size() << std::endl << std::endl;

      //Print the information about each Provider:
      for(type_list_of_provider_info::const_iterator iter = providers.begin(); iter != providers.end(); ++iter)
      { 
        const Gnome::Gda::ProviderInfo& info = *iter; //TODO: If we get a copy instead of a const& then it segfaults on the 2nd one.

        std::cout << "Provider: ID = " << info.get_id() << std::endl <<
                   "  location = " << info.get_location() << std::endl <<
                   "  description = " << info.get_description() << std::endl;

        //The params:
        std::cout << "  GDA Params: ";

        Glib::RefPtr<const Gnome::Gda::ParameterList> params = info.get_gda_params();
        /* TODO:
        for(type_list_of_strings::iterator iter = params.begin(); iter != params.end(); ++iter)
        {
          std::cout << *iter << ", ";
        }

        std::cout << std::endl << std::endl;
        */
      }

    
      //Get the list of data sources:
      typedef std::list<Gnome::Gda::DataSourceInfo> type_list_of_data_sources;
      type_list_of_data_sources data_sources = Gnome::Gda::Config::get_data_sources();

      std::cout << "Number of data sources = " << data_sources.size() << std::endl << std::endl;

      //Print the information about each data source:
      for(type_list_of_data_sources::const_iterator iter = data_sources.begin(); iter != data_sources.end(); ++iter)
      {
        const Gnome::Gda::DataSourceInfo& info = *iter;

        std::cout << "Data source: name = " << info.get_name() << std::endl <<
                    "  provider = " << info.get_provider() << std::endl <<
                    "  connection string = " << info.get_cnc_string() << std::endl <<
                    "  description = " << info.get_description() << std::endl <<
                    "  username = " << info.get_username() << std::endl << std::endl;

      }
    }
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "Glib::Error exception caught: " << ex.what() << std::endl;
  }
  catch(const std::exception& ex)
  {
    std::cerr << "Exception caught: " << ex.what() << std::endl;
  }

  return 0;
}


