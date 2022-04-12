#include <iostream>
using namespace std;

void display(int arr[], int size, int capacity) // Display
{
    cout << " -------------------- Displaying -------------------- ";
    cout << "\nSize : " << size;
    cout << "\nCapacity : " << capacity;
    cout << "\nArray is  : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << " ---------------------------------------------------- ";
}

void insertElement(int arr[], int &size, int capacity) // inserting element
{
    int element, index;
    char answer;
    if (size >= capacity) // checking if array is full
    {
        cout << "\nArray is full";
    }
    else // if array is not full, continue with this
    {
        cout << "\nEnter element : ";
        cin >> element;
        cout << "\nDo you want to add element at the last ? (y/n) : ";
        cin >> answer;
        if (answer == 'n') // checking if user wants to add element at the end of the array
        {
            cout << "\nEnter index : ";
            cin >> index;
            for (int i = size; i >= index; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[index] = element;
            size++;
        }
        else
        {
            arr[size] = element;
            size++;
        }
    }
}

void deleteElement(int arr[], int &size) // delete element
{
    int index;
    if (size == 0)
    {
        cout << "\nArray is empty.  ";
    }
    else
    {
        cout << "\nEnter element index to delete : ";
        cin >> index;
        for (int i = index; i <= size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

int main()
{
    int size, capacity;
    cout << "\nEnter capacity : ";
    cin >> capacity;
    cout << "\nEnter size : ";
    cin >> size;
    int array[capacity];
    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter value of element #" << i << " : ";
        cin >> array[i];
    }
    char choice;
    bool a = true;
    while (a)
    {
        cout << "\nChoose operation -> display(1), insert(2), delete(3) or exit(press any key) : ";
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            display(array, size, capacity);
            break;
        }
        case '2':
        {
            insertElement(array, size, capacity);
            display(array, size, capacity);
            break;
        }
        case '3':
        {
            deleteElement(array, size);
            display(array, size, capacity);
            break;
        }
        default:
        {
            a = false;
            break;
        }
        }
    }

    return 0;
}