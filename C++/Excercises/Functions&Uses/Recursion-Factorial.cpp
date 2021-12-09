// A function is called within the same function, it is called recursion.
// The function which calls the same function, is known as a recursive function.

#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int number;
    cout << "\nEnter number : ";
    cin >> number;
    cout << "\nFactorial is : " << factorial(number);

    return 0;
}

// -------------------DRY RUN-------------------
// -> factorial(5) = 5 * factorial(4)
// -> factorial(5) = 5 * 4 * factorial(3)
// -> factorial(5) = 5 * 4 * 3 * factorial(2)
// -> factorial(5) = 5 * 4 * 3 * 2 * factorial(1)
// -> factorial(5) = 5 * 4 * 3 * 2 * 1

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
        return n * factorial(n - 1) /* factorial() is called within itself */;
}