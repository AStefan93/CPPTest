cmake_minimum_required(VERSION 3.22.1)
project(Tutorial VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
add_subdirectory(src/Tutorial)
add_subdirectory(src/array)
