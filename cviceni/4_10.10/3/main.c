#include <stdio.h>

int get_sum(int arr[], int len);

int main()
{
    int input[] = {1, 2, -4};
    printf("%d\n", get_sum(input, sizeof(input) / sizeof(int)));
    return 0;
}

int get_sum(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}