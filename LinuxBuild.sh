#!/bin/sh
echo =================== Git: Downloading Submodules ====================
git submodule update --init --recursive
echo =================== CMake: Preparing Build Files ===================
cmake -S . -B build
echo =================== Make: Building =================================
make -C build
echo ====================================================================