set(CMAKE_C_COMPILER "gcc")
set(MAIN_SRC "src/pearl.c")

cmake_minimum_required(VERSION 3.0)
project(Pearl C)

# Dependencies.
find_package(FLEX)
find_package(BISON)

flex_target(LEXER "src/lexer.l" "${CMAKE_CURRENT_BINARY_DIR}/lexer.c" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/lexer.h")
bison_target(PARSER "src/parser.y" "${CMAKE_CURRENT_BINARY_DIR}/parser.c" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/parser.h")
add_flex_bison_dependency(LEXER PARSER)

include_directories("include")

# General C elements.
file(GLOB SRC_C_FILES src/*.c)
list(REMOVE_ITEM SRC_C_FILES MAIN_SRC)

add_library(SRC_C_FILES OBJECT "${SRC_C_FILES}")
add_executable(
    pearl
    "${MAIN_SRC}"
    "${CMAKE_CURRENT_BINARY_DIR}/lexer.c"
    "${CMAKE_CURRENT_BINARY_DIR}/parser.c"
)

target_include_directories(pearl PRIVATE "include" "src" "${CMAKE_CURRENT_BINARY_DIR}")

