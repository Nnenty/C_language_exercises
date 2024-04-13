#include <stdio.h>
#include <time.h>
#include <unistd.h>

void yourtime(double intrv);

const clock_t OUTPUT_SLEEP_INTERVAL = 0.1 * CLOCKS_PER_SEC;

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
    clock_t clockintrv = (clock_t)intrv * CLOCKS_PER_SEC;
    clock_t current = clock();
    clock_t outp = 1;
    clock_t exm = (clock_t)0;

    while (outp > 0)
    {
        if ((current - exm) > OUTPUT_SLEEP_INTERVAL)
        {
            outp = clockintrv - current;

            printf("До конца осталось %.1f секунд\n", (double)outp / CLOCKS_PER_SEC);
            exm = current;
        }

        current = clock();
    }
}