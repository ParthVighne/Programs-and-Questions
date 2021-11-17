//Write a program to print all odd numbers till n.
#include <iostream>
using namespace std;
int main()
{
    int i = 1, n;
    cout << "\nEnter a number : ";
    cin >> n;
    for (i; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        cout << i << ' ';
    }
    return 0;
}