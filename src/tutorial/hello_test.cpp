#include "hello.hpp"

#include "gtest/gtest.h"

namespace CPPTest::Tutorial::Test {
// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Tutorial, HelloWorldTest) {
  EXPECT_EQ(Hello::hello_world(), "Hello world!");
}
}  // namespace CPPTest::Tutorial::Test