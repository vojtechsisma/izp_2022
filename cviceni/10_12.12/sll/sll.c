#include "sll.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

List list_ctor()
{
    List list;
    list.first = NULL;
    return list;
}

Item *item_ctor(Object data)
{
    Item *item = malloc(sizeof(Item));
    if (item != NULL)
    {
        item->data = data;
        item->next = NULL;
    }

    return item;
}

void list_insert_first(List *list, Item *i)
{
    i->next = list->first;
    list->first = i;
}

bool list_empty(List *list)
{
    return list->first == NULL;
}

void list_delete_first(List *list)
{
    if (list_empty(list))
    {
        return;
    }

    Item *tmp = list->first->next;
    free(list->first);
    list->first = tmp;
}

unsigned list_count(List *list)
{
    unsigned count = 0;

    Item *next = list->first;
    while (next != NULL)
    {
        next = next->next;
        count++;
    }
    return count;
}

Item *list_find_minid(List *list)
{
    Item *next = list->first;
    Item *min = list->first;
    while (next != NULL)
    {
        if (next->data.id < min->data.id)
        {
            min = next;
        }
        next = next->next;
    }

    return min;
}

Item *list_find_name(List *list, char *name)
{
    Item *next = list->first;

    while (next != NULL)
    {
        if (strcmp(next->data.name, name) == 0)
        {
            return next;
        }

        next = next->next;
    }

    return NULL;
}

void list_dtor(List *list)
{
    Item *item = list->first;
    while (item != NULL)
    {
        Item *tmp = item->next;
        free(item);
        item = tmp;
    }
    list->first = NULL;
}