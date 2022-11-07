// Vojtech Sisma

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    scanf("%d", &count);

    int *arr = malloc(count * sizeof(int));

    if (arr== NULL)
    {
        fprintf(stderr, "Allocation error\n");
        return 1;
    }
    

    for (int i = 0; i < count; i++)
    {
       scanf("%d", &arr[i]);
    }


    for (int i = count-1; i >= 0; i--)
    {
       printf("%d ", arr[i]);
    }
    
    printf("\n");

    free(arr);

    return 0;
}
