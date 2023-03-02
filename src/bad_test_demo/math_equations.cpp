#include "math_equations.hpp"

namespace CPPTest::math_equations {

int linear_equation(const int argument, equation_coefficients coefficients) {
  return coefficients.product * argument + coefficients.summing;
}

// int MathEquations::add(const int argument, const int coefficient) const {
//   return argument + coefficient;
// }

// int MathEquations::multiply(const int argument, const int coefficient) const
// {
//   return argument * coefficient;
// }

// int linear_equation(const std::shared_ptr<Equations>& equations,
//                     const int argument, equation_coefficients coefficients) {
//   const auto prd = equations->multiply(argument, coefficients.product);
//   const auto result = equations->add(prd, coefficients.summing);
//   return result;
// }

// int linear_equation(const int argument, equation_coefficients coefficients) {
//   const auto prd = MathEquations::multiply(argument, coefficients.product);
//   const auto result = MathEquations::sum(prd, coefficients.summing);
//   return result;
// }

// int linear_equation(const std::shared_ptr<Equations>& /*unused*/,
//                     const int argument, equation_coefficients coefficients) {
//   return coefficients.product * argument + coefficients.summing;
// }

}  // namespace CPPTest::math_equations