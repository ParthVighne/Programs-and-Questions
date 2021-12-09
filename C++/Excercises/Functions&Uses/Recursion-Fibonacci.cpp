// A function is called within the same function, it is called recursion.
// The function which calls the same function, is known as a recursive function.
// ! Not always good, gives a lot of overhead i.e that the same function is called for multiple times.
// ! Use iterative approach instead if too much recursion. :)

#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
    int position;
    cout << "\nEnter position : ";
    cin >> position;
    cout << "\nNumber at position " << position << " is : " << fibonacci(position);

    return 0;
}

// -------------------DRY RUN-------------------
// -> fibonacci(5) = fibonacci(4) + fibonacci(3)
// -> fibonacci(5) = fibonacci(3) + fibonacci(2) + fibonacci(2) + fibonacci(1)
// -> fibonacci(5) = fibonacci(2) + fibonacci(1) + fibonacci(1) + fibonacci(0) + fibonacci(1) + fibonacci(0) + 1
// -> fibonacci(5) = fibonacci(1) + fibonacci(0) + 1 + 1 + 1 + 1 + 1 + 1
// -> fibonacci(5) = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8

int fibonacci(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
        return fibonacci(n - 1) + fibonacci(n - 2) /* fibonacci() is called within itself */;
}