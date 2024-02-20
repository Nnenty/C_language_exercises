#include <stdio.h>

int calls = 0;

int func(void)
{
    calls++;
    return calls;
}
int main(void)
{
    printf("calls = %d - begin\n", calls);

    func();
    func();
    func();

    printf("calls = %d - after %d func() calls", calls, calls);

    return 0;
}