#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    char *end;
    int quantity;

    puts("Введите строку, которая будет повторена заданное количество раз:");
    fgets(input, 100, stdin);

    end = strchr(input, '\n');
    if (end)
    {
        *end = '\0';
    }
    else
    {
        while (getchar() != '\n')
        {
        }
    }

    puts("Введите количество повторов:");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++)
    {
        puts(input);
        for (int i = 0; i < 1; i++)
        {
            printf(" %s\n", input);
            for (int i = 0; i < 1; i++)
            {
                printf("  %s\n", input);
                for (int i = 0; i < 1; i++)
                {
                    printf(" %s\n", input);
                }
            }
        }
    }

    return 0;
}