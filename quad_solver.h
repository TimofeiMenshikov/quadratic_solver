/*!
\file
header file with constants, function declarations, standard includes
*/


#ifndef QUAD_SOLVER_H
#define QUAD_SOLVER_H



enum number_of_solutions  /// defines solution number constants for the solutions.numbrer variable
{
    INF_SOLUTIONS  = -1,
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION   = 1,
    TWO_SOLUTIONS  = 2
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

int test(const char* filename);

int release();

bool check_answers(const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer);
bool check_solver(const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer);

#endif /* QUAD_SOLVER_H */
