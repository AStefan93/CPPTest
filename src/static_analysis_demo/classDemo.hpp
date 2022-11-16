#include <string>

#include "classDemoInterface.hpp"

namespace CPPTest::ClassDemo {

class Foo : IFoo {
 public:
  Foo();
  explicit Foo(const std::string& words);

 private:
  std::string m_words;
};
}  // namespace CPPTest::ClassDemo