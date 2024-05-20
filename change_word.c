#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int TEXT_SIZE = 321;

int WORD_SIZE = 32;

void get_text(char *text);
void get_words(char *word1, char *word2);

char *choose_word(char *word1, char *word2);
void change_text_words(char *text, char *word_for_insert, char *word_to_change);
char *s_gets(char *str, int size);

int main(void)
{
    char text[TEXT_SIZE];

    char word1[WORD_SIZE];
    char word2[WORD_SIZE];

    get_text(text);
    get_words(word1, word2);

    puts("Original text:\n");
    puts(text);
    putchar('\n');

    change_text_words(text, choose_word(word1, word2), "animal");

    puts("Changed text:");
    puts(text);

    return 0;
}
void get_text(char *text)
{
    strcpy(text, "Hello cute animal i love you animal! How are you cute animal?"
                 "\nWhat are you think about this program animal?" // if you change this text, change its size too to avoid
                 "\n animal, this program work and i happy!!!");   // segmentation fault
}
void get_words(char *word1, char *word2)
{
    puts("Enter first animal:");
    s_gets(word1, WORD_SIZE);

    puts("Enter second animal:");
    s_gets(word2, WORD_SIZE);
}
char *choose_word(char *word1, char *word2)
{
    char *user_select = malloc(sizeof(char) * WORD_SIZE);

    printf("Select %s or %s to insert into text:\n",
           word1, word2);

    s_gets(user_select, WORD_SIZE);

    if (strncmp(user_select, word1, strlen(word1)) == 0)
    {
        return user_select;
    }
    else if (strncmp(user_select, word2, strlen(word2)) == 0)
    {
        return user_select;
    }
    else
    {
        puts("There is no such word");
        exit(EXIT_FAILURE);
    }
}
char *s_gets(char *str, int size)
{
    char *ret_val;
    char *find;

    ret_val = fgets(str, size, stdin);

    if (ret_val)
    {
        if (find = strchr(str, '\n'))
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
void change_text_words(char *text, char *word_for_insert, char *word_to_change)
{
    int i;

    char temp[TEXT_SIZE];
    char temp2[TEXT_SIZE];

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            if (strncmp(text + i + 1, word_to_change, strlen(word_to_change)) == 0)
            {
                strncpy(temp, text, i + 1);
                strcat(temp, word_for_insert);

                strcpy(temp2, text + i + strlen(word_to_change) + 1);
                strcat(temp, temp2);

                strcpy(text, temp);

                strncpy(temp, "\0", strlen(temp));
                strncpy(temp2, "\0", strlen(temp2));
            }
        }
    }

    free(word_for_insert);
}