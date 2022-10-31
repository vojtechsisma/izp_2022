#include <stdio.h>

#define MX_ROWS 4
#define MX_COLS 4

typedef struct
{
    int x;
    int y;
} Coords;

void print_2d_array(int array[MX_ROWS][MX_COLS]);
Coords find_in_2d_array(int array[MX_ROWS][MX_COLS], int find);

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

    print_2d_array(pole2d);

    Coords result = find_in_2d_array(pole2d, 0);
    printf("x: %d y: %d\n", result.x, result.y);

    return 0;
}

// Tisk 2D pole
void print_2d_array(int array[MX_ROWS][MX_COLS])
{

    for (int row = 0; row < MX_ROWS; row++)
    {
        for (int col = 0; col < MX_COLS; col++)
        {
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

Coords find_in_2d_array(int array[MX_ROWS][MX_COLS], int find)
{
    for (int i = 0; i < MX_ROWS; i++)
    {
        for (int j = 0; j < MX_COLS; j++)
        {
            if (array[i][j] == find)
            {
                return (Coords){i, j};
            }
        }
    }

    return (Coords){-1, -1};
}