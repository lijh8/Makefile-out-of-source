# Makefile for subdir

# build shared library with -fPIC, -shared
CFLAGS    = -fPIC # -g -O3 # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP # -I../bar
LDFLAGS   = -shared # -L$(OBJDIR)/bar
LDLIBS    = # -lbar
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,$(OBJDIR)/bar
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

SUBDIR    = $(OBJDIR)/foo

all : $(SUBDIR)/foo # $(SUBDIR)/bar

$(SUBDIR)/foo : $(SUBDIR)/$(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@ # .cpp

$(SUBDIR)/%.o : %.c | $(SUBDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< # .cpp

$(SUBDIR): ; mkdir -p $(SUBDIR)

-include $(SUBDIR)/*.d
clean : ; -rm -fr $(SUBDIR)
.PHONY : all clean
