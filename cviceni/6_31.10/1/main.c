#include <stdio.h>

void switch_values(int *a, int *b);

int main()
{
    int a = 2;
    int b = 3;

    printf("before: %d %d\n", a, b);
    switch_values(&a, &b);
    printf("after: %d %d\n", a, b);

    return 0;
}

void switch_values(int *a, int *b)
{
    int pom = *a;
    *a = *b;
    *b = pom;
}