#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#define MAXSTR 1000
#define TEST

const double EPS = 0.0000001;

enum number_of_solutions{invalid_number = -2, inf_solutions = -1, zero_solutions = 0, one_solution = 1, two_solutions = 2};

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
void print_test(bool is_passed, int test_number, int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers, struct Coefficients coefficients);
bool check_answers(int num_of_solutions, int right_num_of_solutions, double* solutions, double* right_answers);
bool check_num_of_solutions(int num_of_solutions, int right_num_of_solutions);
bool check_solver(double *solutions, double *right_answers, int num_of_solutions, int right_num_of_solutions);
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

    int num_of_solutions = invalid_number;

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
    int num_of_solutions = invalid_number;

    if (fabs(coefficients.b) >= EPS)
    {
        num_of_solutions = one_solution;
        double x = -coefficients.c / coefficients.b;
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
    int num_of_solutions = invalid_number;

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
        printf("inf solutions in real numbers\n");
    }

    for (int i = 0; i < num_of_solutions; i++)
    {
       printf("x%d = %f ", i + 1, solutions[i]);
    }

    printf("\n");
}


bool check_answers(double* solutions, double* right_answers, int num_of_solutions)
{
    bool is_checked = false;

    int matches = 0;

    for (int i = 0; i < num_of_solutions; i++)
    {
        for (int j = 0; j < num_of_solutions; j++)
        {
            if ((fabs(solutions[i] - right_answers[j])) < EPS)
            {
                matches++;
            }
        }
    }
    is_checked = (matches >= num_of_solutions);

    return is_checked;
}


bool check_num_of_solutions(int num_of_solutions, int right_num_of_solutions)
{
    return (num_of_solutions == right_num_of_solutions);
}


bool check_solver(double *solutions, double *right_answers, int num_of_solutions, int right_num_of_solutions)
{
    if (not check_num_of_solutions(num_of_solutions, right_num_of_solutions))
    {
        return false;
    }

    return check_answers(solutions, right_answers, num_of_solutions);

}


void print_test(bool is_passed, int test_number, int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers, struct Coefficients coefficients)
{
    printf("test %d: ", test_number);

    if (is_passed)
    {
        printf("OK\n");
        printf("equation: %f * x^2 + %f * x + %f = 0\n", coefficients.a, coefficients.b, coefficients.c);
    }
    else
    {
        printf("failed\n");

        printf("equation: %f * x^2 + %f * x + %f = 0\n", coefficients.a, coefficients.b, coefficients.c);

        printf("right answers:\n");

        if (num_of_solutions != inf_solutions)
        {
            printf("%d solution(s) in real numbers\n", num_of_solutions);
        }
        else
        {
            printf("inf solutions in real numbers\n");
        }

        for (int i = 0; i < num_of_solutions; i++)
        {
           printf("x%d = %f ", i + 1, right_answers[i]);
        }

        printf("\n");

        printf("computer answers:\n");

        if (num_of_solutions != inf_solutions)
        {
            printf("%d solution(s) in real numbers\n", num_of_solutions);
        }
        else
        {
            printf("inf solutions in real numbers\n");
        }

        for (int i = 0; i < num_of_solutions; i++)
        {
           printf("x%d = %f ", i + 1, solutions[i]);
        }

        printf("\n");
    }
}


void nulling_coefficients(struct Coefficients* coef_pointer)
{
    coef_pointer -> a = NAN;
    coef_pointer -> b = NAN;
    coef_pointer -> c = NAN;
}


void nulling_answers(double* solutions)
{
    solutions[0] = NAN;
    solutions[1] = NAN;
}


void test()
{
    FILE* inputfile;
    inputfile = fopen("input.txt", "r");

    int right_num_of_solutions = invalid_number;
    int num_of_solutions = invalid_number;

    struct Coefficients coefficients = {NAN, NAN, NAN}; // a, b, c

    double solutions[2] = {NAN, NAN}; // x1, x2
    double right_answers[2] = {NAN, NAN}; //x1, x2




    int test_number = 0;

    bool is_passed = false;

    bool test_end = false;

    char coef_string[MAXSTR];

    char answers_string[MAXSTR];

    while (true)
    {
        fgets(coef_string, MAXSTR, inputfile);

        nulling_coefficients(&coefficients);
        nulling_answers(solutions);
        nulling_answers(right_answers);

        num_of_solutions = invalid_number;
        right_num_of_solutions = invalid_number;

        sscanf(coef_string, "%lf %lf %lf %d" , &coefficients.a, &coefficients.b, &coefficients.c, &right_num_of_solutions);

        num_of_solutions = solve_equation(coefficients, solutions);

        if (fgets(answers_string, MAXSTR, inputfile) == NULL)
        {
            break;
        }

        if (right_num_of_solutions == two_solutions)
        {
            sscanf(answers_string, "%lf %lf", &right_answers[0], &right_answers[1]);
        }
        else if (right_num_of_solutions == one_solution)
        {
            sscanf(answers_string, "%lf", &right_answers[0], &right_answers[1]);
        }

        test_number++;

        is_passed = (check_solver(solutions, right_answers, num_of_solutions, right_num_of_solutions));

        print_test(is_passed, test_number, num_of_solutions, solutions, right_num_of_solutions, right_answers, coefficients);
    }
}
