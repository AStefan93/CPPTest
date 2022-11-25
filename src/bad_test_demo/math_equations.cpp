#include "math_equations.hpp"

namespace CPPTest::math_equations {

int linear_equation(const int argument, equation_coefficients coefficients) {
  return coefficients.product * argument + coefficients.summing;
}

// int MathEquations::sum(const int argument, const int coefficient) {
//   return argument + coefficient;
// }

// int MathEquations::multiply(const int argument, const int coefficient) {
//   return argument * coefficient;
// }

// int linear_equation(const int argument, equation_coefficients coefficients) {
//   const auto prd = MathEquations::multiply(argument, coefficients.product);
//   const auto result = MathEquations::sum(prd, coefficients.summing);
//   return result;
// }

}  // namespace CPPTest::math_equations