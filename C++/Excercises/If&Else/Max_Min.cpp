//Find maximum and minimum among two numbers
#include <iostream>
using namespace std;

int main()
{
    int a, b, max, min;
    cout << "\n Enter first number : ";
    cin >> a;
    cout << "\n Enter second number : \n";
    cin >> b;
    if (a > b)
    {
        max = a;
        min = b;
    }
    if (a < b)
    {
        max = b;
        min = a;
    }
    cout << "\n Max : " << max;
    cout << "\n Min : " << min;

    return 0;
}
