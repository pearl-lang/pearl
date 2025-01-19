cmake_minimum_required(VERSION 3.0)
project(Pearl C)

file(GLOB LIB_SOURCES lib/*.c)

add_library(lib_objects OBJECT ${LIB_SOURCES})

add_executable(pearl src/pearl.c)

target_link_libraries(pearl PRIVATE $<TARGET_OBJECTS:lib_objects>)

target_include_directories(pearl PRIVATE lib src)
