// This program covers the basics of functions and function prototyping.
// Functions are kinda llike the building blocks of a program.
// Two Types : Built-In & User-Defined

#include <iostream>
using namespace std;

// Thees are function prototypes. Used when function is written below main().
int sum(int a, int b); // --> Acceptable
// int sum(int , int); --> Acceptable
// int sum(int a, b); --> Not Acceptable

void greeting();
//This is void datatype function. No need to return value.
//You can also see it does not have arguments, hence it just runs without any arguments.

int main()
{
    greeting();
    int number1, number2;
    // number1 and number2 are actual parameters
    cout << "\nEnter first number : ";
    cin >> number1;
    cout << "\nEnter second number : ";
    cin >> number2;
    cout << "\nThe sum is : " << sum(number1, number2);

    return 0;
}

int sum(int a, int b) // This is a user-defined function. If you write it below the main function,
                      // do not forget to use a functoin prototype ;)
{
    // a and b are formal parameters
    int c = a + b;
    return c;
}

void greeting()
{
    cout << "\n Good morning ! ";
}

/*
 * Possible Function Styles :
 * 
 * A) void function with no arguments
 *      Performs an independent task.
 *      Does not send or recieve arguments.
 *      Does not return any value.
 * 
 * B) Non-void functions with no arguments
 *      Takes no argument.
 *      Returns value.
 * 
 * C) void function with some arguments
 *      Does recieve arguments.
 *      Does not return value.
 * 
 * D) Non-void function with arguments
 *      Takes arguments.
 *      Returns value.
 */