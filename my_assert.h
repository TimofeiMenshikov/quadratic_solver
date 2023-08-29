#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include "print.h"

#define MY_ASSERT(bool_expression, error_code)      \
if (!bool_expression)                               \
{                                                   \
    printf("line %d %s: ", __LINE__, __FILE__);     \
    print_error(error_code);                        \
    return error_code;                              \
}                                                   
                                                                      
#define ARE_COEFFICIENTS_NAN(coef_pointer)          \
{                                                   \
    MY_ASSERT(!isnan((coef_pointer)->a), ISNAN);    \
    MY_ASSERT(!isnan((coef_pointer)->b), ISNAN);    \
    MY_ASSERT(!isnan((coef_pointer)->c), ISNAN);    \
}  

#endif /* MY_ASSERT_H */
