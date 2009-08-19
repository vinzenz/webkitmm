# configure.ac
#
# Copyright 2008 Jonathon Jongsma
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.
#
# You should have received a copy of the GNU Library General Public
# License along with this library; if not, write to the Free
# Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

AC_INIT([webkitmm], [1.1.6], [gtkmm-list@gnome.org])
AC_PREREQ([2.59])

AC_CONFIG_SRCDIR([webkit/webkitmmconfig.h.in])
AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_AUX_DIR(build)
AC_CONFIG_HEADERS([config.h webkit/webkitmmconfig.h])

MM_PREREQ([0.4])
MM_INIT_MODULE([webkitmm-1.0])

# +1 : ? : +1  == new interface that does not break old one
# +1 : ? : 0   == new interface that breaks old one
#  ? : ? : 0   == no new interfaces, but breaks apps
#  ? :+1 : ?   == just some internal changes, nothing breaks but might work 
#                 better
# CURRENT : REVISION : AGE
WEBKITMM_SO_VERSION=0:0:0
AC_SUBST(WEBKITMM_SO_VERSION)

dnl Initialize automake stuff
dnl tar-ustar asks it to use a sensible tar format that can handle long filenames.
AM_INIT_AUTOMAKE([1.9 tar-pax -Wno-portability])

AM_MAINTAINER_MODE
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

#########################################################################
#  Environment Checks
#########################################################################
AC_PROG_CXX
AC_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

#########################################################################
#  Dependancy checks
#########################################################################
PKG_CHECK_MODULES(WEBKITMM,
                  gthread-2.0
                  gtkmm-2.4 >= 2.10
                  webkit-1.0 >= 1.1.7)
PKG_CHECK_MODULES(BROWSER_DEPS,
                  [glibmm-2.4 >= 2.16],
                  BUILD_BROWSER=yes,
                  BUILD_BROWSER=no)
AM_CONDITIONAL(BUILD_BROWSER, test x$BUILD_BROWSER = xyes)

AC_LANG([C++])

MM_ARG_ENABLE_DOCUMENTATION
MM_ARG_WITH_TAGFILE_DOC([libstdc++.tag], [mm-common-libstdc++])
MM_ARG_WITH_TAGFILE_DOC([libsigc++-2.0.tag], [sigc++-2.0])
MM_ARG_WITH_TAGFILE_DOC([glibmm-2.4.tag], [glibmm-2.4])
MM_ARG_WITH_TAGFILE_DOC([ggtkmm-2.4.tag], [gtkmm-2.4])

MM_PKG_CONFIG_SUBST([GMMPROC_DIR], [--variable=gmmprocdir glibmm-2.4])

MM_ARG_ENABLE_WARNINGS([WEBKITMM_WFLAGS], [-Wall], [-Wall -Wextra])

AC_CONFIG_FILES([
  webkit/$WEBKITMM_MODULE_NAME.pc:webkit/webkitmm.pc.in
  webkit/$WEBKITMM_MODULE_NAME-uninstalled.pc:webkit/webkitmm-uninstalled.pc.in
  Makefile

  webkit/src/Makefile
  webkit/webkitmm/Makefile

  tools/Makefile

  docs/Makefile
    docs/reference/Doxyfile

  examples/Makefile
])

AC_OUTPUT()

cat <<EOT

=================================================================
webkitmm WEBKITMM_VERSION
=================================================================

    Prefix                          : ${prefix}
    CFLAGS                          : ${CFLAGS}
    CXXFLAGS                        : ${CXXFLAGS}
    WEBKITMM_LIBS                   : ${WEBKITMM_LIBS}
    WEBKITMM_CFLAGS                 : ${WEBKITMM_CFLAGS}
    Warning flags                   : ${WEBKITMM_WFLAGS}

 OPTIONAL FEATURES:
    Build Example Browser           : ${BUILD_BROWSER}
    Build Reference Documentation   : ${ENABLE_DOCUMENTATION}
EOT
