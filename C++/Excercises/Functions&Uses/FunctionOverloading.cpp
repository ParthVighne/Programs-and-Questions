/* When several function declarations are specified for a single function name in the  same scope, the fuction
 is said to be overloaded 
* For a funtion to be overloaded, it must have a unique signature.
* Signature refers to unique arguments
*/
#include <iostream>
using namespace std;

float sum(float a, float b);          //Two overloaded functions
float sum(float a, float b, float c); //Notice the different arguments

int main()
{
    float number1, number2, number3;

    cout << "Enter first number : ";
    cin >> number1;

    cout << "Enter second number : ";
    cin >> number2;

    cout << "Enter third number : ";
    cin >> number3;

    cout << "----------------------" << endl;

    cout << "Sum of " << number1 << " & " << number2 << " is : " << sum(number1, number2) << endl;

    cout << "Sum of " << number2 << " & " << number3 << " is : " << sum(number3, number2) << endl;

    cout << "Sum of " << number1 << " & " << number3 << " is : " << sum(number1, number3) << endl;

    cout << "Sum of all three numbers is : " << sum(number1, number2, number3);
    return 0;
}

float sum(float a, float b)
{
    return a + b;
}

float sum(float a, float b, float c)
{
    return a + b + c;
}
