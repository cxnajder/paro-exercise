cmake_minimum_required(VERSION 3.17.1)
project(PARO-workshop)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(gtest)
add_subdirectory(application)


