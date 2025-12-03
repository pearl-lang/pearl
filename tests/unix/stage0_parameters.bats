#!/usr/bin/env bats

@test "Can handle short output parameter" {
    run "$PEARL_BIN" -vvv -o test
    [ "$status" -eq 0 ]
    [[ "$output" == *"(INFO): Output File: test"* ]]
}

@test "Can handle long output parameter" {
    run "$PEARL_BIN" -vvv --output test
    [ "$status" -eq 0 ]
    [[ "$output" == *"(INFO): Output File: test"* ]]
}