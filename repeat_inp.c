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

    puts("Введите количество повторов:");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++)
    {
        puts(input);
    }

    return 0;
}