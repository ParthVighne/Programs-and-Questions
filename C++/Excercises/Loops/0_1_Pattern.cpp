/*

n = 5

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

*/
#include <iostream>
using namespace std;
int main()
{
    int n, i, j;
    cout << "\nEnter number : ";
    cin >> n;
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        for (int j = n; j > n - i; j--)
        {
            int sum = i + j;
            if (sum % 2 == 0) // sum is even
            {
                cout << " 1";
            }
            else // sum is odd
            {
                cout << " 0";
            }
        }
        cout << endl;
    }

    return 0;
}