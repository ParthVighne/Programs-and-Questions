#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseList(struct Node *ptr)
{
    printf("\nDisplaying Elements : \n");
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion At First

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *)); // dynamically creating and allocating memory for new node
    ptr->data = data;                                                // assigning value to new node
    ptr->next = head;                                                // linking new node i.e now ptr points to head
    return ptr;                                                      // returns ptr so that new head becomes
}

// Insertion In Between

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    int i = 0;

    struct Node *p = head;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;    // data in new node
    ptr->next = p->next; // new node will point to whatever p was pointing to i.e. the element after new node
    p->next = ptr;       // p points to new node
    return head;         // returns head ( head is unchanged )
}

// Insertion at End

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *)); // new node
    struct Node *p = head;                                           // temporary node
    while (p->next != NULL)                                          // traverse temporary node links till it reaches null
    {
        p = p->next;
    }
    ptr->data = data; // data assigned
    p->next = ptr;    // now that p is the last node, re-assign it to point to ptr
    ptr->next = NULL; // ptr will take place of p to point to null
    return head;
}

// Insert After a given node ( only works if node is defined in main())
struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    // defining nodes
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // allocating memory
    head = (struct Node *)malloc(sizeof(struct Node *));
    first = (struct Node *)malloc(sizeof(struct Node *));
    second = (struct Node *)malloc(sizeof(struct Node *));
    third = (struct Node *)malloc(sizeof(struct Node *));

    // giving value
    head->data = 0;
    first->data = 2;
    second->data = 3;
    third->data = 4;

    // linking pointers
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    traverseList(head); // Displaying

    //! Insertion at first index

    // head = insertAtFirst(head,55);
    // traverseList(head); //Displaying after insertion at first index

    //! Insertion in between

    // head = insertInBetween(head,43,2);
    // traverseList(head);

    //! Insertion At End

    // head = insertAtEnd(head, 88);
    // traverseList(head);

    // ! Insertion After Node
    head = insertAfter(head, first, 344);
    traverseList(head);

    return 0;
}