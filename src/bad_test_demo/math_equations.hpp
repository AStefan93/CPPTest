
namespace CPPTest::math_equations {

// class Equations {
//  public:
//   virtual int add(int argument, int coefficient) const = 0;
//   virtual int multiply(int argument, int coefficient) const = 0;

//   virtual ~Equations() = default;
// };
// class MathEquations : public Equations {
//  public:
//   int add(int argument, int coefficient) const override;
//   int multiply(int argument, int coefficient) const override;
// };

struct equation_coefficients {
  int summing;
  int product;
};
int linear_equation(int argument, equation_coefficients coefficients);
// int linear_equation(const std::shared_ptr<Equations>& equations, int
// argument,
//                     equation_coefficients coefficients);
}  // namespace CPPTest::math_equations