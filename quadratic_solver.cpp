#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#define EPS 0.0000001

void initialization(double *variables)
{
    int num_of_variables = 0;

    while (num_of_variables != 3)
    {
        num_of_variables = scanf("%lf %lf %lf", &variables[0], &variables[1], &variables[2]) ;
    }
}


int solve(double *variables, double *solutions)
{
    int num_of_solutions = 0;

    double a = variables[0];

    double b = variables[1];

    double c = variables[2];

    if (a == 0)
    {
        num_of_solutions = 1;
        double x = - c / b;
        solutions[0] = x;

    }
    else
    {
        double d = b * b - 4 * a * c;

        if (d > EPS)
        {
            num_of_solutions = 2;
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);

            solutions[0] = x1;
            solutions[1] = x2;


        }
        else if (d < -EPS)
        {
            num_of_solutions = 0;
        }
        else
        {
            num_of_solutions = 1;

            double x = -b / (2  * a);

            solutions[0] = x;
        }
    }
    return num_of_solutions;
}

void print(double *solutions, int num_of_solutions)
{
    if (num_of_solutions == 1)
    {
        printf("1 решение в действительных числах\n");
    }
    else
    {
        printf("%d решений в действительных числах\n", num_of_solutions);
    }

    for (int i = 0; i < num_of_solutions; i++)
    {
       printf("x%d = %f ", i + 1, solutions[i]);
    }

}



int main()
{

    double variables[3] = {0.0, 0.0, 0.0}; // a, b, c
    double solutions[2] = {0.0, 0.0}; // x1, x2

    int num_of_solutions = 0;

    initialization(variables);
    num_of_solutions = solve(variables, solutions);

    print(solutions, num_of_solutions);

    return 0;
}
