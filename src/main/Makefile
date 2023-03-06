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

SUBDIR    = $(OBJDIR)/main

all : $(SUBDIR)/main # $(SUBDIR)/foo

$(SUBDIR)/main : $(addprefix $(SUBDIR)/,$(patsubst %.c,%.o,$(wildcard *.c))) # .cpp
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(SUBDIR)/%.o : %.c | $(SUBDIR) # .cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SUBDIR) : ; @ mkdir $@

-include $(SUBDIR)/*.d
clean : ; -rm -fr $(SUBDIR)
.PHONY : all clean
