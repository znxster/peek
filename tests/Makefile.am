TESTS_ENVIRONMENT = $(SHELL)

TESTS = $(srcdir)/*.sh
XFAIL_TESTS = $(srcdir)/NoFile.sh $(srcdir)/UnkFile.sh

EXTRA_DIST=$(TESTS) $(XFAIL_TESTS)

# Need to fix Rar and Ace tests

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
XFAIL_TESTS += $(srcdir)/Z.sh
endif
if TGUNZIP
XFAIL_TESTS += $(srcdir)/*GZ.sh
endif
if TBUNZIPTWO
XFAIL_TESTS += $(srcdir)/*BZ2.sh
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
XFAIL_TESTS += $(srcdir)/Tar*.sh
endif

MAINTAINERCLEANFILES=Makefile.in
