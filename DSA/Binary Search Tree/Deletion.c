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

struct node *binarySearch(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (key < root->data)
        return binarySearch(root->left, key);
    else
        return binarySearch(root->right, key);
}

struct node *iterSearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int isBst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
            return 0;
        else if (prev != NULL && root->data <= prev->data)
            return 0;

        prev = root;
        return isBst(root->right);
    }
    else
        return 1;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
            root = root->right;
        else
            return;
    }
    struct node *new = newNode(key);
    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node *delete (struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value < root->data)
        root->left = delete (root->left, value);
    else if (value > root->data)
        root->right = delete (root->right, value);
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
    return root;
}

int main()
{
    struct node *root = newNode(9);

    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 5);
    insert(root, 8);
    insert(root, 11);
    insert(root, 15);
    insert(root, 14);
    inOrder(root);
    delete (root, 9);
    printf("\n");
    inOrder(root);
    return 0;
}