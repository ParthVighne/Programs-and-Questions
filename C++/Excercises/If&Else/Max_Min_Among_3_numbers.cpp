//Max and min among 3 numbers
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, max = 0, min = 0;
    cout << "\nEnter first number : ";
    cin >> a;
    cout << "\nEnter second number : ";
    cin >> b;
    cout << "\nEnter third number : ";
    cin >> c;
    if (a > b && a > c) //a is greatest
    {
        max = a;
        if (b > c)
            min = c;
        else
            min = b;
    }
    else if (b > a && b > c) //b is greatest
    {
        max = b;
        if (a > c)
            min = c;
        else
            min = a;
    }
    else //c is greatest
    {
        max = c;
        if (a > b)
            min = b;
        else
            min = a;
    }
    cout << "\nMax : " << max;
    cout << "\nMin : " << min;
    return 0;
}