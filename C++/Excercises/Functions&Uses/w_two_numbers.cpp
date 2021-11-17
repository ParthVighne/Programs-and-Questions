// Display all prime numbers between two numbers.
#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int lower, upper, num;
    cout << "\nEnter lower limit : ";
    cin >> lower;
    cout << "\nEnter upper limit : ";
    cin >> upper;
    for (num = lower; num <= upper; num++)
    {
        if (isprime(num))
        {
            cout << num << ' ';
        }
    }

    return 0;
}