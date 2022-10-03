#include <stdio.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("no argumnets provided\n");
        return 1;
    }

    char array[101];

    // vzdy o jedno min = misto pro nulovy znak
    scanf("%100s", array);

    int i = 0;

    while (array[i] != '\0')
    {
        if (array[i] == argv[1][0])
        {
            array[i] = '-';
        }
        i++;
    }

    printf("%s\n", array);
    return 0;
}
