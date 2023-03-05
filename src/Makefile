# Makefile for top dir

# $(call makever,1.2.3)
# major.minor.patch
define makever
	$(MAKE) -C $@ soname=lib$@.so.$(word 1,$(subst ., ,$(1)))

	@ cp $(OBJDIR)/$@/$@ $(OBJDIR)/$@/lib$@.so.$(1)

	@ cd $(OBJDIR)/$@; ln -f -s $(OBJDIR)/$@/lib$@.so.$(1) \
		$(OBJDIR)/$@/lib$@.so.$(word 1,$(subst ., ,$(1))); cd ..

	@ cd $(OBJDIR)/$@; ln -f -s $(OBJDIR)/$@/lib$@.so.$(1) \
		$(OBJDIR)/$@/lib$@.so; cd ..
endef

# make # BUILD_DIR=build
ifndef BUILD_DIR
export OBJDIR = $(abspath build)
else
export OBJDIR = $(abspath $(BUILD_DIR))
endif

SUBDIRS = main foo

all : $(SUBDIRS)
install : $(SUBDIRS)

main : foo
main : ; $(MAKE) -C $@
foo : ; $(call makever,1.2.3)

# make DESTDIR=~/foo install
install :
	install -d "$(DESTDIR)/usr/local/bin"
	install -d "$(DESTDIR)/usr/local/lib"
	install -m 0755 $(OBJDIR)/main/main "$(DESTDIR)/usr/local/bin"
	install -m 0755 $(OBJDIR)/foo/*.so* "$(DESTDIR)/usr/local/lib"

clean : ; -rm -fr $(OBJDIR)

.PHONY : $(SUBDIRS) all install clean
