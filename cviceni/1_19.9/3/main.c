#include <stdio.h>

int main()
{
    int year;
    printf("Zadej year: ");
    scanf("%d", &year);

    if (year < 1582)
    {
        printf("year nesmi byt mensi nez 1528\n");
        return 1;
    }

    if (year % 4 == 0)
    {
        if (year % 100 != 0)
        {
            printf("je prestupny\n");
            return 0;
        }
        else if (year % 400 == 0)
        {
            printf("je prestupny\n");
            return 0;
        }
    }
    printf("neni prestupny\n");
    return 0;

    return 0;
}
