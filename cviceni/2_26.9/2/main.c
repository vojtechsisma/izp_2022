#include <stdio.h>

int main()
{
    char a;
    printf("Zadej pismeno: ");
    scanf("%c", &a);

    if ((a > 64 && a < 91) || (a > 97 && a < 123))
    {
        printf("ASCI code %d\n", a);
    }

    return 0;
}
