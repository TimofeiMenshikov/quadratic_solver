/*!
\file
contains functions for assigning invalid values to variables
*/

#include <math.h>
#include "reinit.h"
#include "quad_solver.h"

void nulling_coefficients(struct Coefficients* coef_pointer)  ///turns coefficients a, b, c into NAN
{
    coef_pointer->a = NAN;
    coef_pointer->b = NAN;
    coef_pointer->c = NAN;
}


void nulling_answers(struct Solutions* solutions_pointer) ///turns solutions x1, x2 into NAN
{
    (solutions_pointer->arr)[0] = NAN;
    (solutions_pointer->arr)[0] = NAN;
    solutions_pointer->number = INVALID_NUMBER;
}
