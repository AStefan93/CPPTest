cmake_minimum_required(VERSION 3.22)

project(CMakeTest)

add_compile_options(-std=c++17 -Wall)
add_link_options(-lstdc++ -lm)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(
    STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(
    DOWNLOAD
    "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(build/conan.cmake)
conan_cmake_run(REQUIRES gtest/1.12.1 BASIC_SETUP CMAKE_TARGETS)

add_subdirectory(src/hello_world)
