#!/bin/zsh
cmake --build build
cd build
ctest
cd ..
