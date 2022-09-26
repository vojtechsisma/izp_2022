#include <stdio.h>
#include <math.h>

int main()
{

    int a, b, c;
    double x1, x2;

    printf("Zadej tri cisla: ");
    scanf("%d %d %d", &a, &b, &c);

    double d = b * b - 4 * a * c;

    if (d > 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b / sqrt(d)) / (2 * a);
        printf("x1 = %f\nx2 = %f\n", x1, x2);
        return 0;
    }

    if (d == 0)
    {
        x1 = -b / (2 * a);
        printf("vysledek %f\n", x1);
        return 0;
    }

    if (d < 0)
    {
        printf("nema reseni\n");
        return 0;
    }

    return 0;
}
