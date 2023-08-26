/*!
\file
header file with constants, function declarations, standard includes
*/


#ifndef QUAD_SOLVER_H
#define QUAD_SOLVER_H




#define MY_ASSERT(bool_expression, error_code)      \
if (!bool_expression)                               \
{                                                   \
    printf("line %d %s: ", __LINE__, __FILE__);     \
    return print_error(error_code);                 \
}                                                   
                                                                      

#define ARE_COEFFICIENTS_NAN(coef_pointer)          \
{                                                   \
    MY_ASSERT(!isnan((coef_pointer)->a), ISNAN);    \
    MY_ASSERT(!isnan((coef_pointer)->b), ISNAN);    \
    MY_ASSERT(!isnan((coef_pointer)->c), ISNAN);    \
}                                                   


//#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/// constant for comparison of two numbers
const double EPS = 0.0000001;

enum number_of_solutions  /// defines solution number constants for the solutions.numbrer variable
{
    INF_SOLUTIONS  = -1,
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION   = 1,
    TWO_SOLUTIONS  = 2
};

enum number_comparison    /// constants for comparison_of_two_numbers function
{
    FIRST_IS_LESS = -1,
    EQUAL = 0,
    FIRST_IS_BIGGER = 1
};

enum error_number /// in case of an error, the function outputs an error code
{
    INVALID_NUMBER = -2,
    NO_ERROR = 0,
    ISNAN = 1,
    FILE_IS_NOT_OPENED = 2,
    FILE_IS_EMPTY = 3,
    DIVISION_BY_ZERO = 4
};

struct Coefficients  ///  coefficients of equation ax^2 + bx + c = 0
{
    double a = NAN;  ///< a * x * x
    double b = NAN;  ///< b * x
    double c = NAN;  ///< c
};


struct Solutions /// the structure includes an array of 2 elements - the maximum countable number of solutions to the quadratic equation and the number of solutions, which is equal to one of the number_of_solutions constants
{
    double arr[2] = {NAN, NAN}; ///< This is array of equation solutions

    int number = INVALID_NUMBER; ///< This is number of equation solutions. Uses enum number_of_solutions in quad_solver.h
};


void clean_buffer();

int test();

int release();

void nulling_answers(struct Solutions* solutions_pointer);
void nulling_coefficients(struct Coefficients* coef_pointer);

bool is_equal(double first_number, double second_number);
int comparison_of_two_numbers(double first_number_pointer, double second_number_pointer);

bool is_not_inputed(double* one_coef_pointer);
void one_coef_input(double* one_coef_pointer);
void coef_input(struct Coefficients* coef_pointer);

int input_from_file(struct Coefficients* coef_pointer, struct Solutions* right_solutions_pointer, FILE* inputfile);

int solve_quadratic(struct Coefficients* coef_pointer, double* solutions_array);
int solve_linear(struct Coefficients* coef_pointer, double* solutions);
int solve_equation(struct Coefficients* coef_pointer, double* solutions);

void print_solutions(struct Solutions* solutions_pointer);
void print_test_info(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer);
void print_test(bool is_passed, int test_number, struct Solutions* solutions_pointer,  struct Solutions* right_solutions_pointer, struct Coefficients* coef_pointer);
int print_error(int ERROR_CODE);

bool check_answers(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer);
bool check_solver(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer);

#endif /* QUAD_SOLVER_H */
