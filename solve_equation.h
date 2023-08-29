#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

int solve_quadratic(const struct Coefficients* coef_pointer, double solutions_array[]);
int solve_linear(const struct Coefficients* coef_pointer, double solutions_array[]);
int solve_equation(const struct Coefficients* coef_pointer, double solutions_array[]);

#endif /* SOLVE_EQUATION_H */