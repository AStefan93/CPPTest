#include <iostream>

#include "hello_world.hpp"

int main() {
  std::cout << CMakeTest::HelloWorld::fn_hello_world();
  return 0;
}