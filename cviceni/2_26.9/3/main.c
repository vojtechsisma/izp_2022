#include <stdio.h>

int main(int argc, char const *argv[])
{
    int count;
    printf("Zadej pocet cisel: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        int number;
        printf("Zadej cislo %d: ", i + 1);
        scanf("%d", &number);

        if (number % 2)
        {
            printf("cislo %d je liche\n", number);
            continue;
        }

        printf("cislo %d je sude\n", number);
    }
    return 0;
}
