#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    struct Node* next;
    int value;
}typedef Node;

Node *initNode(int num, Node* prev, Node *next)
{
    Node *toReturn = (Node *)malloc(sizeof(Node));
    toReturn->next = next;
    toReturn->prev = prev;
    toReturn->value = num;
    return toReturn;
}

struct DoubleLinkedList{
    Node *h;
    Node *t;
}typedef DoubleLinkedList;

DoubleLinkedList *initDoubleLinkedList()
{
    DoubleLinkedList *toRet = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    toRet->h = NULL;
    toRet->t = NULL;
    return toRet;
}

void freeDoubleLinkedList(DoubleLinkedList *toFree)
{
    if (toFree->t == NULL)
    {
        return;
    }

    Node *f = toFree->t;
    Node *p = toFree->t->prev;

    while(f != NULL)
    {
        free(f);
        f = p;
        if (f->prev != NULL)
        {
            p = f->prev;
        }
    }
}

void rem(DoubleLinkedList **d, int num)
{
    DoubleLinkedList *dll = *d;

    // Empty list.
    if (dll->h == NULL)
    {
        return;
    }

    // Delete head.
    if (dll->h->value == num)
    {
        Node *next = dll->h->next;
        dll->h = next;
        dll->h->prev = NULL;
    }

    // Delete tail.
    if (dll->t->value == num)
    {
        Node *prev = dll->t->prev;
        dll->t = prev;
        dll->t->next = NULL;
    }

    // Delete inside the list.
    Node *current = dll->h;
    while (current->next != NULL)
    {
        if (current->value == num)
        {
            Node *pre = current->prev;
            Node *nex = current->next;
            pre->next = nex;
            nex->prev = pre;
        }
        current = current->next;
    }
}

void ins(DoubleLinkedList **dll, int num)
{
    DoubleLinkedList *d = *dll;

    // Empty list.
    if(d->h == NULL)
    {
        Node* n = initNode(num, NULL, NULL);
        d->h = n;
        d->t = n;
        return;
    }

    // New num should be the new head.
    if(num <= d->h->value)
    {
        Node* n = initNode(num, NULL, d->h);
        d->h->prev = n;
        d->h = n;
        return;
    }

    // New num should be the new tail.
    if(num >= d->t->value)
    {
        Node* n = initNode(num, d->t, NULL);
        d->t->next = n;
        d->t = n;
        return;
    }

    // New num should be somewhere in the middle.
    Node *current = d->h;
    while (current->next != NULL)
    {
        if(num >= current->value && num <= current->next->value)
        {
            Node *n = initNode(num, current, current->next);
            current->next->prev = n;
            current->next = n;
            return;
        }
        current = current->next;
    }
}

void print(DoubleLinkedList *dll)
{
    printf("HEAD| ");
    Node *curr = dll->h;

    while (curr != NULL)
    {
        printf(" (%d) ", curr->value);
        if (curr->next != NULL){
            printf("<->");
        }
        curr = curr->next;
    }
    printf(" |TAIL\n");

}


int main()
{
    DoubleLinkedList *dll = initDoubleLinkedList();
    ins(&dll, 0);
    ins(&dll, 1);
    ins(&dll, 2);
    ins(&dll, 3);
    ins(&dll, 4);
    ins(&dll, 5);
    ins(&dll, 6);
    ins(&dll, -1);
    print(dll);

    printf("Delete head:\n");
    rem(&dll, -1); // delete head
    print(dll);
    printf("Delete tail:\n");
    ins(&dll, -1);
    rem(&dll, 6); // delete tail
    print(dll);
    printf("Delete middle:\n");
    ins(&dll, 6);
    rem(&dll, 3); // delete inside
    print(dll);

}



