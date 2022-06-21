#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(2);
    struct node *p3 = createNode(3);

    p1->left = p2;
    p1->right = p3;
    return 0;
}