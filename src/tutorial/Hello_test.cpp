#include "Hello.hpp"

#include "gtest/gtest.h"

namespace CPPTest::Tutorial::Test {
// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Tutorial, HelloWorldTest) { EXPECT_TRUE(true); }
}  // namespace CPPTest::Tutorial::Test