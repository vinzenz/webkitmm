/* main.cc
 *
 * Copyright (C) 2003 gnome-vfsmm Development Team
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
  //Initialize libgdamm:
  Gnome::Gda::init("libgdamm example", "0.1", argc, argv);

#ifndef GLIBMM_EXCEPTIONS_ENABLED
  std::auto_ptr<Glib::Error> error;
#endif // !GLIBMM_EXCEPTIONS_ENABLED

  Glib::RefPtr<Gnome::Gda::Client> gda_client = Gnome::Gda::Client::create();
  if(gda_client)
  {
    //Get a stored data source:
    //(Note that you might prefer to just use Gnome::Gda::Client::open_connection_from_string() instead.)
    const Glib::ustring data_source_name = "datasource_libgdamm_example_simple";
    Gnome::Gda::DataSourceInfo data_source = Gnome::Gda::Config::find_data_source(data_source_name);
    if(!data_source)
    {
      std::cout << "Creating the DataSource, because it does not exist yet." << std::endl;
      //Create it if it does not exist already:
      data_source = Gnome::Gda::DataSourceInfo();
      data_source.set_name(data_source_name);
      data_source.set_username("murrayc");
      data_source.set_password("murraycpw");      
      data_source.set_description("Data Source for libgdamm simple example.");
      data_source.set_provider("PostgreSQL");
      data_source.set_cnc_string("DB_NAME=glom_musiccollection21");
      
      Gnome::Gda::Config::save_data_source(data_source);
    }

    std::cout << " Data source = " << data_source.get_name() << ", User = " << data_source.get_username() << std::endl;

    Glib::RefPtr<Gnome::Gda::Connection> gda_connection;
#ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
      gda_connection = gda_client->open_connection(data_source.get_name(), data_source.get_username(), data_source.get_password() );
    }
    catch(const Glib::Exception& ex)
    {
      std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
#else
    gda_connection = gda_client->open_connection(data_source.get_name(), data_source.get_username(), data_source.get_password(), Gnome::Gda::ConnectionOptions(0), error);
    if(error.get())
    {
      std::cerr << "Exception caught: " << error->what() << std::endl;
    }
#endif // GLIBMM_EXCEPTIONS_ENABLED
    
    if(!gda_connection)
      std::cerr << "Error: Could not open connection to " << data_source.get_name();
    else
    {
      //Open database:
      //gda_connection->change_database("murrayc");

      //Get data from a table:
      Gnome::Gda::Command command("SELECT * FROM artists");

      Glib::RefPtr<Gnome::Gda::DataModel> data_model;
#ifdef GLIBMM_EXCEPTIONS_ENABLED
      try
      {
        data_model = gda_connection->execute_select_command(command);
      }
      catch(const Glib::Exception& ex)
      {
       std::cerr << "Exception caught: " << ex.what() << std::endl;
      }
#else
      data_model = gda_connection->execute_select_command(command, error);
      if(error.get())
      {
        std::cerr << "Exception caught: " << error->what() << std::endl;
      }
#endif //GLIBMM_EXCEPTIONS_ENABLED

      if(!data_model)
      {
        std::cout << "command execution failed." << std::endl;
      }
      else if(data_model) 
      {
        int columns =  data_model->get_n_columns();
        std::cout << "    Number of columns: " << columns << std::endl;

        for(int i = 0; i < columns; ++i)
        {
          std::cout << "      column " << i << ": " <<  data_model->get_column_title(i);

          //Find out whether it's the primary key:
          const Glib::RefPtr<Gnome::Gda::Column> field = data_model->describe_column(i);
          bool is_primary_key = field->get_primary_key();
          if(is_primary_key)
            std:: cout << "  (primary key)";

          std::cout << std::endl;
        }

        const int rows = data_model->get_n_rows();
        std::cout << "    Number of rows: " << rows << std::endl;

        for(int i = 0; i < rows; ++i)
        {
          std::cout << "      row " << i << ": ";

          for(int col = 0; col < columns; ++col)
          {
            Gnome::Gda::Value value_name = data_model->get_value_at(col, i);
            std::cout << value_name.to_string() << ", ";
          }

          std::cout << std::endl;   
        }
      }
    }
  } 

  
  return 0;
}


