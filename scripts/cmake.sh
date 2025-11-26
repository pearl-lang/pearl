#!/bin/sh

# Description:
#    Hakan fidanın kapısını açan adamın kapısın açan adam.
# Usage:
#    u@h:~/pearl$ ./scripts/cmake.sh .
#    u@h:~/pearl$ REBUILD=1 ./scripts/cmake.sh . # to force rebuild
# Requires: 
#    - coreuitls
#    - cmake

set -e

WD="${1}"
cd "${WD:-.}"

[ -n "${REBUILD}" ] && rm -rf "build"
[ ! -d "build" ] && mkdir "build"
cd "build"
cmake ..