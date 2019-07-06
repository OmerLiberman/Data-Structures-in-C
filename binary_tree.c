//
// Created by Omer Liberman on 02-Jun-19.
//

#include <stdlib.h>
#include <stdio.h>

enum bool {false, true};

struct Node
{
    struct Node *right;
    struct Node *left;
    int data;
}typedef Node;


Node *initNode(int data, Node *right, Node* left)
{
    Node *toReturn = (Node *)malloc(sizeof(Node));
    toReturn->data = data;
    toReturn->right = right;
    toReturn->left = left;
    return toReturn;
}


void insert(Node **root, Node *toAdd)
{
    if (!(*root))
    {
        *root = toAdd;
        return;
    }

    if (toAdd->data >= (*root)->data)
    {
        insert(&(*root)->right, toAdd);
    }
    else
    {
        insert(&(*root)->left, toAdd);
    }
}

enum bool search(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }

    if(root->data == val)
    {
        return true;
    }

    else
    {
        if (root->data > val)
        {
            return search(root->left, val);
        }
        if (root->data < val)
        {
            return search(root->right, val);
        }
    }
}

int main()
{
    Node *root = initNode(1, NULL, NULL);
    Node *toAdd = initNode(2, NULL, NULL);
    Node *toAdd1 = initNode(0, NULL, NULL);
    Node *toAdd2 = initNode(-1, NULL, NULL);
    Node *toAdd3 = initNode(3, NULL, NULL);
    Node *toAdd4 = initNode(4, NULL, NULL);


    insert(&root, toAdd);
    insert(&root, toAdd1);
    insert(&root, toAdd2);
    insert(&root, toAdd3);
    insert(&root, toAdd4);

    enum bool s1 = search(root, 1);
    enum bool s2 = search(root, 8);
    printf("S1 : %d, S2: %d", s1, s2);

    printf("stop");
}



