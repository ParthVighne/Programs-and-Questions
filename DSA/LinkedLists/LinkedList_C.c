#include <stdio.h>
#include <stdlib.h> // for 'malloc()' function to allocate memory dynamically

struct Node
{
    int data;          // data part of the linked list
    struct Node *next; // self-referencing structure, pointer part of the linked list
};

void traverse(struct Node *head); // Traverse function

struct Node *insertFirst(struct Node *head, int data);                        // Insert element at beggining of the list
struct Node *insertAtEnd(struct Node *head, int data);                        // Insert element at end of the list
struct Node *insertInBetween(struct Node *head, int data, int index);         // Insert element after a given index
struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data); // Inser element after a given node

struct Node *deleteFirst(struct Node *head);              // Delete the first element of the list
struct Node *deleteEnd(struct Node *head);                // Delete the last element of the list
struct Node *deleteAtIndex(struct Node *head, int index); // Delete element at a given index ( works with head)
struct Node *deleteAtValue(struct Node *head, int value); // Delete element having a given value ( does 'not' work on head)

int main()
{
    // Dynamically initialize nodes and allocate memory
    struct Node *head = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node *));

    // Giving values to nodes
    head->data = 0;
    first->data = 1;
    second->data = 2;
    third->data = 3;

    // Linking the Nodes
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    // Todo = = = = = = TRAVERSAL = = = = = = =

    // traverse(head);

    // Todo = = = = = = INSERTION = = = = = = =

    // head = insertFirst(head, 4);
    // head = insertAtEnd(head, 4);
    // head = insertInBetween(head, 4, 1);
    // head = insertAfter(head, first, 4);

    // Todo = = = = = = DELETION = = = = = = =

    // head = deleteFirst(head);
    // head = deleteEnd(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteAtValue(head, 2);

    traverse(head);

    return 0;
}

void traverse(struct Node *head)
{
    printf("\n - - - - - Displaying - - - - - \n");
    while (head != NULL)
    {
        printf("Element : %d \n", head->data);
        head = head->next;
    }
    printf(" - - - - - - - - - - - - - - - - \n");
}

struct Node *insertFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    newNode->next = head;
    traverse(newNode);
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode->next = NULL;
    ptr->next = newNode;
    traverse(newNode);
    return head;
}

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    traverse(newNode);
    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    traverse(newNode);
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    if (head != NULL)
    {
        struct Node *tempPointer = head;
        head = head->next;
        free(tempPointer);
        return head;
    }
    else
    {
        printf("\nList Empty");
    }

    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *tempPointer = head;
    struct Node *tempPointer2 = head->next;
    while (tempPointer2->next != NULL)
    {
        tempPointer = tempPointer->next;
        tempPointer2 = tempPointer2->next;
    }
    tempPointer->next = NULL;
    free(tempPointer2);

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *tempPointer = head;
    struct Node *tempPointer2 = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        tempPointer = tempPointer->next;
        tempPointer2 = tempPointer2->next;
    }
    tempPointer->next = tempPointer2->next;
    free(tempPointer2);

    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *tempPointer = head;
    struct Node *tempPointer2 = head->next;
    while (tempPointer2->data != value && tempPointer2->next != NULL)
    {
        tempPointer = tempPointer->next;
        tempPointer2 = tempPointer2->next;
    }
    if (tempPointer2->data == value)
    {
        tempPointer->next = tempPointer2->next;
        free(tempPointer2);
    }
    return head;
}