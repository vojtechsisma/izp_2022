#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int size;      // number of items in the vector
    double *items; // dynamically allocated array of items
} Vector;

/**
 * Allocate vector of specified size.
 * @return pointer to the new vector or NULL if any error occurs
 */
Vector *vector_ctor(int size)
{
    Vector *v = malloc(sizeof(Vector));

    if (v == NULL)
    {
        return NULL;
    }

    v->items = malloc(size * sizeof(int));

    if (v->items == NULL)
    {
        free(v);
        return NULL;
    }

    v->size = size;
    return v;
}

/** Free memory associated with the vector. */
void vector_dtor(Vector *v)
{
    free(v->items);
    free(v);

    return;
}

/**
 * Construct a vector of specified size and read its items from stdin.
 * @return pointer to the new vector or NULL if any error occurs
 */
Vector *vector_read(int size)
{
    Vector *v = vector_ctor(size);

    if (v == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        scanf("%lf", &(v->items[i]));
    }

    return v;
}

/** Print vector in the form 'name = (a,b,...,y,z)\n' */
void vector_print(const char *name, const Vector *v)
{
    printf("name = (");

    for (int i = 0; i < v->size; i++)
    {
        i == v->size - 1 ? printf("%d", (int)v->items[i]) : printf("%d,", (int)v->items[i]);
    }

    printf(")\n");

    return;
}

/** Compute the dot product (aka scalar product) of two vectors. */
double vector_dot_product(const Vector *a, const Vector *b)
{
    double sum = 0;

    for (int i = 0; i < a->size; i++)
    {
        sum += a->items[i] * b->items[i];
    }

    return sum;
}

/**
 * Compute the sum of two vectors.
 * @return pointer to the resulting vector or NULL if any error occurs
 */
Vector *vector_sum(const Vector *a, const Vector *b)
{
    Vector *sum = vector_ctor(a->size);
    if (sum == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < a->size; i++)
    {
        sum->items[i] = a->items[i] + b->items[i];
    }

    return sum;
}

/**
 * (BONUS) append an item to the end of the vector.
 * e.g. (a,b,c) + x = (a,b,c,x)
 * @return false if any error occurs, true otherwise
 */
bool vector_append(Vector *v, double x)
{
    // BONUS TODO remove the line below and implement the function
    (void)v;
    (void)x;
    return true;
}

void allocation_error_msg()
{
    fprintf(stderr, "allocation error\n");
}

int main()
{

    int size;
    printf("specify vector dimension (positive integer):\n");
    scanf("%d", &size);

    printf("enter vector a: (%d items)\n", size);
    Vector *a = vector_read(size);
    if (a == NULL)
    {
        allocation_error_msg();
        return 1;
    }
    printf("enter vector b: (%d items)\n", size);
    Vector *b = vector_read(size);
    if (b == NULL)
    {
        allocation_error_msg();
        vector_dtor(a);
        return 1;
    }

    vector_print("a", a);
    vector_print("b", b);

    printf("a.b = %g\n", vector_dot_product(a, b));

    Vector *sum = vector_sum(a, b);
    vector_print("a+b", sum);

    // (bonus) vector_append
    /* printf("appending additional items to vector a...\n");
    vector_append(a, 42);
    vector_append(a, 0);
    vector_append(a, 2);
    vector_print("a", a); */

    vector_dtor(a);
    vector_dtor(b);
    vector_dtor(sum);
}