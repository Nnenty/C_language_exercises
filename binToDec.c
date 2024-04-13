#include <stdio.h>
#include <string.h>
#include <math.h>

int binToDec(const char *);

int main(void)
{
    char *binNum = "01001001";

    printf("%d - ", binToDec(binNum));
    puts(binNum);

    return 0;
}
int binToDec(const char *bin)
{
    int i;
    int var;
    int size = strlen(bin);
    int y = 0;

    for (i = size - 1; i >= 0; i--)
    {
        var += (bin[i] == '1' ? 1 : 0) * (int)pow(2.0, (double)y);
        y++;
    }

    return var;
}