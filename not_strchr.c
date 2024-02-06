#include <stdio.h>
#include <string.h>

char *sstrchr(char *str, char ch);

int main(void)
{
    char arr[] = "Hello, i am codding in C laungage";
    char *ptr;

    ptr = sstrchr(arr, 'C');

    if (ptr)
    {
        puts(ptr);
    }
    else
    {
        puts("Error.");
    }

    return 0;
}
char *sstrchr(char *str, char ch)
{
    while (*str != '\0')
    {
        if (*str == ch)
        {
            return str;
        }
        str++;
    }

    return NULL;
}