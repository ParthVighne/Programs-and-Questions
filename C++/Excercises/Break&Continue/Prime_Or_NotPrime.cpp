//Write a program to check if a given number is prime or not
#include <iostream>
using namespace std;
int main()
{
    int i = 2, n;
    cout << "\nEnter a number : ";
    cin >> n;
    for (i; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "\nNot prime.";
            break;
        }
    }
    if (i == n)
    {
        cout << "\nPrime.";
    }
    return 0;
}