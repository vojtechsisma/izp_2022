#include <stdio.h>

int main(int argc, char const *argv[])
{
    char array[101];

    // vzdy o jedno min = misto pro nulovy znak
    scanf("%100s", array);

    int i = 0;

    int diff = 'a' - 'A';

    while (array[i] != '\0')
    {
        if (array[i] <= 'Z' && array[i] >= 'A')
        {
            array[i] += diff;
            i++;
            continue;
        }

        if (array[i] <= 'z' && array[i] >= 'a')
        {
            array[i] -= diff;
            i++;
            continue;
        }
        i++;
    }

    printf("%s\n", array);
    return 0;
}
