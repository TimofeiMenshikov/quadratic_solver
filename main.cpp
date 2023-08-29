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

char* parse_cmd_args(const int argc, const char** argv); ///reads the name of the test file from the cmd arguments

int main(const int argc, const char* argv[])
{
    #ifdef COLOR_COMANDLINE
        remove_color_cmd();
    #endif /* COLOR_COMANDLINE */

    //TODO const char * const filename;

    #ifdef TEST
        char* filename = parse_cmd_args(argc, argv);
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




       
     
