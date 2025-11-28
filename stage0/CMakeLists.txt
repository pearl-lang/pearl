file(GLOB SOURCES src/*.c)

if(MSVC)
    add_compile_options(/EHsc /D_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -O2)
endif()

add_executable(stage0 ${SOURCES})
target_include_directories(stage0 PRIVATE include)