/*

n=5

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
#include <iostream>
using namespace std;

int factorial(int num)
{
    int product = 1;
    for (int i = 2; i <= num; i++)
    {
        product *= i;
    }
    return product;
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << factorial(i) / (factorial(j) * factorial(i - j)) << ' ';
        }
        cout << endl;
    }
    return 0;
}