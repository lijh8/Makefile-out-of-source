# Makefile for subdir

# build shared library with -fPIC, -shared
CFLAGS    = # -g -O3 -fPIC # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP -I../foo
LDFLAGS   = -L$(OBJDIR)/foo # -shared
LDLIBS    = -lfoo
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,$(OBJDIR)/foo
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
#LDFLAGS += -Wl,-soname,$(soname)

# make # NDEBUG=1
ifdef NDEBUG
CPPFLAGS += -DNDEBUG
CFLAGS   += -O3 # .cpp
else
CFLAGS   += -g # .cpp
LDFLAGS  += -fsanitize=address
endif

all : $(OBJDIR)/main/main # foo

$(OBJDIR)/main/main : $(OBJDIR)/main/$(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@  # CXX for .cpp

$(OBJDIR)/main/%.o : %.c | $(OBJDIR)/main
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<  # CXX CXXFLAGS for .cpp

$(OBJDIR)/main: ; mkdir -p $(OBJDIR)/main

-include $(OBJDIR)/main/*.d
clean : ; -rm -fr $(OBJDIR)

.PHONY : all clean
