//Find factorial
#include <iostream>
using namespace std;
int main()
{
    int number, i = 1, product = 1;
    cout << "\n Enter number : ";
    cin >> number;
    for (i; i <= number; i++)
    {
        product *= i;
    }
    cout << "\n Factorial of " << number << " is : " << product;
    return 0;
}