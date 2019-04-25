cmake_minimum_required(VERSION 2.8.4)

project(hello)

include_directories(.)

add_definitions(-include all_common.h)

add_executable(hello hello.c)
