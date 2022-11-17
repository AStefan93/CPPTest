#include "math_equations.hpp"

#include <memory>

#include "gtest/gtest.h"

namespace CPPTest::math_equations::Test {

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(MathEquations, InputZero) {
  const int argument = 0;
  equation_coefficients coefficients{1, 0};
  const int expected_result = coefficients.summing;

  const auto actual_result = linear_equation(argument, coefficients);

  EXPECT_EQ(expected_result, actual_result);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(MathEquations, InputNotZero) {
  const int argument = 1;
  equation_coefficients coefficients{3, 2};
  const int expected_result = 5;

  const auto actual_result = linear_equation(argument, coefficients);

  EXPECT_EQ(expected_result, actual_result);
}

// //
// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
// TEST(MathEquations, NotAGoodTestCase) {
//   const int argument = 1;
//   equation_coefficients coefficients{3, 2};
//   const int expected_result = 5;

//   // EXPECT_CALL(sum);
//   // EXPECT_CALL(multiply);

//   const auto actual_result = linear_equation(argument, coefficients);

//   EXPECT_EQ(expected_result, actual_result);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::math_equations::Test
