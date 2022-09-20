#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Zadej a b c: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Vysledek: %d\n", b * b - 4 * a * b);

    return 0;
}
