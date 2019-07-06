//
// Created by Omer Liberman on 10-Jun-19.
//

#include <stdlib.h>

typedef enum Bool{True, False} Bool;

struct Set{
    int size;
    int capacity;
    int *items;
}typedef Set;

Set *initSet()
{
    Set *s = (Set *)malloc(sizeof(Set));
    s->capacity = 5;
    s->size = 0;
    s->items = (int *)malloc(sizeof(int) * s->capacity);
    return s;
}

void freeSet(Set **s)
{
    Set *to_free = *s;
    free(to_free->items);
    free(to_free);
}

Bool member(Set *s, int num)
{
    for(int i=0; i < s->size; i++)
    {
        if (s->items[i] == num)
        {
            return True;
        }
    }
    return False;
}

void insert(Set *s, int num)
{
    if (member(s, num) == True)
        return;

    if(s->size + 1 < s->capacity)
}


