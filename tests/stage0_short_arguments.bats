#!/usr/bin/env bats

@test "Short help '-h' argument" {
    run "$PEARL_BIN" -h
    [ "$status" -eq 0 ]
    [[ "$output" == *"Usage:"* ]]
}

@test "Short version '-V' argument" {
    run "$PEARL_BIN" -V
    [ "$status" -eq 0 ]
    [[ "$output" == *"Pearl v"* ]]
}

@test "Verbosity '-vvv' which is info level" {
    run "$PEARL_BIN" -vvv
    [ "$status" -eq 0 ]
    [[ "$output" == *"(INFO): Parsed 0 source files."* ]]
    [[ "$output" == *"(INFO): Output File: Not specified"* ]]
}