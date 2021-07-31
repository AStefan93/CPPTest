#ifndef TEST_HPP
#define TEST_HPP

namespace test {
class Foo {
 public:
  Foo();
  Foo(const double x, const double y) : m_x{x}, m_y{y} {};
  auto product() const -> double;

 private:
  double m_x{};
  double m_y{};
};

struct foo_bar {
  double x{0};
  double y{0};
};
}  // namespace test

#endif  // TEST_HPP