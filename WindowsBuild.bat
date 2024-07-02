@echo on
git submodule update --init --recursive
cmake -S . -B build
ninja -C build