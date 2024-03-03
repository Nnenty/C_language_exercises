#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD "HeLlO"
#define SIZE 100

int main(void)
{
    srand((unsigned int)time(0));

    FILE *file;
    char name[SIZE];
    char ch;

    long count = 0;
    long num;
    int index = 0;

    printf("Эта программа добавляет в рандомном месте файла слово %s!\n", WORD);
    puts("Введите название вашего файла:");
    scanf("%s", &name);
    while (getchar() != '\n')
    {
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
    fputs(WORD, file);
    putc('!', file);

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