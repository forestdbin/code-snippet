program := debugtest
program_srcs := $(wildcard *.c) $(wildcard *.cc *.cpp)
program_objs := $(program_srcs:.c=.o)
program_objs := $(program_objs:.cc=.o)
program_objs := $(program_objs:.cpp=.o)
built_files := $(program) $(program_objs)

COMMON_MACROS := #
ifdef DEBUG
COMMON_MACROS += -D DEBUG
endif
ALL_MACROS := $(COMMON_MACROS)
COMMON_INCLUDES := -I .
ALL_INCLUDES := $(COMMON_INCLUDES)
CPPFLAGS := $(ALL_MACROS) $(ALL_INCLUDES)

CFLAGS := -std=c11 -g -Wall -Wextra -pthread
CXXFLAGS := -std=c++11 -g -Wall -Wextra -pthread

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
