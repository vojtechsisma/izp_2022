#include <stdio.h>

int main(int argc, char const *argv[])
{
    char array[101];

    // vzdy o jedno min = misto pro nulovy znak
    scanf("%100s", array);

    int i = 0;

    while (array[i] != '\0')
    {
        i++;
    }

    printf("%d\n", i);
    return 0;
}
