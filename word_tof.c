#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(void)
{
    srand((unsigned int)time(0));

    FILE *file;
    char name[SIZE];
    char word[SIZE];
    char *find;
    char ch;

    long count = 0;
    long num;
    int index = 0;

    puts("Эта программа вставляет в рандомное место вашего файла выбранное слово!");
    puts("Введите ваше слово:");
    fgets(word, SIZE, stdin);
    find = strchr(word, '\n');
    if (find)
    {
        *find = '\0';
    }

    puts("Введите название вашего файла:");
    fgets(name, SIZE, stdin);
    find = strchr(name, '\n');
    if (find)
    {
        *find = '\0';
    }

    if ((file = fopen(name, "r+")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл %s", name);
        exit(EXIT_FAILURE);
    }

    while (getc(file) != EOF)
    {
        count++;
    }

    num = rand() % count + 1L;
    char storage[count];

    rewind(file);
    while ((storage[index] = getc(file)) != EOF)
    {
        index++;
    }
    storage[count] = '\0';

    puts("Содержимое файла до:");
    puts(storage);
    putchar('\n');

    fseek(file, num, SEEK_SET);
    putc('!', file);
    fputs(word, file);
    putc('!', file);
    putchar('\n');

    rewind(file);
    puts("И содержимое файла после:");
    while ((ch = getc(file)) != EOF)
    {
        putchar(ch);
    }
    putchar('\n');

    fclose(file);
    return 0;
}