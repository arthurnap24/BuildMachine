#!/bin/sh
set -e

cmake $CMAKE_OPTIONS . -B ./build
cmake --build ./build $@
