program := glib_base64
program_srcs := $(wildcard *.c) $(wildcard *.cc *.cpp)
program_objs := $(program_srcs:.c=.o)
program_objs := $(program_objs:.cc=.o)
program_objs := $(program_objs:.cpp=.o)
built_files := $(program) $(program_objs)

COMMON_MACROS := #
ALL_MACROS := $(COMMON_MACROS)
COMMON_INCLUDES := -include all_common.h
ALL_INCLUDES := $(COMMON_INCLUDES)
CPPFLAGS := $(ALL_MACROS) $(ALL_INCLUDES)

GLIB_CFLAGS := $(shell pkg-config --cflags glib-2.0)
CFLAGS := -std=c11 -g -Wall -Wextra $(GLIB_CFLAGS)
CXXFLAGS := -std=c++11 -g -Wall -Wextra $(GLIB_CFLAGS)

GLIB_LDFLAGS := $(shell pkg-config --libs-only-L --libs-only-other glib-2.0)
GLIB_LDLIBS := $(shell pkg-config --libs-only-l glib-2.0)
LDFLAGS := $(GLIB_LDFLAGS)
LDLIBS := -lc -lstdc++ $(GLIB_LDLIBS)

$(program) : $(program_objs)

# %.o : %.c

.DEFAULT_GOAL := all

.SILENT : a
.PHONY : a
a :
	echo program is: $(program)
	echo program_srcs is: $(program_srcs)
	echo program_objs is: $(program_objs)
	echo built_files is: $(built_files)

.PHONY : all
all : $(program)

.PHONY : clean
clean :
	-@ rm -rf $(built_files)
