#include "classDemo.hpp"

#include "gtest/gtest.h"

namespace CPPTest::ClassDemo::Test {

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ClassDemo, test) { FAIL(); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::ClassDemo::Test
