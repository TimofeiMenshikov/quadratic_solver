/*!
\file

the program contains functions called in main.cpp to test the quadratic equation solver
*/


#include <stdio.h>
#include <math.h>

#include "quad_solver.h"
#include "color_cmd.h"
#include "my_assert.h"
#include "solve_equation.h"
#include "input.h"
#include "print.h"
#include "number_comparison.h"
#include "reinit.h"


int test()  ///test run
{   

    FILE* inputfile;

    MY_ASSERT(((inputfile = fopen("input.txt", "r")) != NULL), FILE_IS_NOT_OPENED);

    struct Coefficients coefficients; // a, b, c
    struct Solutions solutions;
    struct Solutions right_solutions;

    bool is_passed = false;

    int number_of_tests = 0;

    fscanf(inputfile, "%d", &number_of_tests);

    printf("number of tests: %d\n", number_of_tests);

    MY_ASSERT((number_of_tests != 0), FILE_IS_EMPTY);

    for (int test_number = 1; test_number <= number_of_tests; test_number++)
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
    return NO_ERROR;
}


bool check_solver(const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer)    /// checks solutions and their number with standards read from a file
{
    if (solutions_pointer->number != right_solutions_pointer->number)
    {
        printf("\nthe number of solutions is wrong\n");
        return false;
    }

    DEBUG_EXEC(printf("the number of solutions is correct\n"));
    
    return check_answers(solutions_pointer, right_solutions_pointer);
}


bool check_answers(const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer)   /// compares an array of solutions with a benchmark read from a file.
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


void print_test(const bool is_passed, const int test_number, const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer, const struct Coefficients* coef_pointer) /// if the test is passed, notifies about it. Сalls print_test_info for test details if it fails
{
    printf("test %d: ", test_number);

    if (is_passed)
    {
        colored_print("OK\n", light_green);

        printf("equation: %f * x^2 + %f * x + %f = 0\n", coef_pointer->a, coef_pointer->b, coef_pointer->c);
    }
    else
    {
        colored_print("failed\n", red);

        printf("equation: %f * x^2 + %f * x + %f = 0\n", coef_pointer->a, coef_pointer->b, coef_pointer->c);

        print_test_info(solutions_pointer, right_solutions_pointer);
    }

    printf("\n");
}


void print_test_info(const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer)/// Detailed information about the test. Calls the print_solutions function from main.cpp
{
    printf("right answers:\n");
    print_solutions(right_solutions_pointer);

    printf("computer answers:\n");
    print_solutions(solutions_pointer);
}

 
