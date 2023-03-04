# Makefile for subdir

# build shared library with -fPIC, -shared
CFLAGS    = -fPIC # -g -O3 # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP # -I../bar
LDFLAGS   = -shared # -L../bar
LDLIBS    = # -lbar
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../bar'
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
LDFLAGS  += -Wl,-soname,$(soname)

# make # NDEBUG=1
ifdef NDEBUG
CPPFLAGS += -DNDEBUG
CFLAGS   += -O3 # .cpp
else
CFLAGS   += -g # .cpp
LDFLAGS  += -fsanitize=address
endif

all : $(OBJDIR)/foo/foo # foo

$(OBJDIR)/foo/foo : $(OBJDIR)/foo/$(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@  # CXX for .cpp

$(OBJDIR)/foo/%.o : %.c | $(OBJDIR)/foo
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<  # CXX CXXFLAGS for .cpp

$(OBJDIR)/foo: ; mkdir -p $(OBJDIR)/foo

-include $(OBJDIR)/foo/*.d

clean : ; -rm -fr $(OBJDIR)

.PHONY : all clean
