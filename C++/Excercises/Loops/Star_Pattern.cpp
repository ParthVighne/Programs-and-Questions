/*
n = 5

. . . . *
. . . * * *
. . * * * * *
. * * * * * * *
* * * * * * * * *  
. * * * * * * *
. . * * * * *
. . . * * *
. . . . *

Herer (.) is space.

*/
#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "\nEnter number : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (j = i; j <= i && j > 0; j--)
        {
            cout << " *";
        }
        for (j = 2; j <= i; j++)
        {
            cout << " *";
        }

        cout << endl;
    }
    for (i = n; i >= 0; i--)
    {
        for (j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (j = i; j <= i && j > 0; j--)
        {
            cout << " *";
        }
        for (j = 2; j <= i; j++)
        {
            cout << " *";
        }

        cout << endl;
    }

    return 0;
}