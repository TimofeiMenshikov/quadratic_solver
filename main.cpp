/*!
\file
main program with int main() function inside
*/

#include <stdio.h>
#include <math.h>

#include "quad_solver.h"
#include "color_cmd.h"
#include "my_assert.h"
#include "input.h"
#include "solve_equation.h"
#include "print.h"


int main()
{
    printf("name of the file is: %s\n", __FILE__);

    #ifdef COLOR_COMANDLINE
        remove_color_cmd();
    #endif /* COLOR_COMANDLINE */

    #ifdef TEST
        test();
    #else /* TEST */
        release();
    #endif /* TEST */

    return 0;
}


int release()
{
    struct Coefficients coefficients;
    struct Solutions solutions;

    coef_input(&coefficients);

    ARE_COEFFICIENTS_NAN(&coefficients);

    solutions.number = solve_equation(&coefficients, solutions.arr);

    MY_ASSERT((solutions.number != INVALID_NUMBER), INVALID_NUMBER);

    print_solutions(&solutions);

    return 0;
}




       
     
