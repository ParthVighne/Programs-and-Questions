#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->data == key)
        return root;
    else if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    struct node *p1 = newNode(9);
    struct node *p2 = newNode(2);
    struct node *p3 = newNode(4);
    struct node *p4 = newNode(7);
    struct node *p5 = newNode(5);
    struct node *p6 = newNode(8);
    struct node *p7 = newNode(11);
    struct node *p8 = newNode(15);
    struct node *p9 = newNode(14);

    p1->left = p3;
    p1->right = p7;

    p3->left = p2;
    p3->right = p4;

    p4->left = p5;
    p4->right = p6;

    p7->right = p8;

    p8->left = p9;

    // inOrder(p1);
    struct node *n = search(p1, 15);
    if (n != NULL)
    {
        printf("\nFound : %d ", n->data);
    }
    else
    {
        printf("\nNot Found");
    }

    return 0;
}