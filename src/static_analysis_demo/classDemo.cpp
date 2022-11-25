#include "classDemo.hpp"

#include <string>

namespace CPPTest::ClassDemo {
std::string Foo::foobar() const { return m_words; }
std::string Bar::foobar() const {
  return m_words + " " + std::to_string(m_number_one) + " " +
         std::to_string(m_number_two);
}
}  // namespace CPPTest::ClassDemo