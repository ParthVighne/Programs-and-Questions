// Binary Coefficient => nCr
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
    int n, r;
    cout << "\nEnter n : ";
    cin >> n;
    cout << "\nEnter r : ";
    cin >> r;
    cout << "\nBinary coefficient is : ";
    int ans = factorial(n) / (factorial(n - r) * factorial(r));
    cout << ans;
    return 0;
}