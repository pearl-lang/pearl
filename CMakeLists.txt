cmake_minimum_required(VERSION 3.10)
project(Pearl C)

enable_testing()

add_subdirectory(stage0)
# add_subdirectory(stage1)
# add_subdirectory(stage2)
if (UNIX)
    add_subdirectory(tests)
endif(UNIX)