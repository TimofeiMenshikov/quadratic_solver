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
#include "functions_with_strings.h"


int main(int argc, char *argv[])
{
    #ifdef COLOR_COMANDLINE
        remove_color_cmd();
    #endif /* COLOR_COMANDLINE */

    char* filename;

    if (argc >= 2)
    {
        filename = argv[1];        
    }
    else
    {
        filename = "input.txt";
    }

    #ifdef TEST
        test(filename);
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




       
     
