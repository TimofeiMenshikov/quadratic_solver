#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#define EPS 0.0000001

int main()
{
    double a;
    double b;
    double c;  /* a * x**2 + b * x + c = 0 */

    scanf("%lf %lf %lf", &a, &b, &c);



    double d = b * b - 4 * a * c;

    if (d > EPS)
    {
        printf("2 корня в действительных числах\n");

        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);

        printf("x1 = %f, x2 = %f", x1, x2);

    }
    else if (d < -EPS)
    {
        printf("0 корней в действительных числах");
    }
    else
    {
        printf("1 корень в действительных числах\n");

        double x = -b / (2  * a);

        printf("x = %f", x);
    }

    return 0;
}
