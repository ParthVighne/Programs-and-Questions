#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default Constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    // Default Constructor
    LinkedList()
    {
        head = NULL;
    }

    void traverse();
    void insertAtEnd(int data);
    void insertAtStart(int data);
};

void LinkedList ::traverse()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "\nList empty";
        return;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    LinkedList List;
    List.traverse();

    return 0;
}