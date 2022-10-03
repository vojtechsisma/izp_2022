#include <stdio.h>

int main(int argc, char const *argv[])
{
    char array;

    // vzdy o jedno min = misto pro nulovy znak
    printf("enter text: ");
    array = getchar();

    printf("%c\n", array);
    return 0;
}
