cmake_minimum_required(VERSION 3.22.1)
project(Tutorial VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
add_subdirectory(src/Tutorial)
