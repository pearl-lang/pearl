add_compile_options(-Wall -Wextra -O2)
file(GLOB SOURCES src/*.c)

add_executable(pearl ${SOURCES})

target_include_directories(pearl PRIVATE include)