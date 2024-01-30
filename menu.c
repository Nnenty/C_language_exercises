#include <stdio.h>
char choice(void);
int plus(void);
long input(void);
long multiplic(void);
int minus(void);
int division(void);
char input_skip(void);
void main()
{
    int cchoice;

    while ((cchoice = choice()) != 'e')
    {
        switch (cchoice)
        {
        case 'a':
            plus();
            break;
        case 'b':
            multiplic();
            break;
        case 'c':
            minus();
            break;
        case 'd':
            division();
            break;
        default:
            printf("Ошибка.\n");
            break;
        }
    }
    printf("Программа завершена.\n");
    return 0;
}
char choice(void)
{
    int ch;

    printf("Выберите желаемую операцию\n(используйте английскую раскладку клавиатуры):\n");
    printf("a. сложение\tb. умножение\n"
           "c. вычитание\td. деление\n"
           "e. выход\n");
    ch = input_skip();
    while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e')
    {
        printf("Пожалуйста, введите a, b, c, d или e.\n");
        ch = input_skip();
    }
    return ch;
}
char input_skip(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
    {
        continue;
    }
    return ch;
}
int plus(void)
{
    int num, num_2, sum;

    printf("Вы выбрали сложение.\n");
    printf("Введите первое целое число:\n");
    num = input();
    printf("Введите второе целое число:\n");
    num_2 = input();
    sum = num + num_2;
    printf("%d + %d = %d\n", num, num_2, sum);
}
long input(void)
{
    char ch;
    int num;

    while (scanf("%d", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
            printf(" не является целочисленным, введите числа по типу 5, 3, 101.\n");
        }
    }
    return num;
}
int minus(void)
{
    int num, num_2, diff;

    printf("Вы выбрали вычитание.\n");
    printf("Введите первое целое число:\n");
    num = input();
    printf("Введите второе целое число:\n");
    num_2 = input();
    diff = num - num_2;
    printf("%d - %d = %d\n", num, num_2, diff);
}
int division(void)
{
    int num, num_2;

    printf("Вы выбрали деление.\n");
    printf("Введите первое целое число:\n");
    num = input();
    printf("Введите второе целое число:\n");
    num_2 = input();
    printf("%d : %d = %.1f\n", num, num_2, (float)num / num_2);
}
long multiplic(void)
{
    int num, num_2;

    printf("Вы выбрали умножение.\n");
    printf("Введите первое целое число:\n");
    num = input();
    printf("Введите второе целое число\n");
    num_2 = input();
    printf("%d * %d = %d\n", num, num_2, num * num_2);
}