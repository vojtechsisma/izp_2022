#include <stdio.h>

int is_in_set(int arr[], int number, int arr_len);
int is_set(int arr[], int arr_len);
void printIntersection(int arr[], int arr2[], int arr_len);

int main()
{
    int number = 2;
    int input[] = {1, 2, 3, 4, 5};
    // int input2[] = {1, 2, 3, 0, 9};
    int size = sizeof(input) / sizeof(int);
    printf("is_in_set %d\n", is_in_set(input, number, size));
    printf("is_set %d\n", is_set(input, size));
    return 0;
}

int is_in_set(int arr[], int number, int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] == number)
        {
            return 1;
        }
    }
    return 0;
}

int is_set(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}