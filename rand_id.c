#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define IDSIZE 10
#define NAMESIZE 50

struct id
{
    int id[IDSIZE];
    char name[NAMESIZE];
};

void rand_id(struct id *);
void read(struct id *);
char *s_gets(char *str, int size);

int main(void)
{
    struct id *storage;

    puts("Введите ваше имя:");
    s_gets(storage->name, NAMESIZE);
    rand_id(storage);
    read(storage);

    return 0;
}
char *s_gets(char *str, int size)
{
    char *ret_val, *find;

    ret_val = fgets(str, size, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
            }
        }
    }
    return ret_val;
}
void rand_id(struct id *ptr)
{
    srand((unsigned int)time(0));

    for (int i = 0; i < IDSIZE - 1; i++)
    {
        ptr->id[i] = rand() % 10;
    }
}
void read(struct id *ptr)
{
    printf("Ваше имя: %s; ваше id: ", ptr->name);
    for (int i = 0; i < IDSIZE - 1; i++)
    {
        printf("%d", ptr->id[i]);
    }
}