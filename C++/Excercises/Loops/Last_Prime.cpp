//Write a program in C++ to find the last prime number occur before the entered number
#include <iostream>
using namespace std;
int main()
{
    int i, number, num;
    cout << "\n Enter number : ";
    cin >> number;
    for (num = number - 1; num > 1; num--)
    {
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (i == num)
        {
            cout << "\n Preceding prime number is : " << num;
            break;
        }
    }
    return 0;
}