set(CMAKE_C_COMPILER "gcc")
set(MAIN_SRC "src/pearl.c")
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
endif()

cmake_minimum_required(VERSION 3.0)
project(Pearl C)

# Dependencies.
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

flex_target(LEXER "src/lexer.l" "${CMAKE_CURRENT_BINARY_DIR}/lexer.c" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/lexer.h")
bison_target(PARSER "src/parser.y" "${CMAKE_CURRENT_BINARY_DIR}/parser.c" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/parser.h")
add_flex_bison_dependency(LEXER PARSER)

include_directories("include")

# General C elements.
file(GLOB SRC_C_FILES src/*.c)

add_library(SRC_C_FILES OBJECT "${SRC_C_FILES}")
add_executable(
    pearl
    "${SRC_C_FILES}"
    "${CMAKE_CURRENT_BINARY_DIR}/lexer.c"
    "${CMAKE_CURRENT_BINARY_DIR}/parser.c"
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(
        TARGET pearl
        POST_BUILD
        COMMAND strip --strip-all $<TARGET_FILE:pearl>
        COMMENT "Stripping binary..."
    )
endif()

target_include_directories(pearl PRIVATE "include" "src" "${CMAKE_CURRENT_BINARY_DIR}")
