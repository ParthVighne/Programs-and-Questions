/*
n = 5

....1
...1 2
..1 2 3
.1 2 3 4 
1 2 3 4 5 

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
            cout << ' ';
        }
        for (j = 1; j <= i; j++)
        {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}