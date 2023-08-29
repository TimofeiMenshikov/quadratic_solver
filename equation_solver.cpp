/*!
\file
contains functinos, that may solve equatations: ax^2 + bx + c = 0; bx + c = 0
*/

#include "quad_solver.h"
#include "color_cmd.h"


int solve_equation(struct Coefficients* coef_pointer, double solutions_array[]) /// solves equatation ax^2 + bx + c = 0
{
    int num_of_solutions = INVALID_NUMBER;

    if (is_equal(coef_pointer->a, 0))
    {
        num_of_solutions = solve_linear(coef_pointer, solutions_array);
    }
    else
    {
        num_of_solutions = solve_quadratic(coef_pointer, solutions_array);
    }

    return num_of_solutions;
}


int solve_linear(struct Coefficients* coef_pointer, double solutions_array[]) /// solves equatation bx + c = 0
{
    int num_of_solutions = INVALID_NUMBER;

    if (!is_equal(coef_pointer->b, 0))
    {
        num_of_solutions = ONE_SOLUTION;
        double x = -coef_pointer->c / coef_pointer->b;

        if (isinf(x))
        {
            colored_print("line 148 main.cpp:\n", red);
            colored_print("division by zero\n", red);
            return INVALID_NUMBER;
        }

        solutions_array[0] = x;
    }
    else
    {
        if (!is_equal(coef_pointer->c, 0))
        {
            num_of_solutions = ZERO_SOLUTIONS;
        }
        else
        {
            num_of_solutions = INF_SOLUTIONS;
        }
    }

    return num_of_solutions;
}


int solve_quadratic(struct Coefficients* coef_pointer, double solutions_array[]) ///solves equatation ax^2 + bx + c = 0 (a != 0)
{
    int num_of_solutions = INVALID_NUMBER;

    double d = (coef_pointer->b) * (coef_pointer->b) - 4 * (coef_pointer->a) * (coef_pointer->c);

    if (comparison_of_two_numbers(d, 0) == FIRST_IS_BIGGER)
    {
        num_of_solutions = TWO_SOLUTIONS;

        double root_of_d = sqrt(d);

        double x1 = (-coef_pointer->b + root_of_d) / (2 * coef_pointer->a);
        double x2 = (-coef_pointer->b - root_of_d) / (2 * coef_pointer->a);

        if (isinf(x1) or isinf(x2))
        {
            colored_print("line 190 main.cpp:\n", red);
            colored_print("division by zero", red);
            return INVALID_NUMBER;
        }

        solutions_array[0] = x1;
        solutions_array[1] = x2;
    }
    else if (comparison_of_two_numbers(d, 0) == FIRST_IS_LESS)
    {
        num_of_solutions = ZERO_SOLUTIONS;
    }
    else
    {
        num_of_solutions = ONE_SOLUTION;

        double x = -coef_pointer->b / (2  * coef_pointer->a);

        if (isinf(x))
        {
            colored_print("line 208 main.cpp:\n", red);
            colored_print("division by zero\n", red);
            return INVALID_NUMBER;
        }

        solutions_array[0] = x;
    }

    return num_of_solutions;
}


bool is_equal(const double first_number, const double second_number) ///checks if two numbers are equal
{
    return (fabs(first_number - second_number) < EPS);
}


int comparison_of_two_numbers(const double first_number, const double second_number) ///comparison of two double numbers with using epsilon
{
    if ((first_number - second_number) > EPS)
    {
        return  FIRST_IS_BIGGER;
    }
    if ((second_number - first_number) > EPS)
    {
        return FIRST_IS_LESS;
    }

    return EQUAL;
}