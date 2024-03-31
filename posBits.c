#include <stdio.h>

char *itobs(int n, char *ps);

int main(void)
{
    int num = 129412;
    int mask = 01;
    int count = 0;

    for (int i = 0; i <= (8 * sizeof(int)); i++)
    {
        if ((num & 01) == 01)
        {
            count++;
        }
        num >>= 1;
    }
    printf("num %d has %d true bits\n", num, count);

    return 0;
}