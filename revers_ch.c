#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, i2;
    char str[] = "abcdefg";
    char str2[strlen(str)];

    for (i = strlen(str) - 1, i2 = 0; i >= 0; i--, i2++)
    {
        str2[i2] = str[i];
    }
    puts(str2);

    return 0;
}