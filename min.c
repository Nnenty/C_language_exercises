#include <stdio.h>

double min(int, int);

int main(void)
{
    double a, b;

    scanf("%lf %lf", &a, &b);
    printf("%.1lf %.1lf %.1lf", a, b, min(a, b));

    return 0;
}
double min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}