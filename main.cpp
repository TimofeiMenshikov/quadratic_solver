/*!
\file
main program with int main() function inside
*/


#include "quad_solver.h"


int main()
{
    #ifdef TEST
        test();
    #else
        release();
    #endif

    return 0;
}


void release()
{
    struct Coefficients coefficients;
    struct Solutions solutions;
    //TODO tell me about NaN types
    coef_input(&coefficients);

    assert(!isnan(coefficients.a));
    assert(!isnan(coefficients.b));
    assert(!isnan(coefficients.c));

    solutions.number = solve_equation(&coefficients, solutions.arr);

    assert(solutions.number != INVALID_NUMBER);

    print_solutions(&solutions);
}


void clean_buffer()
{
    while (getchar() != '\n');
}


bool is_equal(double first_number, double second_number)
{
    return (fabs(first_number - second_number) < EPS);
}


int comparison_of_two_numbers(double first_number, double second_number)///comparison of two double numbers with using epsilon
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


bool is_not_inputed(double* one_coef_pointer)
{
    return scanf("%lf", one_coef_pointer) == 0;
}


void one_coef_input(double* one_coef_pointer)
{
    while (is_not_inputed(one_coef_pointer))
    {
        clean_buffer();

#ifdef INPUT_DEBUG

        printf("buffer is cleaned\n");

#endif

    }
}


void coef_input(struct Coefficients* coef_pointer)  /// introduces coefficients. if coefficient is entered incorrectly, calls clean_buffer
{
    printf("enter 3 numbers - coefficients a, b, c in equation: ax^2 + bx + c = 0\n");

    one_coef_input(&(coef_pointer->a));
    printf("a = %f\n", coef_pointer->a);


    one_coef_input(&(coef_pointer->b));
    printf("b = %f\n", coef_pointer->b);

    one_coef_input(&(coef_pointer->c));
    printf("c = %f\n", coef_pointer->c);

    clean_buffer();
}


int solve_equation(struct Coefficients* coef_pointer, double solutions_array[])
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


int solve_linear(struct Coefficients* coef_pointer, double solutions_array[])
{
    int num_of_solutions = INVALID_NUMBER;

    if (!is_equal(coef_pointer->b, 0))
    {
        num_of_solutions = ONE_SOLUTION;
        double x = -coef_pointer->c / coef_pointer->b;
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


int solve_quadratic(struct Coefficients* coef_pointer, double solutions_array[])
{
    int num_of_solutions = INVALID_NUMBER;

    double d = (coef_pointer->b) * (coef_pointer->b) - 4 * (coef_pointer->a) * (coef_pointer->c);

    if (comparison_of_two_numbers(d, 0) == FIRST_IS_BIGGER)
    {
        num_of_solutions = TWO_SOLUTIONS;

        double root_of_d = sqrt(d);

        double x1 = (-coef_pointer->b + root_of_d) / (2 * coef_pointer->a);
        double x2 = (-coef_pointer->b - root_of_d) / (2 * coef_pointer->a);

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

        solutions_array[0] = x;
    }

    return num_of_solutions;
}


void print_solutions(struct Solutions* solutions_pointer)   //displays solutions and their numbers
{
    if (solutions_pointer->number != INF_SOLUTIONS)
    {
        printf("%d solution(s) in real numbers\n", solutions_pointer->number);
    }
    else
    {
        printf("inf solutions in real numbers\n");
    }

    for (int i = 0; i < solutions_pointer->number; i++)
    {
       printf("x%d = %f ", i + 1, solutions_pointer->arr[i]);
    }

    printf("\n");
}


void nulling_coefficients(struct Coefficients* coef_pointer)
{
    coef_pointer->a = NAN;
    coef_pointer->b = NAN;
    coef_pointer->c = NAN;
}


void nulling_answers(struct Solutions* solutions_pointer)
{
    (solutions_pointer->arr)[0] = NAN;
    (solutions_pointer->arr)[0] = NAN;
    solutions_pointer->number = INVALID_NUMBER;
}
