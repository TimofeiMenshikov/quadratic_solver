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


#ifdef COLOR_COMANDLINE
    void color_cmd(short unsigned int text_color) ///the following text in the console will be of the specified color
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


int print_error(int error_code) 
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