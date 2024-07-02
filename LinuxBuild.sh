#!/bin/sh
git submodule update --init --recursive
cmake -S . -B build
make -C build
