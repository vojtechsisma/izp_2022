#include <stdio.h>

int main(int argc, char const *argv[])
{

    int length;
    printf("Zadej delku pole: ");
    scanf("%d", &length);

    int array[length];

    for (int i = 0; i < length; i++)
    {
        printf("Zadej cislo %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int max = array[0];
    int sum = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        sum += array[i];
        printf("%d ", array[i]);
    }

    double avg = (double)sum / (double)length;

    printf("\nnejvetsi cislo je %d\n", max);
    printf("prumer je %f\n", avg);

    return 0;
}
