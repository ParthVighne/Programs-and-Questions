#include <stdio.h>

void Traverse(int Arr[], int size)
{
    printf("\n - - - - - - Displaying - - - - - -\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", Arr[i]);
    }
    printf("\n - - - - - - - - - - - - - - - - -\n");
}

void insertAtEnd(int &Arr[], int &size)
{
    int element;
    printf("\nEnter Element : ");
    scanf(&element);
    if (size == 20)
    {
        printf("\nArray Full !");
    }
    else
    {
        Arr[size] = element;
        size++;
    }
}

int main()
{
    int Array[] = {1, 2, 3}, size = 3;
    Traverse(Array, size);
    Array[] = insertAtEnd(Array, size);

    return 0;
}