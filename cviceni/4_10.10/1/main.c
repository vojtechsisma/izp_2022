#include <stdio.h>

// vrací absolutní hodnotu menšího čísla
int my_crazy_min(int a, int b);
int my_abs(int x);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", my_crazy_min(a, b));
    return 0;
}

int my_abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

int my_crazy_min(int a, int b)
{
    if (a < b)
    {
        return my_abs(a);
    }
    return my_abs(b);
}