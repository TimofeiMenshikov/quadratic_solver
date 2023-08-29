#include <stdio.h>
#include <math.h>
#include "number_comparison.h"


bool is_equal(const double first_number, const double second_number) ///checks if two numbers are equal
{
    return (fabs(first_number - second_number) < EPS);
}


int comparison_of_two_numbers(const double first_number, const double second_number) ///comparison of two double numbers with using epsilon
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