program := hello
program_srcs := $(wildcard *.c) $(wildcard *.cc *.cpp)
program_objs := $(program_srcs:.c=.o)
program_objs := $(program_objs:.cc=.o)
program_objs := $(program_objs:.cpp=.o)
built_files := $(program) $(program_objs)

COMMON_MACROS := # -D _GNU_SOURCE -D DEBUG
ALL_MACROS := $(COMMON_MACROS)
COMMON_INCLUDES := -include all_common.h
ALL_INCLUDES := $(COMMON_INCLUDES)
CPPFLAGS := $(ALL_MACROS) $(ALL_INCLUDES)

FOO_CFLAGS := # $(shell pkg-config --cflags foo)
CFLAGS := -std=c11 -g -Wall -Wextra -pthread
CXXFLAGS := -std=c++11 -g -Wall -Wextra -pthread

FOO_LDFLAGS := # $(shell pkg-config --libs-only-L --libs-only-other foo)
FOO_LDLIBS := # $(shell pkg-config --libs-only-l foo)
LDFLAGS := -pthread
LDLIBS := -lc -lstdc++

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
