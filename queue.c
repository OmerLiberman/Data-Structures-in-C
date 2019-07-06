
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10
enum bool{false, true} typedef bool;

struct Queue
{
    int *items;
    int capacity;
    int firstIndex;  // The next item to be popped.
    int lastIndex;  // The last item added.
    int numOfEle;  // Num of elements.
}typedef Queue;

Queue *initQueue()
{
    Queue *toRet = (Queue *)malloc(sizeof(Queue));
    toRet->items = (int *)malloc(SIZE * sizeof(int));
    toRet->capacity = SIZE;
    toRet->firstIndex = -1;
    toRet->lastIndex = -1;
    toRet->numOfEle = 0;
    return toRet;
}

void freeQueue(Queue *q)
{
    free(q->items);
    free(q);
}

bool isEmpty(Queue *q)
{
    return  (q->numOfEle == 0);
}

void push(Queue *q, int num)
{
    if(isEmpty(q))
    {
        q->firstIndex = 0;
        q->lastIndex = 0;
        q->numOfEle = 1;
        q->items[q->firstIndex] = num;
    }
    else
    {
        if (q->numOfEle == q->capacity)
        {
            q->capacity += 5;
            int *data = (int *)realloc(q->items, q->capacity * sizeof(int));
            if (data)
            {
                q->items = data;
            }
            else
            {
                printf("Error mem alloc");
                exit(1);
            }
        }
        q->lastIndex = q->numOfEle - 1;
        q->lastIndex++;
        q->items[q->lastIndex] = num;
        q->numOfEle++;
    }
}

int pop(Queue *q)
{
    if (isEmpty(q))
    {
        return false;
    }
    int toRet = q->items[q->firstIndex];
    q->firstIndex++;
    return toRet;
}



void printQueue(Queue *q)
{
    printf("Queue : NEXT-POPPED| ");
    for (int i = q->firstIndex; i <= q->lastIndex; ++i)
    {
        printf("%d ", q->items[i]);
    }
    printf(" |LAST-ADDED-ITEM\n");
}









int main()
{
    Queue *q = initQueue();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    push(q, 6);
    printQueue(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    printQueue(q);

    return 0;
}

