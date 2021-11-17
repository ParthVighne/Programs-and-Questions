/*
input : 1234
output : 4321
*/
#include <iostream>
using namespace std;
int main()
{
    int reverse = 0, number, lastdigit;
    cout << "\n Enter a number : ";
    cin >> number;
    while (number > 0)
    {
        lastdigit = number % 10;
        reverse = reverse * 10 + lastdigit;
        number = number / 10;
    }
    cout << "\n Number is : " << reverse;
    return 0;
}