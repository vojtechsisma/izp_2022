#include <stdio.h>

#define MX_ROWS 4
#define MX_COLS 4

typedef struct
{
    int x;
    int y;
} Coords;

void print_2d_array_to_file(int array[MX_ROWS][MX_COLS]);

int main()
{
    int pole2d[4][4]; // pole 4 řádků s 5 sloupci pole2d[0][0] = 0; pole2d[3][4] = -1;

    for (int i = 0; i < MX_ROWS; i++)
    {
        for (int j = 0; j < MX_COLS; j++)
        {
            pole2d[i][j] = i == j ? 1 : 0;
        }
    }

    print_2d_array_to_file(pole2d);

    return 0;
}

// Tisk 2D pole
void print_2d_array_to_file(int array[MX_ROWS][MX_COLS])
{
    FILE *soubor;
    soubor = fopen("file.txt", "w");

    for (int row = 0; row < MX_ROWS; row++)
    {
        for (int col = 0; col < MX_COLS; col++)
        {
            fprintf(soubor, "%d ", array[row][col]);
        }
        fprintf(soubor, "\n");
    }

    fprintf(soubor, "\n");
    fclose(soubor);
}