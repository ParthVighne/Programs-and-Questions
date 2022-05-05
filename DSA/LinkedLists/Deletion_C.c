#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// TODO ---------------------------- Traversal Algorithms -----------------------------------

// Traversing the Linked List

void traverseList(struct Node *ptr)
{
    printf("\nDisplaying Elements : \n");
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// TODO --------------------------- Insertion Algorithms ------------------------------------

// Insertion At First

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *)); // dynamically creating and allocating memory for new node
    newNode->data = data;                                                // assigning value to new node
    newNode->next = head;                                                // linking new node i.e now newNode points to head
    return newNode;                                                      // returns newNode so that new head becomes
}

// Insertion In Between

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    int i = 0;

    struct Node *ptr = head;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->data = data;      // data in new node
    newNode->next = ptr->next; // new node will point to whatever ptr was pointing to i.e. the element after new node
    ptr->next = newNode;       // p points to new node
    return head;               // returns head ( head is unchanged )
}

// Insertion at End

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *)); // new node
    struct Node *p = head;                                               // temporary node
    while (p->next != NULL)                                              // traverse temporary node links till it reaches null
    {
        p = p->next;
    }
    newNode->data = data; // data assigned
    p->next = newNode;    // now that p is the last node, re-assign it to point to newNode
    newNode->next = NULL; // newNode will take place of p to point to null
    return head;
}

// Insert After a given node ( only works if node is defined in main())

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *)); // New node created and memory allocated
    newNode->data = data;                                                // assigned data
    newNode->next = prevNode->next;                                      // newNode points to what the previous node is pointing to
    prevNode->next = newNode;                                            // previous node points to newNode
    return head;
}

// TODO ------------------------ Deletion Algorithms ---------------------------------------

// Deleting From Front

struct Node *deleteFromFront(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nList already empty");
    }
    else
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }
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
    //! Will not delete 'head', there is a seperate function for it. Will start from index 1.
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next;
    free(ptr2);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    //! will not delete element if value matches at head
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    while (ptr2->data != value && ptr2->next != NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    if (ptr2->data == value)
    {
        ptr->next = ptr2->next;
        free(ptr2);
    }
    return head;
}

// TODO ---------------------------------------------------------------

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

    head = insertAtFirst(head, 55);
    traverseList(head); // Displaying after insertion at first index

    //! Insertion in between

    // head = insertInBetween(head,43,2);
    // traverseList(head);

    //! Insertion At End

    // head = insertAtEnd(head, 88);
    // traverseList(head);

    // ! Insertion After Node
    // head = insertAfter(head, first, 344);
    // traverseList(head);

    // ! Deletion from front
    // head = deleteFromFront(head);
    // traverseList(head);

    // ! Deletion at index
    // head = deleteAtIndex(head, 2);
    // traverseList(head);

    // ! Deletion at value
    // head = deleteAtValue(head, 0);
    // traverseList(head);

    return 0;
}
