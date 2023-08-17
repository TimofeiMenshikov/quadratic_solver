#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#define EPS 0.0000001

enum number_of_solutions{inf_solutions = -1, zero_solutions, one_solution, two_solutions};


void initialization(double *coefficients);
void print_solutions(double *solutions, int num_of_solutions);
int solve_quadratic(double *coefficients, double *solutions);
int main()
{

    double coefficients[3] = {0.0, 0.0, 0.0}; // a, b, c
    double solutions[2] = {0.0, 0.0}; // x1, x2

    int num_of_solutions = 0;

    initialization(coefficients);
    num_of_solutions = solve_quadratic(coefficients, solutions);

    print_solutions(solutions, num_of_solutions);

    return 0;
}




void initialization(double *coefficients)
{
    int num_of_coefficients = 0;

    while (num_of_coefficients != 3)
    {
        num_of_coefficients = scanf("%lf %lf %lf", &coefficients[0], &coefficients[1], &coefficients[2]) ;

    }


}


int solve_quadratic(double *coefficients, double *solutions)
{
    int num_of_solutions = 0;

    double a = coefficients[0];

    double b = coefficients[1];

    double c = coefficients[2];

    if (a == 0)
    {
        num_of_solutions = one_solution;
        double x = - c / b;
        solutions[0] = x;

    }
    else
    {
        double d = b * b - 4 * a * c;

        if (d > EPS)
        {
            num_of_solutions = two_solutions;
            double root_of_d = sqrt(d);
            double x1 = (-b + root_of_d) / (2 * a);
            double x2 = (-b - root_of_d) / (2 * a);

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

            double x = -b / (2  * a);

            solutions[0] = x;
        }
    }
    return num_of_solutions;
}

void print_solutions(double *solutions, int num_of_solutions)
{
    printf("%d solution(s) in real numbers\n", num_of_solutions);


    for (int i = 0; i < num_of_solutions; i++)
    {
       printf("x%d = %f ", i + 1, solutions[i]);
    }

}
