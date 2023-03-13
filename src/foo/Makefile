# Makefile for subdir

# build shared library with -fPIC, -shared
CFLAGS    = -fPIC # -g -O3 # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP # -I../bar
LDFLAGS   = -shared # -L$(OBJDIR)/bar
LDLIBS    = # -lbar
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../bar'
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
LDFLAGS  += -Wl,-soname,$(soname)

# make # NDEBUG=1
ifdef NDEBUG
CFLAGS   += -O3 # .cpp
CPPFLAGS += -DNDEBUG
else
CFLAGS   += -g # .cpp
LDFLAGS  += -fsanitize=address
endif

SUBDIR    = $(OBJDIR)/$(lastword $(subst /, ,$(CURDIR)))

all : $(SUBDIR)/foo # $(SUBDIR)/bar

# https://make.mad-scientist.net/papers/how-not-to-use-vpath/
$(SUBDIR)/foo : $(addprefix $(SUBDIR)/,$(patsubst %.c,%.o,$(wildcard *.c))) # .cpp
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(SUBDIR)/%.o : %.c | $(SUBDIR) # .cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SUBDIR) : ; @ mkdir $@

-include $(SUBDIR)/*.d
clean : ; -rm -fr $(SUBDIR)
.PHONY : all clean
