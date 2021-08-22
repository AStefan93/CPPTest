#include "array.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace {
TEST(HelloTest, BasicAssertions) {
  using ::testing::IsEmpty;
  Array empty_array{};
  EXPECT_THAT(empty_array, IsEmpty());
}
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}