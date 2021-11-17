//Write a program in C++ to find prime numbers within a range.
#include <iostream>
using namespace std;
int main()
{
    int lower, upper, number, i;
    cout << "\nEnter lower limit : ";
    cin >> lower;
    cout << "\nEnter upper limit : ";
    cin >> upper;
    cout << "\n";
    for (number = lower; number <= upper; number++) //runnig through the numbers
    {
        for (i = 2; i <= number; i++) //checking for prime
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