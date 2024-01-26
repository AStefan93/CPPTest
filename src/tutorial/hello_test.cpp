#include "hello.hpp"

#include "gtest/gtest.h"

namespace CPPTest::Tutorial::Test {
// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(Tutorial, HelloWorldTest) {
  EXPECT_EQ(Hello::hello_world(), "Hello world!");
}

std::string digit_to_string(int value) {
  switch (value) {
  case 0:
    return "0";
  case 1:
    return "1";
  case 2:
    return "2";
  case 3:
    return "3";
  case 4:
    return "4";
  case 5:
    return "5";
  case 6:
    return "6";
  case 7:
    return "7";
  case 8:
    return "8";
  case 9:

  default:
    return "Not a digit";
  }
}

std::string fizzbuzz(int value) {

  std::string output;
  int quotient = value;
  while (quotient > 0) {
    output += digit_to_string(quotient % 10);
    quotient /= 10;
  }
  std::reverse(output.begin(), output.end());
  return output;
}

TEST(Tutorial, ConvertOne) {
  int value = 1;
  std::string expected_value = "1";
  EXPECT_EQ(expected_value, fizzbuzz(value));
}
TEST(Tutorial, ConvertTwo) {
  int value = 2;
  std::string expected_value = "2";
  EXPECT_EQ(expected_value, fizzbuzz(value));
}

TEST(Tutorial, ConvertTen) {
  int value = 10;
  std::string expected_value = "10";
  EXPECT_EQ(expected_value, fizzbuzz(value));
}

TEST(Tutorial, ConvertTwoDigitNumber) {
  int value = 12;
  std::string expected_value = "12";
  EXPECT_EQ(expected_value, fizzbuzz(value));
}

TEST(Tutorial, BigNumber) {
  const int value = 123456;
  std::string expected_value = "123456";
  EXPECT_EQ(expected_value, fizzbuzz(value));
}

// TEST(Tutorial, Fizz) {
//   const int value = 6;
//   std::string expected_value = "Fizz";
//   EXPECT_EQ(expected_value, fizzbuzz(value));
// }

// TEST(Tutorial, Buzz) {
//   const int value = 5;
//   std::string expected_value = "Buzz";
//   EXPECT_EQ(expected_value, fizzbuzz(value));
// }

// TEST(Tutorial, FizzBuzz) {
//   const int value = 15;
//   std::string expected_value = "FizzBuzz";
//   EXPECT_EQ(expected_value, fizzbuzz(value));
// }
} // namespace CPPTest::Tutorial::Test