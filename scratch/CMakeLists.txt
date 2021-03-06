cmake_minimum_required(VERSION 3.16)

project(hello)

aux_source_directory(${${PROJECT_NAME}_SOURCE_DIR} program_srcs)
add_executable(${PROJECT_NAME} ${program_srcs})

target_compile_options(
    ${PROJECT_NAME}
    PUBLIC "SHELL:-std=c++11 -g -Wall -Wextra -pthread"
    PUBLIC "SHELL:-include ${hello_SOURCE_DIR}/all_common.h"
    PUBLIC "SHELL:-include ${hello_SOURCE_DIR}/all_3p.h"
)

target_link_options(
    ${PROJECT_NAME}
    PUBLIC -pthread
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB glib-2.0)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${GLIB_INCLUDE_DIRS}
)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE ${GLIB_LIBRARIES}
)
