#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_n_dice(int dice, int sides, int repeat)
{
    int roll;
    int quanitly;
    int sum = 0;

    srand((unsigned int)time(0));
    roll = rand() % (sides * dice) + 1;

    while (repeat != 0)
    {
        sum += roll;
        roll = rand() % (sides * dice) + 1;

        repeat--;
    }
    return sum;
}
int main(void)
{
    int times;
    int sides, dice;

    puts("Введите количество повторений(0 для завершения):");
    while (scanf("%d", &times) == 1 && times > 0)
    {
        puts("Кол-во сторон:");
        scanf("%d", &sides);
        puts("Кол-во костей:");
        scanf("%d", &dice);

        printf("%d костей, %d бросков, %d сумма результатов бросков.\n",
               dice, times, roll_n_dice(dice, sides, times));
        puts("Введите количество повторений(0 для завершения):");
    }

    return 0;
}