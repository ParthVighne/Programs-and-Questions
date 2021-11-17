/*
n = 9

. . . * . . . * . .                       *       *         
. . * . * . * . * .     OR              *   *   *   *
. * . * . * . * . *                   *   *   *   *   *

Herer (.) is space.

*/
#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "\nEnter number (must be multiple of 3) : ";
    cin >> n;
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= n; j++)
        {
            int sum = i + j;
            if ((sum % 4 == 0) || (i == 2 && j % 4 == 0))
            {
                cout << " *";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}