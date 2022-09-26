#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Zadej spodni hranici: ");
    scanf("%d", &a);
    printf("Zadej horni hranici ");
    scanf("%d", &b);
    printf("Zadej cislo: ");
    scanf("%d", &c);

    if (c > a && c < b)
    {
        printf("cislo %d lezi v intervalu\n", c);
        return 0;
    }

    printf("cislo %d nelezi v intervalu\n", c);
    return 0;
}
