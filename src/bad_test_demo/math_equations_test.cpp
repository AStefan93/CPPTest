#include "math_equations.hpp"

#include <memory>

#include "gtest/gtest.h"

namespace CPPTest::math_equations::Test {

// class MockMathEquations : public Equations {
//  public:
//   MOCK_METHOD(int, add, (int argument, int coefficient), (const, override));
//   MOCK_METHOD(int, multiply, (int argument, int coefficient),
//               (const, override));
// };

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(MathEquations, InputZero) {
  constexpr int argument = 0;
  const equation_coefficients coefficients{0, 0};

  constexpr int expected_result = 0;
  const auto actual_result = linear_equation(argument, coefficients);

  EXPECT_EQ(expected_result, actual_result);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(MathEquations, InputNotZero) {
  constexpr int argument = 1;
  const equation_coefficients coefficients{3, 2};

  constexpr int expected_result = 5;
  const auto actual_result = linear_equation(argument, coefficients);

  EXPECT_EQ(expected_result, actual_result);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
// TEST(MathEquations, NewTestCase) {
//   const int argument = 1;
//   equation_coefficients coefficients{3, 2};
//   const int expected_result = 5;

//   using ::testing::_;
//   using ::testing::Return;
//   const auto equations = std::make_shared<MockMathEquations>();
//   EXPECT_CALL(*equations, multiply(_, _))
//       .WillOnce(Return(argument * coefficients.product));
//   EXPECT_CALL(*equations, add(_, _)).WillOnce(Return(expected_result));

//   const auto actual_result = linear_equation(equations, argument,
//   coefficients);

//   EXPECT_EQ(expected_result, actual_result);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::math_equations::Test
