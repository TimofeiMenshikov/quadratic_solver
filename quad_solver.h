#include <TXLib.h>
#include <stdio.h>
#include <math.h>


#define MAXSTR 1000

const double EPS = 0.0000001;

struct Coefficients
{
    double a;
    double b;
    double c;
};

enum number_of_solutions
{
    INVALID_NUMBER = -2,
    INF_SOLUTIONS  = -1,
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION   = 1,
    TWO_SOLUTIONS  = 2
};

enum number_comparison
{
    FIRST_IS_LESS = -1,
    EQUAL = 0,
    FIRST_IS_BIGGER = 1
};

void test();

bool is_equial(double first_number, double second_number);
int comparison_of_two_numbers(double first_number_pointer, double second_number_pointer);

void coef_input_from_file(struct Coefficients* coef_pointer, FILE* inputfile);
void coef_input(struct Coefficients* coef_pointer);

void print_solutions(double* solutions, int num_of_solutions);

int solve_quadratic(struct Coefficients* coef_pointer, double* solutions);
int solve_linear(struct Coefficients* coef_pointer, double* solutions);
int solve_equation(struct Coefficients* coef_pointer, double* solutions);

void print_test_info(int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers);
void print_test(bool is_passed, int test_number, int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers, struct Coefficients* coef_pointer);

bool check_answers(int num_of_solutions, int right_num_of_solutions, double* solutions, double* right_answers);
bool check_solver(double *solutions, double *right_answers, int num_of_solutions, int right_num_of_solutions);
