#include <iostream>
using namespace std;
void fib(int num)
{
    int term1 = 0, term2 = 1, next = 0;
    for (int i = 1; i <= num; i++)
    {
        cout << term1 << ' ';
        next = term1 + term2;
        term1 = term2;
        term2 = next;
    }
    return;
}

int main()
{
    int n;
    cout << "\n Enter number of numbers : ";
    cin >> n;
    fib(n);
    return 0;
}