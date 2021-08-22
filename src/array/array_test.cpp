#include "array.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stdexcept>

namespace {
TEST(Array, WhenDefaultConstructorExpectEmptyArray) {
  using ::testing::IsEmpty;
  Array empty_array{};
  EXPECT_THAT(empty_array, IsEmpty());
}

TEST(Array, WhenConstructorWithSizeExpectNonEmptyArray) {
  using ::testing::SizeIs;
  constexpr auto size = 5;
  Array array_object{size};
  EXPECT_THAT(array_object, SizeIs(size));
}
TEST(Array, WhenAssigningValueExpectCorrectValue) {
  constexpr auto size = 5;
  Array array_object{size};
  constexpr auto test_value{10};
  array_object[0] = test_value;
  EXPECT_EQ(array_object[0], test_value);
}

TEST(Array, WhenAssigningValueOutOfBoundsExpectException) {
  constexpr auto size = 5;
  Array array_object{size};
  constexpr auto out_of_bounds_index{size + 1};
  constexpr auto test_value{10};
  EXPECT_THROW(array_object[out_of_bounds_index] = test_value;
               , std::runtime_error);
}
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}