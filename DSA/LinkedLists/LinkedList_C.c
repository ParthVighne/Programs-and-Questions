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
    // Dyamically initialize nodes and allocate memory
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // initialize new node
    newNode->data = data;                                              // give data to new node
    newNode->next = head;                                              // point new node to current head(first node)
    traverse(newNode);
    return newNode; // return new node so, head is now new node
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // initialize new node
    newNode->data = data;                                              // give data to new node
    struct Node *ptr = head;                                           // pointer that points to head ( first node )
    while (ptr->next != NULL)                                          // loop till pointer is at the last node
    {
        ptr = ptr->next;
    }
    newNode->next = NULL; // new node points to NULL
    ptr->next = newNode;  // point the last node to new node which in turn becomes the last node;
    traverse(newNode);
    return head;
}

struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // initialize new node
    struct Node *ptr = head;                                           // pointer points to head ( first node )
    int i = 0;                                                         // i for traversing till given index
    while (i != index - 1)                                             // loop till pointer comes to the node just after which new node has to be inserted
    {
        ptr = ptr->next;
        i++;
    }
    newNode->data = data;      // give data to new node
    newNode->next = ptr->next; // point new node to node that ptr (node before new node) is pointing to
    ptr->next = newNode;       // point ptr to new node
    traverse(newNode);
    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // initialize new node
    newNode->data = data;                                              // give data to new node
    newNode->next = prevNode->next;                                    // point new node to what its previous node was pointing to
    prevNode->next = newNode;                                          // point previous node to new node
    traverse(newNode);
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    if (head != NULL)
    {
        printf("\nList Empty");
    }
    else
    {
        struct Node *tempPointer = head; // pointer to first node
        head = head->next;               // move first node to the next
        free(tempPointer);               // free pointer to first node , and now the new head is the first node
        return head;
    }
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *tempPointer = head;        // pointer (A) to first node
    struct Node *tempPointer2 = head->next; // pointer (B) to second node
    while (tempPointer2->next != NULL)      // loop till B points to NULL
    {
        tempPointer = tempPointer->next;
        tempPointer2 = tempPointer2->next;
    }
    tempPointer->next = NULL; // point A to NULL
    free(tempPointer2);       // delete B

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *tempPointer = head;        // pointer (A) to first node
    struct Node *tempPointer2 = head->next; // pointer (B) to second node
    for (int i = 0; i < index - 1; i++)     // loop till B is at the node that is to be deleted and A is at its previous node
    {
        tempPointer = tempPointer->next;
        tempPointer2 = tempPointer2->next;
    }
    tempPointer->next = tempPointer2->next; // point A to what B was pointing at
    free(tempPointer2);                     // delete B

    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *tempPointer = head;                                  // pointer (A) to first node
    struct Node *tempPointer2 = head->next;                           // pointer (B) to second node
    while (tempPointer2->data != value && tempPointer2->next != NULL) // loop till B has the given value and B does not point to NULL
    {
        tempPointer = tempPointer->next;
        tempPointer2 = tempPointer2->next;
    }
    if (tempPointer2->data == value) // if B has the given value,
    {
        tempPointer->next = tempPointer2->next; // point A to where B was pointing
        free(tempPointer2);                     // delete B
    }
    return head;
}