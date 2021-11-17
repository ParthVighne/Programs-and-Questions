//Write a program in C++ to find the sum of digits of a given number
#include <iostream>
using namespace std;

int main()
{
    int remainder, number, num, sum = 0;
    cout << "\nEnter number : ";
    cin >> number;
    num = number;
    while (num > 0)
    {
        remainder = num % 10;
        num = num / 10;
        sum += remainder;
    }
    cout << sum;
}