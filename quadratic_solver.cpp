#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#define EPS 0.0000001
#define MAXSTR 1000

#define TEST

enum number_of_solutions{inf_solutions = -1, zero_solutions = 0, one_solution = 1, two_solutions = 2};

struct Coefficients
{
    double a;
    double b;
    double c;
};


void test();
struct Coefficients coef_input_from_file(struct Coefficients coefficients, FILE* inputfile);
struct Coefficients coef_input(struct Coefficients coefficients);
void print_solutions(double* solutions, int num_of_solutions);
int solve_quadratic(struct Coefficients coefficients, double* solutions);
int solve_linear(struct Coefficients coefficients, double* solutions);
int solve_equation(struct Coefficients coefficients, double* solutions);
bool print_test(int test_number, int num_of_solutions,int right_num_of_solutions);
int main()
{

    #ifdef TEST
        test();
    #else
        struct Coefficients coefficients = {NAN, NAN, NAN}; // a, b, c
        double solutions[2] = {NAN, NAN}; // x1, x2
        int num_of_solutions = NAN;
        coefficients = coef_input(coefficients);
        num_of_solutions = solve_equation(coefficients, solutions);
        print_solutions(solutions, num_of_solutions);
    #endif

    return 0;
}


struct Coefficients coef_input_from_file(struct Coefficients coefficients, FILE* inputfile)
{
    fscanf(inputfile, "%lf %lf %lf", &coefficients.a, &coefficients.b, &coefficients.c);



    return coefficients;
}


struct Coefficients coef_input(struct Coefficients coefficients)
{
    printf("введите 3 числа - коэффициенты a, b, c в уравнении ax^2 + bx + c = 0\n");

    int is_scan_coefficient = 0;

    while ((is_scan_coefficient = scanf("%lf", &coefficients.a)) == 0)
    {


        if (is_scan_coefficient == 0)
        {

            scanf("%*s");
        }

    }

    printf("коэффициент a введён\n");

    is_scan_coefficient = 0;

    while ((is_scan_coefficient = scanf("%lf", &coefficients.b)) == 0)
    {
        if (is_scan_coefficient == 0)
        {
            scanf("%*s");
        }
    }

    printf("коэффициет b введён\n");

    is_scan_coefficient = 0;

    while ((is_scan_coefficient = scanf("%lf", &coefficients.c)) == 0)
    {


        if (is_scan_coefficient == 0)
        {
            scanf("%*s");
        }

    }
    printf("коэффициент c введён\n");



    return coefficients;
}


int solve_equation(struct Coefficients coefficients, double* solutions)
{

    int num_of_solutions = 0;

    if (fabs(coefficients.a) < EPS)
    {
        num_of_solutions = solve_linear(coefficients, solutions);

    }
    else
    {
        num_of_solutions = solve_quadratic(coefficients, solutions);
    }

    return num_of_solutions;


}


int solve_linear(struct Coefficients coefficients, double* solutions)
{

    int num_of_solutions = 0;

    if (fabs(coefficients.b) >= EPS)
    {
        num_of_solutions = one_solution;
        double x = - coefficients.c / coefficients.b;
        solutions[0] = x;
    }
    else
    {
        if (fabs(coefficients.c) >= EPS)
        {
            num_of_solutions = zero_solutions;
        }
        else
        {
            num_of_solutions = inf_solutions;
        }
    }

    return num_of_solutions;

}


int solve_quadratic(struct Coefficients coefficients, double* solutions)
{

    int num_of_solutions = 0;

    double d = coefficients.b * coefficients.b - 4 * coefficients.a * coefficients.c;

    if (d > EPS)
    {
        num_of_solutions = two_solutions;

        double root_of_d = sqrt(d);

        double x1 = (-coefficients.b + root_of_d) / (2 * coefficients.a);
        double x2 = (-coefficients.b - root_of_d) / (2 * coefficients.a);

        solutions[0] = x1;
        solutions[1] = x2;
    }
    else if (d < -EPS)
    {
        num_of_solutions = zero_solutions;
    }
    else
    {
        num_of_solutions = one_solution;

        double x = -coefficients.b / (2  * coefficients.a);

        solutions[0] = x;
    }

    return num_of_solutions;
}


void print_solutions(double* solutions, int num_of_solutions)
{
    if (num_of_solutions != inf_solutions)
    {
        printf("%d solution(s) in real numbers\n", num_of_solutions);
    }
    else
    {
        printf("inf solutions in real numbers");
    }

    for (int i = 0; i < num_of_solutions; i++)
    {
       printf("x%d = %f ", i + 1, solutions[i]);
    }

    printf("\n");
}

bool print_test(int test_number, int num_of_solutions, int right_num_of_solutions)
{
    bool is_passed = (num_of_solutions == right_num_of_solutions);

    printf("test %d: ", test_number);

    if (is_passed)
    {
        printf("OK\n");
    }
    else
    {
        printf("failed\n");
    }

    return is_passed;

}


void test()
{
    FILE* inputfile;
    inputfile = fopen("input.txt", "r");

    int right_num_of_solutions = -2;

    struct Coefficients coefficients = {NAN, NAN, NAN}; // a, b, c

    double solutions[2] = {NAN, NAN}; // x1, x2

    int num_of_solutions = 0;


    int test_number = 0;

    while (fscanf(inputfile, "%lf %lf %lf %d", &coefficients.a, &coefficients.b, &coefficients.c, &right_num_of_solutions) != EOF)
    {
        num_of_solutions = solve_equation(coefficients, solutions);

        test_number++;

        if (print_test(test_number, num_of_solutions, right_num_of_solutions) == false)
        {
            break;
        }
    }
}



