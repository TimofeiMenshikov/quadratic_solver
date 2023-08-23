#include "quad_solver.h"
#include "quad_solver.cpp"



  // пишется через аргументы командной строки flag -D
#define INPUT_DEBUG

int main()
{
    #ifdef TEST
        test();
    #else
        release();
    #endif

    return 0;
}

//TODO asserts

void release()
{
    struct Coefficients coefficients;  // a, b, c
    struct Solutions solutions;
    //TODO tell me about NaN types
    coef_input(&coefficients);
    solutions.number = solve_equation(&coefficients, solutions.arr);
    print_solutions(&solutions);
}

void test()
{
    FILE* inputfile = fopen("input.txt", "r");

    struct Coefficients coefficients; // a, b, c
    struct Solutions solutions;
    struct Solutions right_solutions;

    bool is_passed = false;

    int number_of_tests = 0;

    fscanf(inputfile, "%d", &number_of_tests);

    assert(isnan(number_of_tests));

    for (int test_number = first_test; test_number <= number_of_tests; test_number++)
    {
        nulling_coefficients(&coefficients);
        nulling_answers(&solutions);
        nulling_answers(&right_solutions);

        input_from_file(&coefficients, &right_solutions, inputfile);

        solutions.number = solve_equation(&coefficients, solutions.arr);

        is_passed = (check_solver(&solutions, &right_solutions));

        print_test(is_passed, test_number, &solutions, &right_solutions, &coefficients);
    }

    fclose(inputfile);
}



void clean_buffer()
{
    while (getchar() != '\n');
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


void coef_input(struct Coefficients* coef_pointer)
{
    printf("введите 3 числа - коэффициенты a, b, c в уравнении ax^2 + bx + c = 0\n");

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


void print_solutions(struct Solutions* solutions_pointer)
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


bool check_answers(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer)
{
    bool is_checked = false;

    int matches = 0;

    for (int solution_number = 0; solution_number < solutions_pointer->number; solution_number++)
    {
        for (int right_solution_number = 0; right_solution_number < right_solutions_pointer->number; right_solution_number++)
        {
            if (is_equal((solutions_pointer->arr)[solution_number], (right_solutions_pointer->arr)[right_solution_number]))
            {
                matches++;
            }
        }
    }
    is_checked = (matches >= solutions_pointer->number);

    return is_checked;
}


bool check_solver(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer)
{
    if (solutions_pointer->number != right_solutions_pointer->number)
    {
        printf("\nне совпало\n");
        return false;
    }
    printf("\nкол-во совпало\n");
    return check_answers(solutions_pointer, right_solutions_pointer);
}


void print_test(bool is_passed, int test_number, struct Solutions* solutions_pointer,  struct Solutions* right_solutions_pointer, struct Coefficients* coef_pointer)
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

        print_test_info(solutions_pointer, right_solutions_pointer);
    }
}


void print_test_info(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer)
{
    printf("right answers:\n");
    print_solutions(right_solutions_pointer);

    printf("computer answers:\n");
    print_solutions(solutions_pointer);
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

void input_from_file(struct Coefficients* coef_pointer, struct Solutions* right_solutions_pointer, FILE* inputfile)
{
    fscanf(inputfile, "%lf %lf %lf %d" , &(coef_pointer->a), &(coef_pointer->b), &(coef_pointer->c), &(right_solutions_pointer->number));

    assert(isnan(coef_pointer->a));
    assert(isnan(coef_pointer->b));
    assert(isnan(coef_pointer->c));
    assert(isnan(right_solutions_pointer->number));

    printf("Scanned coeffs and amount: %lf, %lf, %lf, %lf\n", coef_pointer->a, coef_pointer->b, coef_pointer->c, right_solutions_pointer->number);
    if (right_solutions_pointer->number == TWO_SOLUTIONS)
    {
        fscanf(inputfile, "%lf %lf", &((right_solutions_pointer->arr)[0]), &((right_solutions_pointer->arr)[1]));

#ifdef INPUT_DEBUG

        printf("Scanned two right solutions: %lf, %lf\n", right_solutions_pointer->arr[0], right_solutions_pointer->arr[1]);

#endif

    }
    else if (right_solutions_pointer->number == ONE_SOLUTION)
    {
        fscanf(inputfile, "%lf", &((right_solutions_pointer->arr)[0]));

#ifdef INPUT_DEBUG

        printf("Scanned one right solution: %lf\n", right_solutions_pointer->arr[0]);
    }
    else
    {
        printf("Scanned zero right solutions\n");

#endif

    }
}
