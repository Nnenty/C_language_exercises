#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME 10
#define SHRTNAME 4
#define MONTHS 12

typedef enum
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} monthname;

typedef struct
{
    int monthsize;
    char *month_name;
    char shrt_name[SHRTNAME];
    monthname number;
} months;

int year;
char *names[MONTHS] = {"january", "february", "march", "april", "may", "june", "july", "august",
                       "september", "october", "november", "december"};
int months_sizes[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sum_days(months *, char *);
void fillarr(months *);
char *s_gets(char *, int);

int main(void)
{
    int sum = 0;
    char name[MAXNAME];
    months arr[MONTHS];

    puts("Введите ваш год(для выхода введите любую букву):");
    if (scanf("%d", &year) == 0)
    {
        exit(EXIT_SUCCESS);
    }
    while (getchar() != '\n')
    {
    }

    fillarr(arr);

    puts("Введите название месяца на английском(пустую строку для выхода):");
    while ((s_gets(name, MAXNAME)) != NULL && name[0] != '\0')
    {
        sum = sum_days(arr, name);

        printf("Сумма дней, вплоть до конца месяца %s = %d\n",
               name, sum);
        puts("Введите следующий месяц(пустую строку для выхода):");
    }

    return 0;
}
void fillarr(months *ptr)
{
    monthname month;

    for (month = January; month <= December; month++)
    {
        ptr[month].month_name = names[month];

        strncpy(ptr[month].shrt_name, ptr[month].month_name, SHRTNAME);
        ptr[month].shrt_name[SHRTNAME - 1] = '\0';

        ptr[month].number = month;

        if ((year % 4) == 0 && month == 1)
        {
            ptr[month].monthsize = months_sizes[month] + 1;
        }
        else
        {
            ptr[month].monthsize = months_sizes[month];
        }
    }
}
int sum_days(months *ptr, char *str)
{
    monthname month, i;
    int sum = 0;

    for (month = January; month <= December; month++)
    {
        if (strcmp(str, names[month]) == 0)
        {
            for (i = January; i <= month; i++)
            {
                sum += ptr[i].monthsize;
            }
        }
    }
    return sum;
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