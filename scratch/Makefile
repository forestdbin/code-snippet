program := hello
program_srcs := $(wildcard *.c *.cc *.cpp *.cxx)
program_objs := $(program_srcs:.c=.o)
program_objs := $(program_objs:.cc=.o)
program_objs := $(program_objs:.cpp=.o)
program_objs := $(program_objs:.cxx=.o)
built_files := $(program) $(program_objs)

COMMON_MACROS := # -D _GNU_SOURCE -D DEBUG
ALL_MACROS := $(COMMON_MACROS)
COMMON_INCLUDES := -include all_common.h -include all_3p.h
ALL_INCLUDES := $(COMMON_INCLUDES)
CPPFLAGS := $(ALL_MACROS) $(ALL_INCLUDES)

FOO_CFLAGS := # $(shell pkg-config --cflags foo)
COMMON_CFLAGS := -g -Wall -Wextra -pthread
CFLAGS := -std=c11 $(COMMON_CFLAGS) $(FOO_CFLAGS)
CXXFLAGS := -std=c++11 $(COMMON_CFLAGS) $(FOO_CFLAGS)

FOO_LDFLAGS := # $(shell pkg-config --libs-only-L --libs-only-other foo)
FOO_LDLIBS := # $(shell pkg-config --libs-only-l foo)
LDFLAGS := -pthread $(FOO_LDFLAGS)
LDLIBS := -lc -lstdc++ $(FOO_LDLIBS)

.DEFAULT_GOAL := all

$(program) : $(program_objs)
	$(CC) $(LDFLAGS) $+ $(LDLIBS) -o $@

.PHONY : all
all : $(program)

.PHONY : clean
clean :
	-@ rm -rf $(built_files)

.SILENT : a
.PHONY : a
a :
	echo program is: $(program)
	echo program_srcs is: $(program_srcs)
	echo program_objs is: $(program_objs)
	echo built_files is: $(built_files)
