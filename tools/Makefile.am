AUTOMAKE_OPTIONS=subdir-objects

include $(srcdir)/m4/filelist.am

dist_noinst_DATA = $(addprefix m4/,$(files_codegen_m4))

noinst_PROGRAMS = extra_defs_gen/generate_extra_defs
extra_defs_gen_generate_extra_defs_SOURCES = extra_defs_gen/generate_defs_webkit.cc
extra_defs_gen_generate_extra_defs_LDADD = $(WEBKITMM_LIBS) -lglibmm_generate_extra_defs-2.4
extra_defs_gen_generate_extra_defs_LDFLAGS = -no-undefined -avoid-version
AM_CXXFLAGS = $(WEBKITMM_CFLAGS)

