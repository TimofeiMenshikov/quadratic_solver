/*!
\file
header file with constants, function declarations, standard includes
*/


//#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

/// constant for comparison of two numbers
const double EPS = 0.0000001;


const int first_test = 1;


enum number_of_solutions
{
    INVALID_NUMBER = -2,
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

struct Coefficients  ///  coefficients of equation ax^2 + bx + c = 0
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};


struct Solutions /// the structure includes an array of 2 elements - the maximum countable number of solutions to the quadratic equation and the number of solutions, which is equal to one of the number_of_solutions constants
{
    double arr[2] = {NAN, NAN};

    int number = INVALID_NUMBER;
};


void clean_buffer();

void test();

void release();

void nulling_answers(struct Solutions* solutions_pointer);
void nulling_coefficients(struct Coefficients* coef_pointer);

bool is_equal(double first_number, double second_number);
int comparison_of_two_numbers(double first_number_pointer, double second_number_pointer);

bool is_not_inputed(double* one_coef_pointer);
void one_coef_input(double* one_coef_pointer);
void coef_input(struct Coefficients* coef_pointer);

void input_from_file(struct Coefficients* coef_pointer, struct Solutions* right_solutions_pointer, FILE* inputfile);

int solve_quadratic(struct Coefficients* coef_pointer, double* solutions_array);
int solve_linear(struct Coefficients* coef_pointer, double* solutions);
int solve_equation(struct Coefficients* coef_pointer, double* solutions);

void print_solutions(struct Solutions* solutions_pointer);
void print_test_info(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer);
void print_test(bool is_passed, int test_number, struct Solutions* solutions_pointer,  struct Solutions* right_solutions_pointer, struct Coefficients* coef_pointer);

bool check_answers(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer);
bool check_solver(struct Solutions* solutions_pointer, struct Solutions* right_solutions_pointer);
