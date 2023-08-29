/*!
\file
functions to print user, test information
colored text is supported 
*/

#include <stdio.h>
#include <math.h>

#include "quad_solver.h"
#include "color_cmd.h"
#include "print.h"


void print_solutions(const struct Solutions* solutions_pointer)   ///displays solutions and their numbers
{
    if (solutions_pointer->number != INF_SOLUTIONS)
    {
        printf("%d solution(s) in real numbers\n", solutions_pointer->number);
    }
    else
    {
        printf("inf solutions in real numbers\n");
    }

    for (int i = 0; i < solutions_pointer->number; i++)
    {
       printf("x%d = %f ", i + 1, solutions_pointer->arr[i]);
    }

    printf("\n");
}


/* color cmd*/
#ifdef COLOR_COMANDLINE
    void color_cmd(const short unsigned int text_color) ///the following text in the console will be of the specified color
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color);
    }

    void remove_color_cmd() /// the following text in the console will be white    
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  white); 
    }

#endif /* COLOR_COMANDLINE */


void colored_print(const char* text, short unsigned int text_color  /* COLOR_COMANDLINE*/) /// can make text color, but does not work with variables
{   
    #ifdef COLOR_COMANDLINE
        color_cmd(text_color);
    #endif /* COLOR_COMANDLINE */

    printf("%s", text);

    #ifdef COLOR_COMANDLINE
        remove_color_cmd();
    #endif /* COLOR_COMANDLINE */
}


/* assert */
int print_error(const int error_code)   /// function, that helps my_assert print error_code
{                   
    switch(error_code) 
    {                           
        case INVALID_NUMBER:                       
            printf("invalid int value\n");         
            return INVALID_NUMBER; // TODO remove                 
        case ISNAN:                                
            printf("invalid double value\n");      
            return ISNAN;                          
        case FILE_IS_NOT_OPENED:                   
            printf("file is not opened\n");        
            return FILE_IS_NOT_OPENED;             
        case FILE_IS_EMPTY:                        
            printf("cannot read from file\n");     
            return FILE_IS_EMPTY;                  
        case DIVISION_BY_ZERO:                     
            printf("division by zero\n");          
            return INVALID_NUMBER;                 
        default:                                   
            return NO_ERROR;       
    }
}      


/* test */
void print_test(const bool is_passed, const int test_number, const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer, const struct Coefficients* coef_pointer) /// if the test is passed, notifies about it. Сalls print_test_info for test details if it fails
{
    printf("test %d: ", test_number);

    if (is_passed)
    {
        colored_print("OK\n", light_green);

        printf("equation: %f * x^2 + %f * x + %f = 0\n", coef_pointer->a, coef_pointer->b, coef_pointer->c);
    }
    else
    {
        colored_print("failed\n", red);

        printf("equation: %f * x^2 + %f * x + %f = 0\n", coef_pointer->a, coef_pointer->b, coef_pointer->c);

        print_test_info(solutions_pointer, right_solutions_pointer);
    }

    printf("\n");
}


void print_test_info(const struct Solutions* solutions_pointer, const struct Solutions* right_solutions_pointer)/// Detailed information about the test. Calls the print_solutions function from main.cpp
{
    printf("right answers:\n");
    print_solutions(right_solutions_pointer);

    printf("computer answers:\n");
    print_solutions(solutions_pointer);
}
