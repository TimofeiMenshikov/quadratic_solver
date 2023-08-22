#include "quad_solver.h"

#define TEST


int main()
{
    #ifdef TEST
        test();
    #else
        struct Coefficients coefficients = {NAN, NAN, NAN}; // a, b, c
        double solutions[2] = {NAN, NAN}; // x1, x2
        int num_of_solutions = NAN;
        coef_input(&coefficients);
        num_of_solutions = solve_equation(&coefficients, solutions);
        print_solutions(solutions, num_of_solutions);
    #endif

    return 0;
}


bool is_equal(double first_number, double second_number)
{
    return (fabs(first_number - second_number) < EPS);
}


int comparison_of_two_numbers(double first_number, double second_number)
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


void coef_input_from_file(struct Coefficients* coef_pointer, FILE* inputfile)
{
    fscanf(inputfile, "%lf %lf %lf", &(coef_pointer->a) , &(coef_pointer->b), &(coef_pointer->c));
}


void coef_input(struct Coefficients* coef_pointer)
{
    printf("введите 3 числа - коэффициенты a, b, c в уравнении ax^2 + bx + c = 0\n");

    int is_scan_coefficient = 0;

    while ((is_scan_coefficient = scanf("%lf", &(coef_pointer->a))) == 0)
    {
        if (is_scan_coefficient == 0)
        {
            scanf("%*s");
        }
    }

    printf("коэффициент a введён\n");

    is_scan_coefficient = 0;

    while ((is_scan_coefficient = scanf("%lf", &(coef_pointer->b))) == 0)
    {
        if (is_scan_coefficient == 0)
        {
            scanf("%*s");
        }
    }

    printf("коэффициет b введён\n");

    is_scan_coefficient = 0;

    while ((is_scan_coefficient = scanf("%lf", &(coef_pointer->c))) == 0)
    {
        if (is_scan_coefficient == 0)
        {
            scanf("%*s");
        }
    }
    printf("коэффициент c введён\n");
}


int solve_equation(struct Coefficients* coef_pointer, double* solutions)
{

    int num_of_solutions = INVALID_NUMBER;

    if (is_equal(coef_pointer->a, 0))
    {
        num_of_solutions = solve_linear(coef_pointer, solutions);

    }
    else
    {
        num_of_solutions = solve_quadratic(coef_pointer, solutions);
    }

    return num_of_solutions;
}


int solve_linear(struct Coefficients* coef_pointer, double* solutions)
{
    int num_of_solutions = INVALID_NUMBER;

    if (!is_equal(coef_pointer->b, 0))
    {
        num_of_solutions = ONE_SOLUTION;
        double x = -coef_pointer->c / coef_pointer->b;
        solutions[0] = x;
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


int solve_quadratic(struct Coefficients* coef_pointer, double* solutions)
{
    int num_of_solutions = INVALID_NUMBER;

    double d = (coef_pointer->b) * (coef_pointer->b) - 4 * (coef_pointer->a) * (coef_pointer->c);

    if (comparison_of_two_numbers(d, 0) == FIRST_IS_BIGGER)
    {
        num_of_solutions = TWO_SOLUTIONS;

        double root_of_d = sqrt(d);

        double x1 = (-coef_pointer->b + root_of_d) / (2 * coef_pointer->a);
        double x2 = (-coef_pointer->b - root_of_d) / (2 * coef_pointer->a);

        solutions[0] = x1;
        solutions[1] = x2;
    }
    else if (comparison_of_two_numbers(d, 0) == FIRST_IS_LESS)
    {
        num_of_solutions = ZERO_SOLUTIONS;
    }
    else
    {
        num_of_solutions = ONE_SOLUTION;

        double x = -coef_pointer->b / (2  * coef_pointer->a);

        solutions[0] = x;
    }

    return num_of_solutions;
}


void print_solutions(double* solutions, int num_of_solutions)
{
    if (num_of_solutions != INF_SOLUTIONS)
    {
        printf("%d solution(s) in real numbers\n", num_of_solutions);
    }
    else
    {
        printf("inf solutions in real numbers\n");
    }

    for (int i = 0; i < num_of_solutions; i++)
    {
       printf("x%d = %f ", i + 1, solutions[i]);
    }

    printf("\n");
}


bool check_answers(double* solutions, double* right_answers, int num_of_solutions)
{
    bool is_checked = false;

    int matches = 0;

    for (int i = 0; i < num_of_solutions; i++)
    {
        for (int j = 0; j < num_of_solutions; j++)
        {
            if (comparison_of_two_numbers(solutions[i], right_answers[j]) == EQUAL)
            {
                matches++;
            }
        }
    }
    is_checked = (matches >= num_of_solutions);

    return is_checked;
}


bool check_solver(double *solutions, double *right_answers, int num_of_solutions, int right_num_of_solutions)
{
    if (num_of_solutions != right_num_of_solutions)
    {
        printf("\nне совпало\n");
        return false;
    }
    printf("\nкол-во совпало\n");
    return check_answers(solutions, right_answers, num_of_solutions);
}


void print_test(bool is_passed, int test_number, int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers, struct Coefficients* coef_pointer)
{
    printf("test %d: ", test_number);

    if (is_passed)
    {
        printf("OK\n");
        printf("equation: %f * x^2 + %f * x + %f = 0\n", coef_pointer->a, coef_pointer->b, coef_pointer->c);
    }
    else
    {
        printf("failed\n");
        printf("equation: %f * x^2 + %f * x + %f = 0\n", coef_pointer->a, coef_pointer->b, coef_pointer->c);

        print_test_info(num_of_solutions, solutions, right_num_of_solutions, right_answers);
    }
}


void print_test_info(int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers)
{
        printf("right answers:\n");

        if (num_of_solutions != INF_SOLUTIONS)
        {
            printf("%d solution(s) in real numbers\n", num_of_solutions);
        }
        else
        {
            printf("inf solutions in real numbers\n");
        }

        for (int i = 0; i < num_of_solutions; i++)
        {
           printf("x%d = %f ", i + 1, right_answers[i]);
        }

        printf("\n");

        printf("computer answers:\n");

        if (num_of_solutions != INF_SOLUTIONS)
        {
            printf("%d solution(s) in real numbers\n", num_of_solutions);
        }
        else
        {
            printf("inf solutions in real numbers\n");
        }

        for (int i = 0; i < num_of_solutions; i++)
        {
           printf("x%d = %f ", i + 1, solutions[i]);
        }

        printf("\n");
}


void nulling_coefficients(struct Coefficients* coef_pointer)
{
    coef_pointer->a = NAN;
    coef_pointer->b = NAN;
    coef_pointer->c = NAN;
}


void nulling_answers(double* solutions)
{
    solutions[0] = NAN;
    solutions[1] = NAN;
}


void test()
{
    FILE* inputfile;
    inputfile = fopen("input.txt", "r");

    int right_num_of_solutions = INVALID_NUMBER;
    int num_of_solutions = INVALID_NUMBER;

    struct Coefficients coefficients = {NAN, NAN, NAN}; // a, b, c

    double solutions[2] = {NAN, NAN}; // x1, x2
    double right_answers[2] = {NAN, NAN}; //x1, x2

    int test_number = 0;

    bool is_passed = false;

    char coef_string[MAXSTR];

    char answers_string[MAXSTR];

    while (true)
    {
        fgets(coef_string, MAXSTR, inputfile);

        nulling_coefficients(&coefficients);
        nulling_answers(solutions);
        nulling_answers(right_answers);

        num_of_solutions = INVALID_NUMBER;
        right_num_of_solutions = INVALID_NUMBER;

        sscanf(coef_string, "%lf %lf %lf %d" , &coefficients.a, &coefficients.b, &coefficients.c, &right_num_of_solutions);

        num_of_solutions = solve_equation(&coefficients, solutions);

        if (fgets(answers_string, MAXSTR, inputfile) == NULL)
        {
            break;
        }

        if (right_num_of_solutions == TWO_SOLUTIONS)
        {
            sscanf(answers_string, "%lf %lf", &right_answers[0], &right_answers[1]);
        }
        else if (right_num_of_solutions == ONE_SOLUTION)
        {
            sscanf(answers_string, "%lf", &right_answers[0], &right_answers[1]);
        }

        test_number++;

        is_passed = (check_solver(solutions, right_answers, num_of_solutions, right_num_of_solutions));

        print_test(is_passed, test_number, num_of_solutions, solutions, right_num_of_solutions, right_answers, &coefficients);
    }
}
