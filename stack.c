//
// Created by Omer Liberman on 31-May-19.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct Stack{
    int *values;
    size_t currSize;
    int topIndex;
    int topValue;
}typedef Stack;

Stack *initStack()
{
    Stack *toRet = (Stack *)malloc(sizeof(Stack));
    toRet->values = (int *)malloc(10 * sizeof(int));
    toRet->currSize = 10;
    toRet->topIndex = -1;
    toRet->topValue = -1;
    return toRet;
}

void freeStack(Stack *s)
{
    free(s->values);
    free(s);
}

void push(Stack *s, int val)
{
    if (s->topIndex + 1 == s->currSize)
    {
        s->currSize += 5;
        int *newValues = (int *)realloc(s->values, s->currSize * sizeof(int));
        if (newValues)
        {
            s->values = newValues;
        }
    }
    s->topIndex++;
    s->values[s->topIndex] = val;
    s->topValue = s->values[s->topIndex];
}

int pop(Stack *s)
{
    if (s->topIndex == -1)
    {
        return -1;
    }
    int toReturn = s->values[s->topIndex];
    s->topIndex--;
    s->topValue = s->values[s->topIndex];
    if (s->topIndex < s->currSize - 5)
    {
        s->currSize -= 5;
        s->values = (int *)realloc(s->values, s->currSize * sizeof(int));
    }
    return toReturn;
}


void printStack(Stack *s)
{
    printf("Current Stack is : BOTTOM| ");
    for (int i = 0; i <= s->topIndex; i++)
    {
        int curr = s->values[i];
        printf("%d ", curr);
    }
    printf("|TOP\n");
}


int main()
{
    Stack *s = initStack();
    push(s, 0);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 9);
    push(s, 9);
    push(s, 9);
    printStack(s);
    pop(s);
    pop(s);
    printStack(s);

    free(s);

    return 0;
}


