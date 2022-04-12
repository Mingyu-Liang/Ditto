#!/usr/bin/env bash

make clean
./configure CPPFLAGS=-DDEBUG -CXXFLAGS="-g3 -O0 -D_GLIBCXX_DEBUG"
make -j
