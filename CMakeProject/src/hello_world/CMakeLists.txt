cmake_minimum_required(VERSION 3.22)

# set the project name
project(HelloWorld)

# add the executable
add_executable(HelloWorldMain hello_world_main.cpp)
target_link_libraries(HelloWorldMain HelloWorld)

add_library(HelloWorld hello_world.cpp)

enable_testing()
add_executable(TestHelloWorld test_hello_world.cpp)
target_link_libraries(TestHelloWorld HelloWorld CONAN_PKG::gtest)

include(GoogleTest)
gtest_discover_tests(TestHelloWorld)
