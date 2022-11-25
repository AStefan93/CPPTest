#include "classDemo.hpp"

// #include <memory>

#include "gtest/gtest.h"
#include "src/static_analysis_demo/classDemoInterface.hpp"  // for IFoo

namespace CPPTest::ClassDemo::Test {

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ClassDemo, ObjectAssignment) {
  Foo foo_obj{};
  const Bar bar_obj{};

  const std::string expected_result_foo = "hello world Foo";
  const std::string expected_result_bar = "hello world Bar 0 0";
  EXPECT_EQ(expected_result_foo, foo_obj.foobar());
  EXPECT_EQ(expected_result_bar, bar_obj.foobar());

  const Foo foo_obj2{};

  foo_obj = foo_obj2;  // works as expected
  EXPECT_EQ(expected_result_foo, foo_obj.foobar());

  // IFoo abstract_object{};  // compilation error IFoo is an abstract class
  // foo_obj = bar_obj;  // compilation error - no assignment operator
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ClassDemo, PointersCopy) {
  Foo foo_obj{};
  Bar bar_obj{1, 2};

  IFoo* pfoo = &foo_obj;
  IFoo* pbar = &bar_obj;

  const std::string expected_result_foo = "hello world Foo";
  const std::string expected_result_bar = "hello world Bar 1 2";
  EXPECT_EQ(expected_result_foo, pfoo->foobar());
  EXPECT_EQ(expected_result_bar, pbar->foobar());

  pfoo = pbar;  // why does this work? This should work only if I call "clone"
  // // ????????????????
  // EXPECT_NE(expected_result_bar,
  //           pfoo->foobar());  // this should be not equal but they are??
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::ClassDemo::Test
