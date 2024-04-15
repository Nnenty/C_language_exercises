#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void randindex(int arr[], int size, int index_amount);
void show_indexes(int arr[], int index_array[], int indxarr_size);
void index_sort(int index_array[], int indxarr_size);

int main(void)
{
    int array[SIZE];
    int amount;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = i + 1;
    }

    printf("Please, enter num from 1 to %d:\n", SIZE);

    scanf("%d", &amount);
    while (getchar() != '\n')
    {
    }

    if (amount > SIZE)
    {
        printf("Your number > %d\n", SIZE);
        exit(EXIT_FAILURE);
    }
    else if (amount < 1)
    {
        puts("Your number < 1");
        exit(EXIT_FAILURE);
    }

    randindex(array, SIZE, amount);

    return 0;
}
void randindex(int arr[], int size, int index_amount)
{
    srand((unsigned int)time(NULL));

    int rand_index;
    int iter, j;
    int index_arr[index_amount];

    for (int i = 0; i < index_amount; i++)
    {
        index_arr[i] = 0;
    }

    for (iter = 0; iter < index_amount; iter++)
    {
        rand_index = rand() % size;
        index_arr[iter] = rand_index;

        for (j = 0; j < iter; j++)
        {
            if (rand_index == index_arr[j])
            {
                rand_index = rand() % size;
                index_arr[iter] = rand_index;

                iter = iter - 1;

                break;
            }
        }
    }

    printf("Unsorted random list of indexes in range %d:\n",
           index_amount);
    for (int i = 0; i < index_amount; i++)
    {
        int num = index_arr[i];

        printf("%d ", arr[num]);
    }
    putchar('\n');

    printf("Sorted random list of indexes in range %d:\n",
           index_amount);
    show_indexes(arr, index_arr, index_amount);
}
void show_indexes(int arr[], int index_array[], int indxarr_size)
{
    index_sort(index_array, indxarr_size);

    for (int i = 0; i < indxarr_size; i++)
    {
        int num = index_array[i];

        printf("%d ", arr[num]);
    }
    putchar('\n');
}
void index_sort(int index_array[], int indxarr_size)
{
    int i;
    int intern;
    int storage;

    for (i = 0; i < indxarr_size - 1; i++)
    {
        for (intern = i + 1; intern < indxarr_size; intern++)
        {
            if (index_array[intern] > index_array[i])
            {
                storage = index_array[i];
                index_array[i] = index_array[intern];
                index_array[intern] = storage;
            }
        }
    }
}