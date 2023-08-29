/*!
\file
functions to input from file or from cmd
*/


#include <stdio.h>
#include <math.h>

#include "input.h"
#include "my_assert.h"
#include "quad_solver.h"

/* cmd args */

const char* parse_cmd_args(const int argc, const char** argv)
{
    const char* filename;

    if (argc >= 2) 
    {
        filename = argv[1];        
    }
    else
    {
        filename = "input.txt"; 
    }

    return filename;
}



/* from file */
int input_from_file(struct Coefficients* coef_pointer, struct Solutions* right_solutions_pointer, FILE* inputfile)  ///reads from the file the coefficients a, b, c of the equation ax^2 + bx + c = 0; number of decisions; solution of this equation
{
    fscanf(inputfile, "%lf %lf %lf %d" , &(coef_pointer->a), &(coef_pointer->b), &(coef_pointer->c), &(right_solutions_pointer->number));

    ARE_COEFFICIENTS_NAN(coef_pointer); 

    DEBUG_EXEC(printf("Scanned coeffs and amount: %lf, %lf, %lf, %d\n", coef_pointer->a, coef_pointer->b, coef_pointer->c, right_solutions_pointer->number));
    
    if (right_solutions_pointer->number == TWO_SOLUTIONS)
    {
        fscanf(inputfile, "%lf %lf", &((right_solutions_pointer->arr)[0]), &((right_solutions_pointer->arr)[1]));

        DEBUG_EXEC(printf("Scanned two right solutions: %lf, %lf\n", right_solutions_pointer->arr[0], right_solutions_pointer->arr[1]));
    }
    else if (right_solutions_pointer->number == ONE_SOLUTION)
    {
        fscanf(inputfile, "%lf", &((right_solutions_pointer->arr)[0]));

        DEBUG_EXEC(printf("Scanned one right solution: %lf\n", right_solutions_pointer->arr[0]));
    }
    else
    {
        DEBUG_EXEC(printf("Scanned zero right solutions\n"));
    }

    return 0;
}


/* from cmd */
void coef_input(struct Coefficients* coef_pointer)  /// introduces coefficients. if coefficient is entered incorrectly, calls clean_buffer
{
    printf("enter 3 numbers - coefficients a, b, c in equation: ax^2 + bx + c = 0\n");

    one_coef_input(&(coef_pointer->a));
    printf("a = %f\n", coef_pointer->a);

    one_coef_input(&(coef_pointer->b));
    printf("b = %f\n", coef_pointer->b);

    one_coef_input(&(coef_pointer->c));
    printf("c = %f\n", coef_pointer->c);

    clean_buffer();
}


void one_coef_input(double* one_coef_pointer) ///a function for entering one coefficient with a check for the correctness of the input
{
    while (is_not_inputed(one_coef_pointer))
    {
        clean_buffer();

        #ifdef INPUT_DEBUG

            printf("buffer is cleaned\n");

        #endif /* INPUT_DEBUG */
    }
}


bool is_not_inputed(double* one_coef_pointer) ///returns true if scanf did not work correctly
{
    return scanf("%lf", one_coef_pointer) == 0;
}


void clean_buffer()  ///clears the input stream until the end of line character
{
    while (getchar() != '\n');
}





