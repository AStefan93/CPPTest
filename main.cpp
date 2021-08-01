#include <iostream>

#include "src/test.hpp"

int const TEST_VARIABLE = 0;

void bar(const test::Foo& test_foo) {
  std::cout << test_foo.product() << std::endl;
}

double foobar(const double x, const double /*unused*/) { return x; }

class Stuff {
  Stuff();
  //~STUFF();
};

class TestClass {
  TestClass();
  ~TestClass();
  TestClass(const TestClass& test);
  TestClass(const TestClass&& test);
  TestClass& operator=(const TestClass& test);
  TestClass& operator=(const TestClass&& test);

 private:
  double m_x;
  double m_y;
};

int main() {
  // foo* test_foo_p = new foo{1, 1};
  constexpr auto x{6};
  constexpr auto yTestTest{5};

  // const double STARTINGTestValue = 4;

  test::Foo test_foo{x, yTestTest};
  bar(test_foo);
  // std::cout << test_foo_p->product() << std::endl;
  std::cout << "hello world" << std::endl;
}