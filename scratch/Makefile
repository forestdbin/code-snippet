ifndef DEBUG
    DEBUG := 1
endif
USE_GLIB := 1

program := hello
program_srcs := $(wildcard *.c *.cc *.cpp *.cxx)
program_objs := $(program_srcs:.c=.o)
program_objs := $(program_objs:.cc=.o)
program_objs := $(program_objs:.cpp=.o)
program_objs := $(program_objs:.cxx=.o)
built_files := $(program) $(program_objs)

COMMON_MACROS := # -D _GNU_SOURCE
ifeq ($(DEBUG), 1)
    COMMON_MACROS += -D DEBUG
endif
ALL_MACROS := $(COMMON_MACROS)
COMMON_INCLUDES := -include all_common.h -include all_3p.h
ALL_INCLUDES := $(COMMON_INCLUDES)
CPPFLAGS := $(ALL_MACROS) $(ALL_INCLUDES)

COMMON_CFLAGS := -Wall -Wextra -pthread
ifeq ($(DEBUG), 1)
    COMMON_CFLAGS += -g
endif
ifeq ($(COVERAGE), 1)
    common_cflags += --coverage
endif
CFLAGS := -std=c11 $(COMMON_CFLAGS)
CXXFLAGS := -std=c++11 $(COMMON_CFLAGS)
ifeq ($(USE_GLIB), 1)
    GLIB_CFLAGS := $(shell pkg-config --cflags glib-2.0)
    CFLAGS += $(GLIB_CFLAGS)
    CXXFLAGS += $(GLIB_CFLAGS)
endif

LDFLAGS := -pthread
ifeq ($(RELEASE), 1)
    LDFLAGS += -s
endif
LDLIBS := -lc -lstdc++
ifeq ($(USE_GLIB), 1)
    GLIB_LDFLAGS := $(shell pkg-config --libs-only-L --libs-only-other glib-2.0)
    GLIB_LDLIBS := $(shell pkg-config --libs-only-l glib-2.0)
    LDFLAGS += $(GLIB_LDFLAGS)
    LDLIBS += $(GLIB_LDLIBS)
endif

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
