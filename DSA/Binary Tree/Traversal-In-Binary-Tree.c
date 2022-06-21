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

void preOrder(struct node *root) // root -> left -> right
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root) // left -> right -> root
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root) // left -> root -> right
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(2);
    struct node *p3 = createNode(3);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(5);
    struct node *p6 = createNode(6);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;

    /*
                p1(1)
            /         \
        p2(2)          p3(3)
     /        \       /      \
    p4(4)   p5(5)   p6(6)    NULL

    */

    printf("\nPre-order : ");
    preOrder(p1); // 1 2 4 5 3 6
    printf("\n");

    printf("\nPost-order : ");
    postOrder(p1); // 4 5 2 6 3 1
    printf("\n");

    printf("\nIn-order : ");
    inOrder(p1); // 4 2 5 1 6 3
    printf("\n");

    return 0;
}
