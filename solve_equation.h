#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

ssize_t solve_equation(const struct Coefficients* const coef_pointer, double* const solutions_array);
ssize_t solve_linear(const struct Coefficients* const coef_pointer, double* const solutions_array);
ssize_t solve_quadratic(const struct Coefficients* const coef_pointer, double* const solutions_array);

#endif /* SOLVE_EQUATION_H */