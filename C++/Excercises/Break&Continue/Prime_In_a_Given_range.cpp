//Write a program to print all prime numbers in a given range.
#include <iostream>
using namespace std;
int main()
{
    int i = 2, lower, upper;
    cout << "\nEnter lower number :";
    cin >> lower;
    cout << "\nEnter upper number :";
    cin >> upper;
    cout << "\n Prime numbers from " << lower << " to " << upper << " are : ";
    for (int number = lower; number <= upper; number++)
    {
        for (i = 2; i < number; i++)
        {
            if (number % i == 0)
                break;
        }
        if (i == number)
        {
            cout << number << ' ';
        }
    }
    return 0;
}