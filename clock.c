#include <stdio.h>
#include <time.h>

void yourtime(double intrv);

int main(void)
{
    double inptime;

    puts("Введите, сколько будет длиться цикл в секундах:");
    scanf("%lf", &inptime);
    while (getchar() != '\n')
    {
    }

    yourtime(inptime);
    printf("Прошло %.1f секунд\n", inptime);

    return 0;
}
void yourtime(double intrv)
{
    while (clock() < (clock_t)intrv * CLOCKS_PER_SEC)
    {
        printf("Этот цикл закончится через %.1f секунд\n",
               intrv);
    }
}