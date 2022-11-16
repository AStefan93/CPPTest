#ifndef CLASSDEMOINTERFACE_HPP
#define CLASSDEMOINTERFACE_HPP
namespace CPPTest {

class IFoo {
 public:
  virtual ~IFoo() = default;
  IFoo(const IFoo& other) = delete;
  IFoo(const IFoo&& other) = delete;
  IFoo& operator=(const IFoo& other) = delete;
  IFoo& operator=(const IFoo&& other) = delete;
};
}  // namespace CPPTest

#endif  // CLASSDEMOINTERFACE_HPP