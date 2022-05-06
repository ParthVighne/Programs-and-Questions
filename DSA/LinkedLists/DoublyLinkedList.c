#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverse(struct Node *head);

void traverseInReverse(struct Node *head);

struct Node *insertAtFirst(struct Node *head, int data);

struct Node *insertAtEnd(struct Node *head, int data); // TOD

struct Node *insertAtIndex(struct Node *head, int index, int data);

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data);

struct Node *insertBefore(struct Node *head, struct Node *afterNode, int data); // TODO

struct Node *deleteFromStart(struct Node *head);

struct Node *deleteFromEnd(struct Node *head);

struct Node *deleteAtIndex(struct Node *head, int index);

struct Node *deleteAtValue(struct Node *head, int value);

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 0;
    first->data = 1;
    second->data = 2;
    third->data = 3;

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    head->prev = NULL;
    first->prev = head;
    second->prev = first;
    third->prev = second;
    // traverseInReverse(head);
    traverse(head);
    // head = insertAtFirst(head, 4);
    // head = insertAtIndex(head, 2, 4);
    // head = insertAfter(head, first, 4);
    // head = insertBefore(head, second, 4);
    head = insertAtEnd(head, 4);

    // head = deleteFromStart(head);
    // head = deleteFromEnd(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtValue(head, 2);
    traverse(head);

    return 0;
}

void traverse(struct Node *head)
{
    printf("\n - - - - Displaying - - - - - \n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void traverseInReverse(struct Node *head)
{
    printf("\n - - - - Displaying list in reverse - - - - - \n");
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode->next = NULL;
    newNode->prev = ptr->prev;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    newNode->data = data;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    newNode->prev = ptr;
    ptr->next = newNode;
    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    return head;
}

struct Node *insertBefore(struct Node *head, struct Node *afterNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = afterNode;
    newNode->prev = afterNode->prev;
    afterNode->prev = newNode;
    return head;
}

struct Node *deleteFromStart(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct Node *deleteFromEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    while (ptr2->next != NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = NULL;
    free(ptr2);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
        i++;
    }
    ptr->next = ptr2->next;
    free(ptr2);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    while (ptr2->data != value && ptr2->next != NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next;
    free(ptr2);
    return head;
}
