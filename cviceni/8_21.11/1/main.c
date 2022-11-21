#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int size; // number of items in the vector
    int *items;        // dynamically allocated array of items
} vector_t;

vector_t *vector_ctor();
void vector_dtor(vector_t *vector);
int vector_add(vector_t *vec, int value);
int *resize(int *arr, unsigned int new_size);

int main()
{
    vector_t *vec = vector_ctor();
    int num;

    while (scanf("%d", &num) == 1)
    {
        if (!vector_add(vec, num))
        {
            vector_dtor(vec);
            return 1;
        }
    }

    for (size_t i = 0; i < vec->size; i++)
    {
        printf("%d ", vec->items[i]);
    }

    printf("\n");

    return 0;
}

vector_t *vector_ctor()
{
    vector_t *v = malloc(sizeof(vector_t));

    if (v != NULL)
    {
        v->size = 0;
        v->items = NULL;
    }

    return v;
}

void vector_dtor(vector_t *vector)
{
    if (vector == NULL)
    {
        return;
    }

    if (vector->items != NULL)
    {
        free(vector->items);
    }

    free(vector);
}

int *resize(int *arr, unsigned int new_size)
{
    int *new_arr = (int *)realloc(arr, new_size * sizeof(int));

    if (new_arr == NULL)
    {
        free(arr);
        return NULL;
    }

    return new_arr;
}

int vector_add(vector_t *vec, int value)
{
    if ((vec->items = resize(vec->items, vec->size + 1)) == NULL)
    {
        return 0;
    }

    vec->items[vec->size] = value;
    vec->size++;

    return 1;
}