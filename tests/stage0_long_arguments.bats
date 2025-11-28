#!/usr/bin/env bats

@test "--help" {
    run "$PEARL_BIN" --help
    [ "$status" -eq 0 ]
    [[ "$output" == *"Pearl Programming Language Compiler"* ]]
}

@test "--version" {
    run "$PEARL_BIN" --version
    [ "$status" -eq 0 ]
    [[ "$output" == *"Pearl Bootstrap Compiler"* ]]
}