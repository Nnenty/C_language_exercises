#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define NAMESIZE 15
#define LNGSIZE 10

typedef struct piggy
{
    char laungage[LNGSIZE];
    char pigname[NAMESIZE];
} PIGGY;

char *s_gets(char *str, int size);
bool check_pig(PIGGY pig);
void show_pig(PIGGY pig);
void initialize_piggy(PIGGY *pig, int pignum);
void fix_letters(char *pigname);

int main(void)
{
    int check;
    char name[NAMESIZE];
    PIGGY nifnif, nafnaf, nufnuf;
    PIGGY yourpig;

    initialize_piggy(&nifnif, 1);
    initialize_piggy(&nafnaf, 2);
    initialize_piggy(&nufnuf, 3);

    puts("Ты Ниф-ниф, Наф-наф или Нуф-нуф?(пиши на английском)");

    while (s_gets(name, NAMESIZE))
    {
        fix_letters(&name);
        strcpy(yourpig.pigname, name);

        if (check_pig(yourpig))
        {
            break;
        }
        else
        {
            puts("Повтори ввод. Ты НИФ-НИФ, НАФ-НАФ, или НУФ-НУФ?");
        }
    }

    if (strncmp(yourpig.pigname, nifnif.pigname, 3) == 0)
    {
        show_pig(nifnif);
    }
    else if (strncmp(yourpig.pigname, nafnaf.pigname, 3) == 0)
    {
        show_pig(nafnaf);
    }
    else if (strncmp(yourpig.pigname, nufnuf.pigname, 3) == 0)
    {
        show_pig(nufnuf);
    }

    return 0;
}
char *s_gets(char *str, int size)
{
    char *find, *ret_val;
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
bool check_pig(PIGGY pig)
{
    int check;

    if (check = strncmp(pig.pigname, "Nif", 3) == 0)
    {
        return true;
    }
    else if (check = strncmp(pig.pigname, "Naf", 3) == 0)
    {
        return true;
    }
    else if (check = strncmp(pig.pigname, "Nuf", 3) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void show_pig(PIGGY pig)
{
    int process;
    int endprocess = 100;

    int error;
    int *sgmnt_flt = NULL;

    printf("\nТебя зовут %s\n", pig.pigname);
    printf("Ты решил сделать веб-сайт на языке %s\n", pig.laungage);

    for (process = 0; process <= endprocess; process += 10)
    {
        sleep(1);

        printf("Прогресс создания: %d%% из %d%%...\n", process, endprocess);

        if (strncmp(pig.pigname, "Nuf", 3) == 0 && process == 30)
        {
            error = *sgmnt_flt; // funny :)

            break;
        }
    }
    puts("У тебя получилось! Средняя активность сайта - 999999 человек!!");
}
void fix_letters(char *pigname)
{
    int your_namesize = strlen(pigname);

    pigname[0] = toupper(pigname[0]);

    for (int i = 1; i < your_namesize; i++)
    {
        pigname[i] = tolower(pigname[i]);
    }
}
void initialize_piggy(PIGGY *pig, int pignum)
{
    if (pignum == 1)
    {
        *pig = (PIGGY){
            .laungage = "Python",
            .pigname = "Nif-nif"};
    }
    else if (pignum == 2)
    {
        *pig = (PIGGY){
            .laungage = "JS",
            .pigname = "Naf-naf"};
    }
    else if (pignum == 3)
    {
        *pig = (PIGGY){
            .laungage = "C",
            .pigname = "Nuf-nuf"};
    }
    else
    {
        puts("Ошибка инициализации свинтуса");
    }
}