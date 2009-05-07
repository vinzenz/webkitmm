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

dnl We use define() here because we can't use shell variables before AC_INIT, but
dnl we want to use a variable with AC_INIT:
define([WEBKITMM_MAJOR_VERSION],     [0])
define([WEBKITMM_MINOR_VERSION],     [9])
define([WEBKITMM_MICRO_VERSION],     [90])
define([WEBKITMM_EXTRA_VERSION],     [])
define([WEBKITMM_VERSION], WEBKITMM_MAJOR_VERSION.WEBKITMM_MINOR_VERSION.WEBKITMM_MICRO_VERSION[]WEBKITMM_EXTRA_VERSION)
AC_INIT([webkitmm], WEBKITMM_VERSION, [gtkmm-list@gnome.org])
AC_CONFIG_SRCDIR([webkit/webkitmmconfig.h.in])

# +1 : ? : +1  == new interface that does not break old one
# +1 : ? : 0   == new interface that breaks old one
#  ? : ? : 0   == no new interfaces, but breaks apps
#  ? :+1 : ?   == just some internal changes, nothing breaks but might work 
#                 better
# CURRENT : REVISION : AGE
WEBKITMM_SO_VERSION=0:0:0
AC_SUBST(WEBKITMM_SO_VERSION)

dnl Add to the config.h header
AC_DEFINE_UNQUOTED([[WEBKITMM_MAJOR_VERSION]], WEBKITMM_MAJOR_VERSION, [Major version of webkitmm])
AC_DEFINE_UNQUOTED([[WEBKITMM_MINOR_VERSION]], WEBKITMM_MINOR_VERSION, [Minor version of webkitmm])
AC_DEFINE_UNQUOTED([[WEBKITMM_MICRO_VERSION]], WEBKITMM_MICRO_VERSION, [Micro version of webkitmm])
AC_DEFINE_UNQUOTED([[WEBKITMM_EXTRA_VERSION]], WEBKITMM_EXTRA_VERSION, [Extra version of webkitmm])
AC_DEFINE_UNQUOTED([[WEBKITMM_VERSION]], WEBKITMM_VERSION, [version of webkitmm])

AC_CONFIG_AUX_DIR(scripts)

dnl Initialize automake stuff
dnl tar-ustar asks it to use a sensible tar format that can handle long filenames.
AM_INIT_AUTOMAKE([1.9 tar-ustar])

dnl Specify a configuration file (no autoheader)
AM_CONFIG_HEADER(webkit/webkitmmconfig.h)
AM_MAINTAINER_MODE
AL_ACLOCAL_INCLUDE(scripts)


#########################################################################
#  Configure arguments 
#########################################################################

dnl Add an --enable-documentation option:
AC_ARG_ENABLE(documentation,
              AC_HELP_STRING([--enable-documentation=yes|no],
                             [Build the reference documentation (default=yes)]),
              BUILD_REFERENCE=$enableval,
              BUILD_REFERENCE=yes)

AM_CONDITIONAL(BUILD_REFERENCE, test x$BUILD_REFERENCE = xyes)


#########################################################################
#  Environment Checks
#########################################################################
AC_PROG_CC
AC_PROG_CPP
AC_PROG_MAKE_SET
AC_CANONICAL_HOST

dnl Used for enabling the "-no-undefined" flag while generating DLLs
dnl Copied from the official gtk+-2 configure.in
AC_MSG_CHECKING([for some Win32 platform])
case "$host" in
  *-*-mingw*|*-*-cygwin*)
    platform_win32=yes
    ;;
  *)
    platform_win32=no
    ;;
esac
AC_MSG_RESULT([$platform_win32])
AM_CONDITIONAL(PLATFORM_WIN32, test "$platform_win32" = "yes")

AC_MSG_CHECKING([for native Win32])
case "$host" in
  *-*-mingw*)
    os_win32=yes
    ;;
  *)
    os_win32=no
    ;;
esac
AC_MSG_RESULT([$os_win32])
AM_CONDITIONAL(OS_WIN32, test "$os_win32" = "yes")

AM_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL

AL_PROG_GNU_M4(AC_MSG_ERROR([dnl
SUN m4 does not work for building webkitmm. 
Please install GNU m4.]))

AL_PROG_GNU_MAKE(AC_MSG_ERROR([dnl
SUN make does not work for building webkitmm.
Please install GNU make.]))

AL_PROG_PERL(AC_MSG_ERROR([Perl is required to build webkitmm.]))

AC_CHECK_PROGS(PERL, perl5 perl)

#########################################################################
#  Dependancy checks
#########################################################################
PKG_CHECK_MODULES(WEBKITMM,
                  gthread-2.0
                  gtkmm-2.4 >= 2.10
                  webkit-1.0 >= 1.0)
PKG_CHECK_MODULES(BROWSER_DEPS,
                  [glibmm-2.4 >= 2.16],
                  BUILD_BROWSER=yes,
                  BUILD_BROWSER=no)
AM_CONDITIONAL(BUILD_BROWSER, test x$BUILD_BROWSER = xyes)

AC_SUBST(WEBKITMM_CFLAGS)
AC_SUBST(WEBKITMM_LIBS)

GLIBMM_PREFIX=`pkg-config --variable=prefix glibmm-2.4`
GMM_PROCDIR=$GLIBMM_PREFIX/lib/glibmm-2.4/proc
AC_SUBST(GMM_PROCDIR)
GMM_PROC=$GMM_PROCDIR/gmmproc
AC_SUBST(GMM_PROC)

#########################################################################
#  C++ checks
#########################################################################
AC_PROG_CXX
AC_LANG([C++])

# Create a list of input directories for Doxygen.  We have to check wether
# we are building in the source directory, because Doxygen doesn't like
# duplicated directories in the input list.
WEBKITMM_DOXYGEN_INPUT=''
webkitmm_srcdir=`cd "$srcdir" && pwd`
webkitmm_builddir=`pwd`
for sublib in webkit
do
  WEBKITMM_DOXYGEN_INPUT="$WEBKITMM_DOXYGEN_INPUT $webkitmm_builddir/$sublib/$sublib""mm/"
  test "x$webkitmm_builddir" = "x$webkitmm_srcdir" || \
    WEBKITMM_DOXYGEN_INPUT="$WEBKITMM_DOXYGEN_INPUT $webkitmm_srcdir/$sublib/$sublib""mm/"
done
WEBKITMM_DOXYGEN_INPUT="$WEBKITMM_DOXYGEN_INPUT $webkitmm_builddir/webkit/webkitmmconfig.h"
AC_SUBST(WEBKITMM_DOXYGEN_INPUT)

# HACK:  Assign a dummy in order to prevent execution of autoheader by the
# maintainer-mode rules.  That would fail since we aren't using autoheader.
AUTOHEADER=':'

AC_CONFIG_FILES([
  Makefile

  webkit/Makefile
  webkit/webkitmm-1.0.pc
  webkit/src/Makefile
  webkit/webkitmm/Makefile
  webkit/webkitmm/private/Makefile
  
  tools/Makefile
    tools/extra_defs_gen/Makefile
    tools/m4/Makefile

  scripts/Makefile

  docs/Makefile
  docs/reference/Makefile
    docs/reference/Doxyfile

  examples/Makefile
    examples/simple/Makefile
    examples/browser/Makefile
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

 OPTIONAL FEATURES:
    Build Example Browser           : ${BUILD_BROWSER}
    Build Reference Documentation   : ${BUILD_REFERENCE}
EOT
