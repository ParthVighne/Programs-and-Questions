//Program to print the largest element of an array
#include <iostream>
using namespace std;

void enter(int n, int a[]);
void display(int n, int a[]);
void largest(int n, int a[]);

int main()
{
    int n;
    cout << "\nEnter number of elements : ";
    cin >> n;
    int array[n];
    enter(n, array);
    display(n, array);
    largest(n, array);

    return 0;
}

void enter(int n, int a[])
{
    cout << "\n--------- Enter Values ----------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nElement number : " << i + 1 << " : ";
        cin >> a[i];
    }
}

void display(int n, int a[])
{
    cout << "\n--------- Displaying ----------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nElement number " << i + 1 << " : ";
        cout << a[i];
    }
}

void largest(int n, int a[])
{
    int largest = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    cout << "\nLargest element is : " << largest << " , at index : " << i;
}