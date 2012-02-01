dnl
dnl configure.ac: Configure template for peek
dnl Process this file with autoconf to produce a configure script.
dnl
dnl Copyright (c) 2007-2009 Mark Sangster <znxster@gmail.com>
dnl Released under GPL3 (see COPYING for details)
dnl

AC_INIT([peek], [0.0.3], [znxster@gmail.com])
AC_PREREQ(2.59)
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MAKE_SET

dnl Check for the various compression tools
dnl Not sure if this is the best way but it works!
AC_PATH_PROG(CPIO_PATH, cpio)
if test "$CPIO_PATH" != ""
then
	AC_DEFINE_UNQUOTED(CPIO, "$CPIO_PATH", [Path to cpio program])
fi
AM_CONDITIONAL(TCPIO, test "$CPIO_PATH" == "")
AC_PATH_PROG(ARJ_PATH, arj)
if test "$ARJ_PATH" != ""
then
    AC_DEFINE_UNQUOTED(ARJ, "$ARJ_PATH", [Path to arj program])
fi
AM_CONDITIONAL(TARJ, test "$ARJ_PATH" == "")
AC_PATH_PROG(UNZIP_PATH, unzip)
if test "$UNZIP_PATH" != ""
then
    AC_DEFINE_UNQUOTED(UNZIP, "$UNZIP_PATH", [Path to unzip program])
fi
AM_CONDITIONAL(TUNZIP, test "$UNZIP_PATH" == "")
AC_PATH_PROG(UNACE_PATH, unace)
if test "$UNACE_PATH" != ""
then
    AC_DEFINE_UNQUOTED(UNACE, "$UNACE_PATH", [Path to unace program])
fi
AM_CONDITIONAL(TUNACE, test "$UNACE_PATH" == "")
AC_PATH_PROG(COMPRESS_PATH, compress)
if test "$COMPRESS_PATH" != ""
then
    AC_DEFINE_UNQUOTED(COMPRESS, "$COMPRESS_PATH", [Path to compress program])
fi
AM_CONDITIONAL(TCOMPRESS, test "$COMPRESS_PATH" == "")
AC_PATH_PROG(GUNZIP_PATH, gunzip)
if test "$GUNZIP_PATH" != ""
then
    AC_DEFINE_UNQUOTED(GUNZIP, "$GUNZIP_PATH", [Path to gunzip program])
fi
AM_CONDITIONAL(TGUNZIP, test "$GUNZIP_PATH" == "")
AC_PATH_PROG(BUNZIPTWO_PATH, bunzip2)
if test "$BUNZIPTWO_PATH" != ""
then
    AC_DEFINE_UNQUOTED(BUNZIPTWO, "$BUNZIPTWO_PATH", [Path to bunzip2 program])
fi
AM_CONDITIONAL(TBUNZIPTWO, test "$BUNZIPTWO_PATH" == "")
AC_PATH_PROG(RAR_PATH, rar)
if test "$RAR_PATH" != ""
then
    AC_DEFINE_UNQUOTED(RAR, "$RAR_PATH", [Path to rar program])
fi
AM_CONDITIONAL(TRAR, test "$RAR_PATH" == "")
AC_PATH_PROG(SEVENZ_PATH, 7z)
if test "$SEVENZ_PATH" != ""
then
    AC_DEFINE_UNQUOTED(SEVENZ, "$SEVENZ_PATH", [Path to 7z program])
else
	AC_PATH_PROG(SEVENZ_PATH, 7za)
	if test "$SEVENZ_PATH" != ""
	then
		AC_DEFINE_UNQUOTED(SEVENZ, "$SEVENZ_PATH", [Path to 7za program])
	fi
fi
AM_CONDITIONAL(TSEVENZ, test "$SEVENZ_PATH" == "")
AC_PATH_PROG(ZOO_PATH, zoo)
if test "$ZOO_PATH" != ""
then
    AC_DEFINE_UNQUOTED(ZOO, "$ZOO_PATH", [Path to zoo program])
fi
AM_CONDITIONAL(TZOO, test "$ZOO_PATH" == "")
AC_PATH_PROG(TAR_PATH, tar)
if test "$TAR_PATH" != ""
then
    AC_DEFINE_UNQUOTED(TAR, "$TAR_PATH", [Path to tar program])
fi
AM_CONDITIONAL(TTAR, test "$TAR_PATH" == "")
AC_PATH_PROG(ZZIP_PATH, zzip.exe)
if test "$ZZIP_PATH" != ""
then
  AC_DEFINE_UNQUOTED(ZZIP, "$ZZIP_PATH", [Path to zzip.exe program])
fi
AM_CONDITIONAL(TZZIP, test "$ZZIP_PATH" == "")
AC_PATH_PROG(ZZIP_PATH, zzip)
if test "$ZZIP_PATH" != ""
then
  AC_DEFINE_UNQUOTED(ZZIP, "$ZZIP_PATH", [Path to zzip program])
fi
AM_CONDITIONAL(TZZIP, test "$ZZIP_PATH" == "")

AC_PATH_PROG(RZIP_PATH, rzip)
if test "$RZIP_PATH" != ""
then
    AC_DEFINE_UNQUOTED(RZIP, "$RZIP_PATH", [Path to rzip program])
fi
AM_CONDITIONAL(TRZIP, test "$RZIP_PATH" == "")

AC_PATH_PROG(AR_PATH, ar)
if test "$AR_PATH" != ""
then
    AC_DEFINE_UNQUOTED(AR, "$AR_PATH", [Path to ar program])
fi
AM_CONDITIONAL(TAR, test "$AR_PATH" == "")
AC_PATH_PROG(LZOP_PATH, lzop)
if test "$LZOP_PATH" != ""
then
    AC_DEFINE_UNQUOTED(LZOP, "$LZOP_PATH", [Path to lzop program])
fi
AM_CONDITIONAL(TLZOP, test "$LZOP_PATH" == "")
AC_PATH_PROG(LHA_PATH, lha)
if test "$LHA_PATH" != ""
then
    AC_DEFINE_UNQUOTED(LHA, "$LHA_PATH", [Path to lha program])
fi
AM_CONDITIONAL(TLHA, test "$LHA_PATH" == "")
AC_PATH_PROG(XAR_PATH, xar)
if test "$XAR_PATH" != ""
then
	AC_DEFINE_UNQUOTED(XAR, "$XAR_PATH", [Path to xar program])
fi
AM_CONDITIONAL(TXAR, test "$XAR_PATH" == "")
AC_PATH_PROG(SHAR_PATH, shar)
if test "$SHAR_PATH" != ""
then
	AC_DEFINE_UNQUOTED(SHAR, "$SHAR_PATH", [Path to shar program])
fi
AM_CONDITIONAL(TSHAR, test "$SHAR_PATH" == "")


dnl Checks for libraries.
AC_PROG_LIBTOOL

dnl Checks for header files.

dnl Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_SIZE_T

dnl Checks for library functions.
dnl AC_CHECK_LIB(m, pow)
AC_CHECK_FUNCS([putenv setenv])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])
AC_OUTPUT

echo "
---------------------------
Peek configuration complete
"
if test "$CPIO_PATH" != ""
then
	echo "cpio support ........ Yes"
else
	echo "cpio support ........ No"
fi
if test "$LZOP_PATH" != ""
then
	echo "lzop support ........ Yes"
else
	echo "lzop support ........ No"
fi
if test "$ARJ_PATH" != ""
then
    echo "arj support ......... Yes"
else
    echo "arj support ......... No"
fi
if test "$UNZIP_PATH" != ""
then
    echo "zip support ......... Yes"
else
    echo "zip support ......... No"
fi
if test "$UNACE_PATH" != ""
then
    echo "ace support ......... Yes"
else
    echo "ace support ......... No"
fi
if test "$COMPRESS_PATH" != ""
then
    echo "compress support .... Yes"
else
    echo "compress support .... No"
fi
if test "$GUNZIP_PATH" != ""
then
    echo "gzip support ........ Yes"
else
    echo "gzip support ........ No"
fi
if test "$BUNZIPTWO_PATH" != ""
then
    echo "bzip2 support ....... Yes"
else
    echo "bzip2 support ....... No"
fi
if test "$RAR_PATH" != ""
then
    echo "rar support ......... Yes"
else
    echo "rar support ......... No"
fi
if test "$SEVENZ_PATH" != ""
then
    echo "7z support .......... Yes"
else
    echo "7z support .......... No"
fi
if test "$ZOO_PATH" != ""
then
    echo "zoo support ......... Yes"
else
    echo "zoo support ......... No"
fi
if test "$AR_PATH" != ""
then
    echo "ar support .......... Yes"
else
    echo "ar support .......... No"
fi
if test "$LHA_PATH" != ""
then
	echo "lha support ......... Yes"
else
	echo "lha support ......... No"
fi
if test "$XAR_PATH" != ""
then
	echo "xar support ......... Yes"
else
	echo "xar support ......... No"
fi
if test "$SHAR_PATH" != ""
then
	echo "shar support ........ Yes"
else
	echo "shar support ........ No"
fi
if test "$TAR_PATH" != ""
then
    echo "tar support ......... Yes"
else
    echo "tar support ......... No"
fi
if test "$ZZIP_PATH" != ""
then
  echo "zzip support ........ Yes"
else
  echo "zzip support ........ No"
fi
if test "$RZIP_PATH" != ""
then
  echo "rzip support ........ Yes"
else
  echo "rzip support ........ No"
fi
echo "---------------------------
"

dnl Don't build if we have no support for anything!
if test "$CPIO_PATH" == "" && \
	test "$ARJ_PATH" == "" && \
    test "$UNZIP_PATH" == "" && \
    test "$UNACE_PATH" == "" && \
    test "$COMPRESS_PATH" == "" && \
    test "$GUNZIP_PATH" == "" && \
    test "$BUNZIPTWO_PATH" != "" && \
    test "$RAR_PATH" != "" && \
    test "$SEVENZ_PATH" != "" && \
    test "$ZOO_PATH" != "" && \
    test "$TAR_PATH" != "" && \
    test "$AR_PATH" != "" && \
    test "$XAR_PATH" != "" && \
    test "$SHAR_PATH" != "" && \
    test "$LHA_PATH" != "" && \
    test "$ZZIP_PATH" != "" && \
    test "RZIP_PATH" != ""
then
    echo "NO SUPPORT FOR ANYTHING FOUND
Check your PATH"
    exit 1
fi
