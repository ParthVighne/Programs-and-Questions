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

struct node *IterSearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
            return;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    struct node *new = newNode(key);
    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

int main()
{
    struct node *root = newNode(9);
    // struct node *p2 = newNode(2);
    // struct node *p3 = newNode(4);
    // struct node *p4 = newNode(7);
    // struct node *p5 = newNode(5);
    // struct node *p6 = newNode(8);
    // struct node *p7 = newNode(11);
    // struct node *p8 = newNode(15);
    // struct node *p9 = newNode(14);

    // p1->left = p3;
    // p1->right = p7;

    // p3->left = p2;
    // p3->right = p4;

    // p4->left = p5;
    // p4->right = p6;

    // p7->right = p8;

    // p8->left = p9;
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 5);
    insert(root, 8);
    insert(root, 11);
    insert(root, 15);
    insert(root, 14);
    inOrder(root);
    return 0;
}