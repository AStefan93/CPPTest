#ifndef CLASSDEMOINTERFACE_HPP
#define CLASSDEMOINTERFACE_HPP
#include <string>
namespace CPPTest {

class IFoo {
 public:
  virtual ~IFoo() = default;
  [[nodiscard]] virtual std::string foobar() const = 0;

  // IFoo() = delete;
  // IFoo(const IFoo& other) = delete;
  // IFoo(const IFoo&& other) = delete;
  // IFoo& operator=(const IFoo& other) = delete;
  // IFoo& operator=(const IFoo&& other) = delete;
};
}  // namespace CPPTest

#endif  // CLASSDEMOINTERFACE_HPP