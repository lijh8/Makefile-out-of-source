# Makefile for subdir

# build shared library with -fPIC, -shared
CFLAGS    = # -g -O3 -fPIC # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP -I../foo
LDFLAGS   = -L$(OBJDIR)/foo # -shared
LDLIBS    = -lfoo
#CC       = $(CXX) # link with CXX for .cpp

# LDFLAGS  += -Wl,-rpath,$(OBJDIR)/foo
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../foo'
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
#LDFLAGS += -Wl,-soname,$(soname)

# make # NDEBUG=1
ifdef NDEBUG
CFLAGS   += -O3 # .cpp
CPPFLAGS += -DNDEBUG
else
CFLAGS   += -g # .cpp
LDFLAGS  += -fsanitize=address
endif

SUBDIR    = $(OBJDIR)/$(lastword $(subst /, ,$(CURDIR)))

all : $(SUBDIR)/main # $(SUBDIR)/foo

# https://make.mad-scientist.net/papers/how-not-to-use-vpath/
$(SUBDIR)/main : $(addprefix $(SUBDIR)/,$(patsubst %.c,%.o,$(wildcard *.c))) # .cpp
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(SUBDIR)/%.o : %.c | $(SUBDIR) # .cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SUBDIR) : ; @ mkdir $@

-include $(SUBDIR)/*.d
clean : ; -rm -fr $(SUBDIR)
.PHONY : all clean
