#!/bin/sh
echo =================== Git: Downloading Submodules ====================
git submodule update --init --recursive
echo =================== CMake: Preparing Build Files ===================
cmake -S . -B build -DBENCHMARK_ENABLE_TESTING=OFF -DCMAKE_BUILD_TYPE=Release
echo =================== Make: Building =================================
cmake --build build --config Release
echo ====================================================================
