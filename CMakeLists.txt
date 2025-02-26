set(CMAKE_C_COMPILER "gcc")
set(MAIN_SRC "src/pearl.c")

cmake_minimum_required(VERSION 3.0)
project(Pearl C)

# Dependencies.
find_package(FLEX)
find_package(BISON)

flex_target(LEXER src/lexer.l src/lexer.c)
bison_target(PARSER src/parser.y src/parser.c)
add_flex_bison_dependency(LEXER PARSER)

include_directories("include")

# General C elements.
file(GLOB SRC_C_FILES src/*.c)
list(REMOVE_ITEM SRC_C_FILES MAIN_SRC)

add_library(SRC_C_FILES OBJECT "${SRC_C_FILES}")
add_executable(
    pearl
    "${MAIN_SRC}"
)

target_include_directories(pearl PRIVATE "include" src)

