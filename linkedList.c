//
// Created by Omer Liberman on 31-May-19.
//

# include <stdlib.h>
# include <stdio.h>
#include <string.h>

enum Bool {FALSE,TRUE};

struct Data
{
    char *name;
    int age;
}typedef Data;

Data *createData(char *name, int age)
{
    Data *newData = (Data *)malloc(sizeof(Data));
    char *newName = (char *)malloc(strlen(name));
    strcpy(newName, name);
    newData->name = newName;
    newData->age = age;
    return newData;
}

void freeData(Data *d)
{
    free(d->name);
}

void printData(Data d)
{
    printf("(Name: %s, Age: %d)", d.name, d.age);
}

struct Node
{
    struct Node *next;
    Data *data;
}typedef Node;

Node *createNode(char *name, int age)
{
    Node *toReturn = (Node *)malloc(sizeof(Node));
    Data *d = createData(name, age);
    toReturn->next = NULL;
    toReturn->data = d;
    return toReturn;
}

void freeNode(Node *n)
{
    freeData(n->data);
    n->next = NULL;
}

void addNextToNode(Node *addTo, Node *toAdd)
{
    addTo->next = toAdd;
}

void printChain(Node *head)
{
    while (head != NULL)
    {
        printData(*head->data);
        printf("->");
        head = head->next;
    }
    printf("NULL");
}

void reverseChain(Node **head)
{
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // Store the next
        curr->next = prev; // Reverse curr node
        // Move pointers :
        prev = curr;
        curr = next;
    }
    *head  = prev;
}

enum Bool memberByName(Node *head, char *name)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (strcmp(curr->data->name, name) != FALSE)
        {
            return TRUE;
        }
        curr = curr->next;
    }
    return FALSE;
}

int main()
{
    // For testing
}




