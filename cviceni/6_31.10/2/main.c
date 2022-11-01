#include <stdio.h>
#include <stdbool.h>

const int UNIVERSUM[5] = {1, 2, 3, 4, 5};
#define MAX_ITEMS (sizeof(UNIVERSUM) / sizeof(UNIVERSUM[0]))

typedef struct
{
    int items[MAX_ITEMS];
    int cardinality;
} set_t;

typedef struct
{
    int first;
    int second;
} pair_t;

bool is_function(pair_t relation[], int rel_size, set_t set);
int rel_minmax(pair_t rel[5], set_t set, pair_t *min, pair_t *max);

int main()
{
    set_t set = {{1, 2, 3, 4, 5}, 5};

    pair_t rel1[5] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    pair_t rel2[5] = {{1, 1}, {1, 2}, {3, 3}, {3, 4}, {5, 5}};
    pair_t rel3[5] = {{1, 1}, {1, 2}, {3, 3}, {3, 4}, {4, 5}};

    printf("%d\n", is_function(rel1, 5, set));
    printf("%d\n", is_function(rel2, 5, set));
    printf("%d\n", is_function(rel3, 5, set));

    pair_t min;
    pair_t max;

    rel_minmax(rel1, set, &min, &max);

    printf("[%d, %d]\n", min.first, min.second);
    printf("[%d, %d]\n", max.first, max.second);

    return 0;
}

bool is_function(pair_t relation[], int rel_size, set_t set)
{
    for (int i = 0; i < set.cardinality; i++)
    {
        int count = 0;
        for (int j = 0; j < MAX_ITEMS; j++)
        {
            if (relation[j].first == set.items[i])
            {
                count++;
            }
        }

        if (count != 1)
        {
            return 0;
        }
    }
    return 1;
}

int rel_minmax(pair_t rel[5], set_t set, pair_t *min, pair_t *max)
{
    *max = rel[0];
    *min = rel[0];

    for (int j = 0; j < MAX_ITEMS; j++)
    {
        if (rel[j].second > max->second)
        {
            *max = rel[j];
        }

        if (rel[j].second < min->second)
        {
            *min = rel[j];
        }
    }

    return 1;
}