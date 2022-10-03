#include <stdio.h>

int main(int argc, char const *argv[])
{
    char array[101];
    char compareArr[101];

    // vzdy o jedno min = misto pro nulovy znak
    printf("First string: ");
    scanf("%100s", array);
    printf("String to compare: ");
    scanf("%100s", compareArr);

    int i = 0;

    while (array[i] != '\0' || compareArr[i] != '\0')
    {
        if (array[i] != compareArr[i])
        {
            printf("not match\n");
            return 0;
        }
        i++;
    }

    printf("arrays match\n");
    return 0;
}
