TESTS_ENVIRONMENT = $(SHELL)

TESTS = $(srcdir)/*.sh
XFAIL_TESTS = $(srcdir)/NoFile.sh $(srcdir)/UnkFile.sh

EXTRA_DIST=$(TESTS) $(XFAIL_TESTS)

# Need to fix Rar and Ace tests

if TCPIO
XFAIL_TESTS += $(srcdir)/Cpio.sh
endif
if TXAR
XFAIL_TESTS += $(srcdir)/Xar.sh
endif
if TSHAR
XFAIL_TESTS += $(srcdir)/Shar.sh
endif
if TLHA
XFAIL_TESTS += $(srcdir)/Lha.sh
endif
if TAR
XFAIL_TESTS += $(srcdir)/Ar.sh
endif
if TLZOP
XFAIL_TESTS += $(srcdir)/Lzop.sh
endif
if TARJ
XFAIL_TESTS += $(srcdir)/Arj.sh
endif
if TUNZIP
XFAIL_TESTS += $(srcdir)/Zip.sh
endif
#if TUNACE
#XFAIL_TESTS += $(srcdir)/Ace.sh
#endif
if TCOMPRESS
XFAIL_TESTS += $(srcdir)/Z.sh $(srcdir)/TarZ.sh
endif
if TGUNZIP
XFAIL_TESTS += $(srcdir)/GZ.sh $(srcdir)/TarGZ.sh
endif
if TBUNZIPTWO
XFAIL_TESTS += $(srcdir)/BZ2.sh $(srcdir)/TarBZ2.sh
endif
#if TRAR
#XFAIL_TESTS += $(srcdir)/Rar.sh
#endif
if TSEVENZ
XFAIL_TESTS += $(srcdir)/7z.sh
endif
if TZOO
XFAIL_TESTS += $(srcdir)/Zoo.sh
endif
if TTAR
XFAIL_TESTS += $(srcdir)/Tar.sh $(srcdir)/TarBZ2.sh  $(srcdir)/TarGZ.sh  $(srcdir)/TarZ.sh
endif
if TZZIP
XFAIL_TESTS += $(srcdir)/Zzip.sh
endif
if TRZIP
XFAIL_TESTS += $(srcdir)/Rzip.sh
endif

MAINTAINERCLEANFILES=Makefile.in
CLEANFILES=testfile*
