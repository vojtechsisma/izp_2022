#include <stdio.h>

int compare_arr(int arr1[], int arr2[], int arr_len);

int main()
{
    int input[] = {1, 2, 3, 4, 5};
    int input2[] = {1, 2, 3, 0, 9};
    int size = sizeof(input) / sizeof(int);
    printf("%d\n", compare_arr(input, input2, size));
    return 0;
}

int compare_arr(int arr1[], int arr2[], int arr_len)
{
    int result = 0;
    for (int i = 0; i < arr_len; i++)
    {
        for (int index = 0; index < arr_len; index++)
        {
            if (arr1[i] == arr2[index])
            {
                result++;
            }
        }
    }
    return result;
}
