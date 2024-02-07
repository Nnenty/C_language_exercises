#include <stdio.h>

int main(int argc, char *argv[])
{
    puts("arguments in reverse order:");

    for (int i = argc - 1; i > 0; i--)
    {
        printf("%s ", argv[i]);
    }

    return 0;
}
