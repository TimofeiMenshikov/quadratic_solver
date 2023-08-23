/*!
\file

the program contains functions called in main.cpp to test the quadratic equation solver
*/


#include "quad_solver.h"

void test()  ///test run
{
    FILE* inputfile = fopen("input.txt", "r");

    struct Coefficients coefficients; // a, b, c
    struct Solutions solutions;
    struct Solutions right_solutions;

    bool is_passed = false;

    int number_of_tests = 0;

    fscanf(inputfile, "%d", &number_of_tests);

    printf("%d\n", number_of_tests);

    assert(number_of_tests != 0);

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


void input_from_file(struct Coefficients* coef_pointer, struct Solutions* right_solutions_pointer, FILE* inputfile)  ///reads from the file the coefficients a, b, c of the equation ax^2 + bx + c = 0; number of decisions; solution of this equation
{
    fscanf(inputfile, "%lf %lf %lf %d" , &(coef_pointer->a), &(coef_pointer->b), &(coef_pointer->c), &(right_solutions_pointer->number));

    assert(!isnan(coef_pointer->a));
    assert(!isnan(coef_pointer->b));
    assert(!isnan(coef_pointer->c));
    assert(!isnan(right_solutions_pointer->number));
#ifdef INPUT_DEBUG
    printf("Scanned coeffs and amount: %lf, %lf, %lf, %d\n", coef_pointer->a, coef_pointer->b, coef_pointer->c, right_solutions_pointer->number);
#endif
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


void print_test(bool is_passed, int test_number, struct Solutions* solutions_pointer,  struct Solutions* right_solutions_pointer, struct Coefficients* coef_pointer) /// if the test is passed, notifies about it. Сalls print_test_info for test details if it fails
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


void print_test_info(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer)/// Detailed information about the test. Calls the print_solutions function from main.cpp
{
    printf("right answers:\n");
    print_solutions(right_solutions_pointer);

    printf("computer answers:\n");
    print_solutions(solutions_pointer);
}


