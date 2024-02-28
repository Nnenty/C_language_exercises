#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *str, int size);

int main(void)
{
    FILE *fa, *fs;

    char file_app[SLEN];
    char file_src[SLEN];
    int files = 0;
    int ch;

    puts("Введите имя файла назначения:");
    s_gets(file_app, SLEN);

    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IONBF, BUFSIZE) != 0)
    {
        fputs("Не удается создать выходной буфер\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Введите имя первого исходного файла(или пустую строку для завершения):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app) == 0)
        {
            fputs("Добавить файл в конец самого себя невозможно\n", stderr);
        }
        else if ((fs = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "Не удается открыть %s\n", file_src);
        }
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Не удается создать такой входной буфер\n", stderr);
                continue;
            }

            append(fs, fa);
            if (ferror(fs) != 0)
            {
                fprintf(stderr, "Ошибка при чтении файла %s\n", file_src);
            }
            if (ferror(fa) != 0)
            {
                fprintf(stderr, "Ошибка при записи файла %s\n", file_app);
            }
            fclose(fs);

            files++;
            printf("Содержимое файла %s добавлено.\n", file_src);
            puts("Введите имя следующего файла(или пустую строку для завершения):");
        }
    }
    printf("Добавления завершено. Количество добавленных файлов: %d.\n", files);

    rewind(fa);
    printf("Содержимое %s:\n", file_app);
    while ((ch = getc(fa)) != EOF)
    {
        putchar(ch);
    }
    putchar('\n');
    puts("Отображение завершено.");

    fclose(fa);
    return 0;
}
void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    {
        for (int i = 0; i < BUFSIZE; i++)
        {
            temp[i] = toupper(temp[i]);
        }
        fwrite(temp, sizeof(char), bytes, dest);
    }
}
char *s_gets(char *str, int size)
{
    char *ret_val;
    char *find;

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
}