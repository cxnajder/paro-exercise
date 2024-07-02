@echo on
@echo =================== Git: Downloading Submodules ====================
git submodule update --init --recursive
@echo =================== CMake: Preparing Build Files ===================
cmake -S . -B build
@echo =================== Ninja: Building ================================
ninja -C build
@echo ====================================================================