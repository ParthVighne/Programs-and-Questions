/*
*             *
* *         * *
* * *     * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *
*/
#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << "\nEnter number : ";
    cin >> n;
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}