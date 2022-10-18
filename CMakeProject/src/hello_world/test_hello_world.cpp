#include <stdexcept>
#include <utility>

#include "gtest/gtest.h"
#include "hello_world.hpp"

namespace CMakeTest::HelloWorld::Test {

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(HelloWorld, WhenDefaultConstructorExpectEmptyArray) {
  const std::string expected_value = "hello world\n";
  const auto actual_value = fn_hello_world();
  EXPECT_EQ(expected_value, actual_value);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CMakeTest::HelloWorld::Test