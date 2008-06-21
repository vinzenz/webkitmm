// -*- c++ -*-
#ifndef _LIBGDAMM_VALUE_H
#define _LIBGDAMM_VALUE_H


/* $Id: value.h 1100 2007-09-28 16:02:13Z murrayc $ */
// -*- C++ -*- //

/* value.h
 *
 * Copyright 2003 libgdamm Development Team
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

#include <glibmm.h>
#include <glibmm/value.h>
#include <libgda/gda-value.h> //TODO: Patch libgda to use the struct _ technique.


namespace Gnome
{

namespace Gda
{

typedef GdaGeometricPoint GeometricPoint;
typedef GdaTime Time;
typedef GdaTimestamp Timestamp;

/** 
 *
 * Use value_type() to identify the value type at runtime.
 */
class Value : public Glib::ValueBase
{
public:
  Value();

  explicit Value(const GValue* castitem);

  Value(const Value& src);
  Value& operator=(const Value& src);

  ~Value();
  

//We can't have this constructor because gint64 and int are the same on 64-bit systems:
//explicit Value(gint64 val);
  static Value create_as_int64(gint64 val);

//We can't have this constructor because guint64 and unsigned int are the same on 64-bit systems:
//explicit Value(gint64 val);
// explicit Value(guint64 val);
   static Value create_as_uint64(guint64 val);
  
  explicit Value(const guchar* val, long size); 

  explicit Value(const GdaBlob* val);

  explicit Value(bool val);
  
  explicit Value(const Glib::Date& val);
  
  explicit Value(double val);
  
  explicit Value(const GeometricPoint& val);
  
  explicit Value(int val);
  
  explicit Value(const GdaValueList* val);
  
  explicit Value(const GdaNumeric* val);
  
  explicit Value(float val);
  
  explicit Value(gshort val);
  
  explicit Value(gushort val);

  explicit Value(gulong val);
  
  explicit Value(const Glib::ustring& val);
  

  //If this constructor does not exists, then Value("something") uses Value(bool) instead of Value(ustring).
  explicit Value(const char* val);

  explicit Value(const Time& val);
  
  explicit Value(const Timestamp& val);
  
  
  //This causes ambiguity with another constructor on 64-bit systems:
  //explicit Value(time_t val);
  
  static Value create_as_time_t(time_t val);

  explicit Value(gchar val);
  
  explicit Value(guchar val);
  
  explicit Value(guint val);
  
  explicit Value(const Glib::ustring& as_string, GType type);
  
  //TODO: explicit Value(const xmlNodePtr node);
  //__IGNORE(gda_value_new_from_xml)

  bool operator==(const Value& src) const;
  bool operator!=(const Value& src) const;

  
  GType get_value_type() const;
  
  bool is_null() const;
  
  bool is_number() const;

  
  gint64 get_int64() const;
  
  // We can't have this as a regular set() overload because it has the same
  // type as GType on 64bit systems.
  void set_int64(gint64 val);
  
  guint64 get_uint64() const;
  
  // We can't have this as a regular set() overload because it has the same
  // type as GType on 64bit systems.
  void set_uint64(guint64 val);

  //TODO: The const here is quite meaningless:
  
  const guchar* get_binary(long& size) const;
  
  void set(const guchar* val, long size);

  //TODO: The const here is quite meaningless:
  
  const GdaBlob* get_blob() const;
  
  void set(const GdaBlob* val);
  
  bool get_boolean() const;
  
  void set(bool val);
  
  Glib::Date get_date() const;
  
  void set(const Glib::Date& val);
  
  double get_double() const;
  
  void set(double val);
  
  GeometricPoint get_geometric_point() const;
  
  void set(const GeometricPoint& val);
  
  Glib::RefPtr<const Glib::Object> get_gobject();
  
  void set(const Glib::RefPtr<Glib::Object>& val);
  
  int get_int() const;
  
  void set(int val);
  
  const GdaValueList* get_list();
  
  void set(const GdaValueList *val);
  
  const GdaNumeric* get_numeric() const;
  
  void set(const GdaNumeric *val);
  
  float get_float() const;
  
  void set(float val);
  
  gshort get_short() const;
  
  void set(gshort val);
  
  gushort get_ushort() const;
  
  void set(gushort val);

  gulong get_ulong() const;
  
  void set(gulong val);
  
  Glib::ustring get_string() const;
  
  void set(const Glib::ustring& val);

  //If this method does not exists, then set("something") uses set(bool) instead of set(ustring).
  void set(const char* val);
  
  Time get_time() const;
  
  void set(const Time& val);
  
  Timestamp get_timestamp() const;
  
  void set(const Timestamp& val);
  
  void set(gchar val);
  
  void set(guchar val);
  
  guint get_uint() const;
  
  void set(guint val);
  
  GType get_g_type() const;
  
  void set_g_type(GType val);
  
  //Use the copy constructor instead: _WRAP_METHOD(bool set_from_value(const Value& from), gda_value_set_from_value)
  

  //TODO: Wrap this as some stream operator thing?
  
  Glib::ustring to_string() const;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
struct ValueTraits
{
  typedef Value CppType;
  typedef const GValue* CType;
  typedef GValue* CTypeNonConst;

  /* TODO: Should to_c_type make a copy of the actualy GValue? */
  static CType to_c_type(const CppType& obj) { return obj.gobj(); }
  static CType to_c_type(const CType& obj) { return obj; }
  static CppType to_cpp_type(const CType& obj) { return CppType(obj); }
  static void release_c_type(const CType& obj) {}
};
#endif

typedef Glib::ListHandle<Value, ValueTraits> ValueList;
typedef Glib::SListHandle<Value, ValueTraits> ValueSList;

GType value_get_type_null();
GType value_get_type_binary();
GType value_get_type_blob();
GType value_get_type_geometric_point();
GType value_get_type_list();
GType value_get_type_numeric();
GType value_get_type_short();
GType value_get_type_ushort();
GType value_get_type_time();
GType value_get_type_timestamp();

//These can't work because the static instances would be instantiated before the GType system has been initialized.
/*
extern const GType VALUE_TYPE_NULL;
extern const GType VALUE_TYPE_BINARY;
extern const GType VALUE_TYPE_BLOB;
extern const GType VALUE_TYPE_GEOMETRIC_POINT;
extern const GType VALUE_TYPE_LIST;
extern const GType VALUE_TYPE_NUMERIC;
extern const GType VALUE_TYPE_SHORT;
extern const GType VALUE_TYPE_USHORT;
extern const GType VALUE_TYPE_TIME;
extern const GType VALUE_TYPE_TIMESTAMP;
*/

typedef GdaGeometricPoint GeometricPoint;

/*  TODO:
typedef struct {
	gchar *currency;
	double amount;
} GdaMoney;

typedef struct {
	gchar *number;
	long precision;
	long width;
} GdaNumeric;
*/


#if 0
int value_compare(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
int value_compare_ext(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
bool value_equal(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
#endif


/*
xmlNodePtr                        gda_value_to_xml(const Glib::ValueBase& value);

gchar                            *gda_binary_to_string(const GdaBinary& bin, guint maxlen);
bool                          gda_string_to_binary(const gchar *str, GdaBinary *bin);


GType                             gda_numeric_get_type (void) G_GNUC_CONST;
gpointer                          gda_numeric_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_numeric_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_time_get_type(void) G_GNUC_CONST;
gpointer                          gda_time_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_time_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_timestamp_get_type(void) G_GNUC_CONST;
gpointer                          gda_timestamp_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_timestamp_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_geometricpoint_get_type(void) G_GNUC_CONST;
gpointer                          gda_geometricpoint_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_geometricpoint_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_binary_get_type(void) G_GNUC_CONST;
gpointer                          gda_binary_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_binary_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_value_list_get_type (void) G_GNUC_CONST;
GType                             gda_short_get_type (void) G_GNUC_CONST;
GType                             gda_ushort_get_type (void) G_GNUC_CONST;

#define                           gda_value_new_null() (g_new0 (GValue, 1))
*/




} //namespace Gda
} //namespaec Gnome


#endif /* _LIBGDAMM_VALUE_H */

