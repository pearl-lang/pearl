find_program(BATS_EXECUTABLE NAMES bats)

if (NOT BATS_EXECUTABLE)
    message(FATAL_ERROR "Bats testing framework not found. Please install Bats to run the tests.")
endif()

file(GLOB BATS_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/*.bats")

foreach(test_file ${BATS_TESTS})
    get_filename_component(test_name ${test_file} NAME_WE)
    if(test_name MATCHES "^stage0_")
        set(PEARL_BIN $<TARGET_FILE:stage0>)
    else()
        message(FATAL_ERROR "Unknown stage in test: ${test_file}")
    endif()

    add_test(
        NAME ${test_name}
        COMMAND ${BATS_EXECUTABLE} "${test_file}"
    )
    set_tests_properties(${test_name} PROPERTIES ENVIRONMENT "PEARL_BIN=${PEARL_BIN}")
endforeach()
