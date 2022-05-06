#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *head);

struct Node *insertAtStart(struct Node *head, int data);

struct Node *insertAtEnd(struct Node *head, int data);

struct Node *insertBetween(struct Node *head, int data, int index);

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data);

struct Node *deleteAtStart(struct Node *head);

struct Node *deleteAtEnd(struct Node *head);

struct Node *deleteAtIndex(struct Node *head, int index);

struct Node *deleteAtValue(struct Node *head, int value);

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node *));

    head->data = 0;
    first->data = 1;
    second->data = 2;
    third->data = 3;

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    traverse(head);
    head = insertAtStart(head, 4);
    // head = insertAtEnd(head,4);
    // head = insertBetween(head, 4, 2);
    // head = insertAfter(head, first, 4);
    traverse(head);
    head = deleteAtStart(head);
    // head = deleteAtEnd(head);
    // head = deleteAtIndex(head ,2);
    // head = deleteAtValue(head, 4);
    traverse(head);

    return 0;
}

void traverse(struct Node *head)
{
    struct Node *ptr = head;
    printf("\nDisplaying \n");
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;

    struct Node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    // same as insertAtStart() , just return head instead of newNode ;)
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;

    struct Node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;

    return head;
}

struct Node *insertBetween(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    struct Node *ptr = head;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}

struct Node *deleteAtStart(struct Node *head)
{
    struct Node *ptr = head;        // to be deleted
    struct Node *ptr2 = head->next; // for linking last node to new head
    while (ptr2->next != head)      // traversing till ptr2 points to head
    {
        ptr2 = ptr2->next;
    }
    head = head->next; // head moves 1 up, hence becoming the new head
    ptr2->next = head; // ptr2 points to the new head
    free(ptr);         // previous head i.e. ptr gets deleted
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    while (ptr2->next != head)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next; // or ptr->next = head , will work the same
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
    while (ptr2->data != value && ptr2->next != head)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next;
    free(ptr2);
    return head;
}