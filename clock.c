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
    clock_t wait_until = (clock_t)intrv * CLOCKS_PER_SEC;
    clock_t last_output_time = 0;
    clock_t current = clock();

    while (current < wait_until)
    {
        if ((current - last_output_time) > OUTPUT_SLEEP_INTERVAL)
        {
            double wait_left = difftime(wait_until, current);

            printf("Этот цикл закончится через %.1f секунд\n",
                   wait_left / CLOCKS_PER_SEC);

            last_output_time = current;
        }

        current = clock();
    }
}