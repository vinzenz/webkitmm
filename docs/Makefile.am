## This file is part of webkitmm.

include $(top_srcdir)/webkit/src/filelist.am
include $(top_srcdir)/webkit/webkitmm/filelist.am

webkitmm_files_h = $(files_built_h) $(filter-out wrap_init.h,$(files_extra_h))

book_name = $(WEBKITMM_MODULE_NAME)
doc_input = $(addprefix $(top_srcdir)/webkit/webkitmm/,$(webkitmm_files_h))

# Override the web location to use the old-style path with redundant
# directory components.
htmlrefpub = http://www.gtkmm.org/docs/$(book_name)/docs/reference/html

include $(top_srcdir)/build/doc-reference.am
