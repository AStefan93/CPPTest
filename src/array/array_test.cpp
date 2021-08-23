#include "array.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stdexcept>

namespace {
TEST(Array, WhenDefaultConstructorExpectEmptyArray) {
  using ::testing::IsEmpty;
  Array<int> empty_array{};
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

TEST(Array, WhenOutputToStreamExpectNoThrows) {
  constexpr auto size = 5;
  Array array_object{size};
  constexpr auto index = 1;
  constexpr auto test_value{10};
  array_object[index] = test_value;
  EXPECT_NO_THROW(std::cout << array_object << std::endl);
}

TEST(Array, WhenCopyingArrayExpectCorrectValues) {
  constexpr auto size = 5;
  Array array_object1{size};
  Array array_object2{size};
  constexpr auto index = 1;
  constexpr auto test_value1{10};
  constexpr auto test_value2{20};
  array_object1[index] = test_value1;
  array_object2 = array_object1;
  array_object1[index + 1] = test_value1;
  array_object2[index + 1] = test_value2;

  EXPECT_EQ(array_object1[index], array_object2[index]);
  EXPECT_EQ(array_object1[index + 1], test_value1);
  EXPECT_EQ(array_object2[index + 1], test_value2);
}

TEST(Array, WhenMoveConstructingArrayExpectCorrectValues) {
  constexpr auto size = 5;
  Array array_object1{size};
  constexpr auto index = 1;
  constexpr auto test_value1{10};
  constexpr auto test_value2{20};
  array_object1[index] = test_value1;
  auto array_object2{std::move(array_object1)};
  array_object2[index + 1] = test_value2;

  EXPECT_EQ(array_object2[index], test_value1);
  EXPECT_EQ(array_object2[index + 1], test_value2);
}
TEST(Array, WhenMovingByAssignmentArrayExpectCorrectValues) {
  constexpr auto size = 5;
  Array array_object1{size};
  Array array_object2{size};
  constexpr auto index = 1;
  constexpr auto test_value1{10};
  constexpr auto test_value2{20};
  array_object1[index] = test_value1;
  array_object2 = std::move(array_object1);
  array_object2[index + 1] = test_value2;

  EXPECT_EQ(array_object2[index], test_value1);
  EXPECT_EQ(array_object2[index + 1], test_value2);
}
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}