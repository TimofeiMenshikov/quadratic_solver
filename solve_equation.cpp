/*!
\file
contains functions to solve equatations: ax^2 + bx + c = 0; bx + c = 0
*/

#include <stdio.h>
#include <math.h>

#include "quad_solver.h"
#include "my_assert.h"
#include "solve_equation.h"
#include "number_comparison.h"

int solve_equation(const struct Coefficients* coef_pointer, double solutions_array[]) /// solves equatation ax^2 + bx + c = 0
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


int solve_linear(const struct Coefficients* coef_pointer, double solutions_array[]) /// solves equatation bx + c = 0
{
    int num_of_solutions = INVALID_NUMBER;

    if (!is_equal(coef_pointer->b, 0))
    {
        num_of_solutions = ONE_SOLUTION;
        double x = -coef_pointer->c / coef_pointer->b;

        MY_ASSERT(!isinf(x), DIVISION_BY_ZERO);

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


int solve_quadratic(const struct Coefficients* coef_pointer, double solutions_array[]) ///solves equatation ax^2 + bx + c = 0 (a != 0)
{
    int num_of_solutions = INVALID_NUMBER;

    double d = (coef_pointer->b) * (coef_pointer->b) - 4 * (coef_pointer->a) * (coef_pointer->c);

    if (comparison_of_two_numbers(d, 0) == FIRST_IS_BIGGER)
    {
        num_of_solutions = TWO_SOLUTIONS;

        double root_of_d = sqrt(d);

        double x1 = (-coef_pointer->b + root_of_d) / (2 * coef_pointer->a);
        double x2 = (-coef_pointer->b - root_of_d) / (2 * coef_pointer->a);

        MY_ASSERT(!isinf(x1), DIVISION_BY_ZERO);
        MY_ASSERT(!isinf(x2), DIVISION_BY_ZERO);

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

        MY_ASSERT(!isinf(x), DIVISION_BY_ZERO);

        solutions_array[0] = x;
    }

    return num_of_solutions;
}