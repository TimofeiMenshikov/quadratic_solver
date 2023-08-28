/*!
\file
main program with int main() function inside
*/

#include "quad_solver.h"
#include "color_cmd.h"

int main()
{
    printf("\n");
    printf("%d\n", __LINE__);
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
    //TODO tell me about NaN types
    coef_input(&coefficients);

    ARE_COEFFICIENTS_NAN(&coefficients);

    solutions.number = solve_equation(&coefficients, solutions.arr);

    MY_ASSERT((solutions.number != INVALID_NUMBER), INVALID_NUMBER);

    print_solutions(&solutions);

    return 0;
}


void clean_buffer()  ///clears the input stream until the end of line character
{
    while (getchar() != '\n');
}


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


bool is_not_inputed(double* one_coef_pointer) ///returns true if scanf did not work correctly
{
    return scanf("%lf", one_coef_pointer) == 0;
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


int solve_equation(const struct Coefficients* coef_pointer, double solutions_array[]) /// solves equatation ax^2 + bx + c = 0
{
    int num_of_solutions = INVALID_NUMBER;

    if (is_equal(coef_pointer->a, 0))
    {
        num_of_solutions = solve_linear(coef_pointer, solutions_array);
    }
    else
    {
        num_of_solutions = solve_quadratic(coef_pointer, solutions_array);
    }

    return num_of_solutions;
}


int solve_linear(const struct Coefficients* coef_pointer, double solutions_array[]) /// solves equatation bx + c = 0
{
    int num_of_solutions = INVALID_NUMBER;

    if (!is_equal(coef_pointer->b, 0))
    {
        num_of_solutions = ONE_SOLUTION;
        double x = -coef_pointer->c / coef_pointer->b;

        MY_ASSERT(!isinf(x), DIVISION_BY_ZERO);

        solutions_array[0] = x;
    }
    else
    {
        if (!is_equal(coef_pointer->c, 0))
        {
            num_of_solutions = ZERO_SOLUTIONS;
        }
        else
        {
            num_of_solutions = INF_SOLUTIONS;
        }
    }

    return num_of_solutions;
}


int solve_quadratic(const struct Coefficients* coef_pointer, double solutions_array[]) ///solves equatation ax^2 + bx + c = 0 (a != 0)
{
    int num_of_solutions = INVALID_NUMBER;

    double d = (coef_pointer->b) * (coef_pointer->b) - 4 * (coef_pointer->a) * (coef_pointer->c);

    if (comparison_of_two_numbers(d, 0) == FIRST_IS_BIGGER)
    {
        num_of_solutions = TWO_SOLUTIONS;

        double root_of_d = sqrt(d);

        double x1 = (-coef_pointer->b + root_of_d) / (2 * coef_pointer->a);
        double x2 = (-coef_pointer->b - root_of_d) / (2 * coef_pointer->a);

        MY_ASSERT(!isinf(x1), DIVISION_BY_ZERO);
        MY_ASSERT(!isinf(x2), DIVISION_BY_ZERO);

        solutions_array[0] = x1;
        solutions_array[1] = x2;
    }
    else if (comparison_of_two_numbers(d, 0) == FIRST_IS_LESS)
    {
        num_of_solutions = ZERO_SOLUTIONS;
    }
    else
    {
        num_of_solutions = ONE_SOLUTION;

        double x = -coef_pointer->b / (2  * coef_pointer->a);

        MY_ASSERT(!isinf(x), DIVISION_BY_ZERO);

        solutions_array[0] = x;
    }

    return num_of_solutions;
}


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
            return INVALID_NUMBER;                 
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
     
