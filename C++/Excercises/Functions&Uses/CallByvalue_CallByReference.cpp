// This program explains "Call by value" & "Call by Reference"

/**
 * <--- Call By Value --->
 * 
 * Changes are not reflected.
 * Cannot alter the variables that are used to call the function.
 * This is because any change occures on the function's copy of the original value.

*/

/**
 * <--- Call By Reference --->
 * 
 * Changes are reflected back to the original values.
 * Used in situations where the values of the original variable are to be changedusing a function.

*/

#include <iostream>
using namespace std;

//Function Prototypes
void swap(int a, int b);
void swapPointer(int *a, int *b);
void swapReferenceVariable(int &a, int &b);

int main()
{
    int number1, number2;
    cout << "\nEnter first number : ";
    cin >> number1;
    cout << "\nEnter second number : ";
    cin >> number2;
    cout << "\nFirst number is : " << number1 << " Second number is : " << number2 << endl;

    cout << "\n--------Swapping-------- " << endl;

    /* 1 */ swap(number1, number2); //Call by value

    cout << "\n --> Swapped using call by value (Doesn't Work)" << endl;
    cout << "\nFirst number is : " << number1 << "      Second number is : " << number2 << endl;

    /* 2 */ swapPointer(&number1, &number2); // Call by reference using pointers

    cout << "\n --> Swapped using call by reference using pointers " << endl;
    cout << "\nFirst number is : " << number1 << "      Second number is : " << number2 << endl;

    /* 3 */ swapReferenceVariable(number1, number2); //Call by reference using C++ reference variables

    cout << "\n --> Swapped using call by reference using C++ reference variables " << endl;
    cout << "\nFirst number is : " << number1 << "      Second number is : " << number2 << endl;

    return 0;
}

void swap(int a, int b) //Call by value
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapPointer(int *a, int *b) //Call by reference using pointers
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapReferenceVariable(int &a, int &b) //Call by reference using C++ reference variables
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}