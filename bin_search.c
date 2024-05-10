#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize_array(int *arr, int arr_size);
bool search_element(int *arr, int arr_size, int element);
int pow_count(int *arr, int arr_sizes);

int main(void)
{
    int arr_size = 123;
    int arr[arr_size];
    initialize_array(arr, arr_size);

    int usrinp;

    puts("Enter the number you want to find in the integer array:");
    scanf("%d", &usrinp);
    while (getchar() != '\n')
    {
    }

    printf("%d is %s array\n", usrinp,
           (search_element(arr, arr_size, usrinp) == true) ? "in the" : "not in");

    return 0;
}
void initialize_array(int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = i + 1;
    }
}
bool search_element(int *arr, int arr_size, int element)
{
    int max_iterations = pow_count(arr, arr_size) + 1;

    int mid_index = (arr_size - 1) / 2;
    int l_index = 0;
    int r_index = arr_size - 1;

    for (int i = 0; i < max_iterations; i++)
    {
        if (element == arr[arr_size - 1])
        {
            return true;
        }
        if (element == arr[mid_index])
        {
            return true;
        }
        else if (element > arr[mid_index])
        {
            l_index = mid_index;
            mid_index = (l_index + r_index) / 2;
        }
        else if (element < arr[mid_index])
        {
            r_index = mid_index;
            mid_index = (r_index + l_index) / 2;
        }
    }

    return false;
}
int pow_count(int *arr, int arr_size)
{
    int num = arr_size;
    int pow_count = 0;

    while (1)
    {
        num = num / 2;
        pow_count++;

        if (num == 1)
        {
            break;
        }
        if (pow_count > 50)
        {
            exit(EXIT_FAILURE); // if too much big number
        }
    }

    return pow_count;
}