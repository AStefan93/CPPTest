#ifndef CLASSDEMO_HPP
#define CLASSDEMO_HPP

#include <string>

#include "classDemoInterface.hpp"

namespace CPPTest::ClassDemo {

class Foo : public IFoo {
 public:
  [[nodiscard]] std::string foobar() const override;

 private:
  std::string m_words{"hello world Foo"};
};
class Bar : public IFoo {
 public:
  Bar() = default;
  // NOLINTNEXTLINE
  Bar(int nr_one, int nr_two) : m_number_one(nr_one), m_number_two(nr_two){};
  [[nodiscard]] std::string foobar() const override;

 private:
  std::string m_words{"hello world Bar"};
  int m_number_one{0};
  int m_number_two{0};
};
}  // namespace CPPTest::ClassDemo

#endif  // CLASSDEMO_HPP