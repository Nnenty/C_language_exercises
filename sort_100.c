#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sort(int *arr, int num);

int main(void)
{
    int size = 100;
    int save[size];

    srand((unsigned int)time(0));

    for (int i = 0; i < size - 1; i++)
    {
        save[i] = rand() % 10 + 1;
    }
    sort(save, size);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d\n", save[i]);
    }

    return 0;
}
void sort(int *arr, int num)
{
    int i;
    int intern;
    int storage;

    for (i = 0; i < num - 1; i++)
    {
        for (intern = i + 1; intern < num - 1; intern++)
        {
            if (arr[intern] < arr[i])
            {
                storage = arr[i];
                arr[i] = arr[intern];
                arr[intern] = storage;
            }
        }
    }
}