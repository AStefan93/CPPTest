#include <iostream>

#include "src/test.hpp"

void bar(const foo& test_foo) { std::cout << test_foo.product() << std::endl; }

int main() {
  foo test_foo{6, 6};
  bar(test_foo);
  std::cout << "hello world" << std::endl;
}