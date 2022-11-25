
namespace CPPTest::math_equations {

// class MathEquations {
//  public:
//   static int sum(int argument, int coefficient);
//   static int multiply(int argument, int coefficient);
// };

struct equation_coefficients {
  int summing;
  int product;
};
int linear_equation(int argument, equation_coefficients coefficients);
}  // namespace CPPTest::math_equations