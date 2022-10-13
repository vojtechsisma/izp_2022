#include <stdio.h>

// Funkce porovná pole a vrací 1, pokud každý prvek v poliarr1 je menší než prvek na stejném indexu v poli arr2.
int smaller_than(int arr1[], int arr2[], int arr_len);

int main()
{
    int input[] = {1, 2, -4};
    int input2[] = {2, 3, 1};
    printf("%d\n", smaller_than(input, input2, sizeof(input) / sizeof(int)));
    return 0;
}

int smaller_than(int arr1[], int arr2[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        if (arr1 > arr2)
        {
            return -1;
        }
    }
    return 1;
}