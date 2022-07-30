#include "array.hpp"

#include <stdexcept>
#include <utility>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace CPPTest::Array::Test {

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Array, WhenDefaultConstructorExpectEmptyArray) {
  using ::testing::IsEmpty;
  Array<int> empty_array{};
  EXPECT_THAT(empty_array, IsEmpty());
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Array, WhenConstructorWithSizeExpectNonEmptyArray) {
  using ::testing::SizeIs;
  constexpr auto size = 5;
  Array array_object{size};
  EXPECT_THAT(array_object, SizeIs(size));
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Array, WhenAssigningValueExpectCorrectValue) {
  constexpr auto size = 5;
  Array array_object{size};
  constexpr auto test_value{10};
  array_object[0] = test_value;
  EXPECT_EQ(array_object[0], test_value);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Array, WhenAssigningValueOutOfBoundsExpectException) {
  constexpr auto size = 5;
  Array array_object{size};
  constexpr auto out_of_bounds_index{size + 1};
  constexpr auto test_value{10};

  // NOLINTNEXTLINE(cppcoreguidelines-avoid-goto)
  EXPECT_THROW(array_object[out_of_bounds_index] = test_value;
               , std::runtime_error);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Array, WhenOutputToStreamExpectNoThrows) {
  constexpr auto size = 5;
  Array array_object{size};
  constexpr auto index = 1;
  constexpr auto test_value{10};
  array_object[index] = test_value;

  // NOLINTNEXTLINE(cppcoreguidelines-avoid-goto)
  EXPECT_NO_THROW(std::cout << array_object << std::endl);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
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

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
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

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Array, WhenMovingByAssignmentArrayExpectCorrectValues) {
  constexpr auto size = 5;
  Array array_object{size};
  Array array_object2{size};
  constexpr auto index = 1;
  constexpr auto test_value1{10};
  constexpr auto test_value2{20};
  array_object[index] = test_value1;
  array_object2 = std::move(array_object);
  array_object2[index + 1] = test_value2;

  EXPECT_EQ(array_object2[index], test_value1);
  EXPECT_EQ(array_object2[index + 1], test_value2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::Array::Test
