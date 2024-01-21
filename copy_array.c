#include <stdio.h>

double copy_arr(double array[], double copy_array[], int num);
double copy_ptr(double *array, double *copy_array, int num);
double copy_ptrs(double *array, double *start, double *end);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    int i;

    printf("Исходный массив source = ");
    for (i = 0; i < 5; i++)
    {
        printf("%.1lf ", source[i]);
    }
    putchar('\n');
    putchar('\n');

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    printf("Массив target1 = ");
    for (i = 0; i < 5; i++)
    {
        printf("%.1lf ", target1[i]);
    }
    putchar('\n');

    printf("Массив target2 = ");
    for (i = 0; i < 5; i++)
    {
        printf("%.1lf ", target1[i]);
    }
    putchar('\n');

    printf("Массив target3 = ");
    for (i = 0; i < 5; i++)
    {
        printf("%.1lf ", target1[i]);
    }
    putchar('\n');

    return 0;
}
double copy_arr(double array[], double copy_array[], int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        array[i] = copy_array[i];
    }
}
double copy_ptr(double *array, double *copy_array, int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        array[i] = *(copy_array + i);
    }
}
double copy_ptrs(double array[], double start[], double *end)
{
    double *i;

    for (i = start; i < end; i++)
    {
        *array++ = *i;
    }
}
