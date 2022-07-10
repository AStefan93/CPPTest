#include "foo.hpp"

#include "bar.hpp"

std::vector<int> FooBar(std::vector<int> x) {
  for (size_t i = 0; i < x.size(); i++) {
    std::cout << x[i] << std::endl;
  }
  std::vector<int> Array = x;

  std::cout << "hello_world" << std::endl;
  return Array;
}