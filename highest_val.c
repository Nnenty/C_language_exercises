#include <stdio.h>

int max_val(int[], int);

int main(void)
{
    int array[6] = {1, 2, 3, 4, 5, 6};

    printf("%d\n", max_val(array, 6));
}
int max_val(int arr[], int size)
{
    int max = arr[0];
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}
