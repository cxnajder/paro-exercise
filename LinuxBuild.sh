#!/bin/sh
cmake -S . -B build -DBENCHMARK_ENABLE_TESTING=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
