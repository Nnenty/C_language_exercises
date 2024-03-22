#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CSIZE 4
#define MAXGRD 3
#define NAMESIZE 50

struct names
{
    char name[NAMESIZE];
    char surname[NAMESIZE];
};
struct student
{
    struct names name;
    float grades[MAXGRD];
    float avg_grd;
};

void enter_grade(struct student *);
void avg_grade(struct student *);
void read(struct student *);
char *s_gets(char *str, int size);

int main(void)
{
    struct student list[CSIZE];
    int i = 0;

    while (i < CSIZE)
    {
        printf("Введите имя студента %d:\n", (i + 1));
        s_gets(list[i].name.name, NAMESIZE);

        printf("Введите фамилию студента %d:\n", (i + 1));
        s_gets(list[i].name.surname, NAMESIZE);

        printf("Введите %d оценки %sа %sа:\n", MAXGRD, list[i].name.surname,
               list[i].name.name);
        enter_grade(&list[i]);
        avg_grade(&list[i]);
        i++;
    }
    read(list);

    puts("\nПрограмма завершена.");

    return 0;
}
void enter_grade(struct student *ptr)
{
    int i = 0;
    scanf("%f %f %f", &ptr->grades[i++], &ptr->grades[i++],
          &ptr->grades[i++]);
    while (getchar() != '\n')
    {
    }
}
void avg_grade(struct student *ptr)
{
    float stor = 0;

    for (int i = 0; i < MAXGRD; i++)
    {
        stor += ptr->grades[i];
    }
    ptr->avg_grd = (stor / MAXGRD);
}
void read(struct student *ptr)
{
    puts("Ваш список студентов:\n");
    for (int i = 0; i < CSIZE; i++)
    {
        printf("%s %s: оценки: ", ptr[i].name.surname, ptr[i].name.name);
        for (int j = 0; j < MAXGRD; j++)
        {
            printf("%.0f ", ptr[i].grades[j]);
        }
        printf(", среднее значение оценок: %.2f\n", ptr[i].avg_grd);
    }
}
char *s_gets(char *str, int size)
{
    char *ret_val, *find;

    ret_val = fgets(str, size, stdin);
    *ret_val = toupper(*ret_val);
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