/*Program that invokes a function calc() which intakes 
two integers and an arithematic operator and prints the corresponding result */
#include <iostream>
using namespace std;

void calc(float a, float b, char o);

int main()
{
    float number1, number2;
    char op, choice;
    bool a = true;
    while (a)
    {
        cout << "\nChoose to restart(r) or exit(e) : ";
        cin >> choice;
        switch (choice)
        {
        case 'r':
        {
            cout << "\nEnter first number : ";
            cin >> number1;
            cout << "\nEnter operator ( + , - , * , / : ";
            cin >> op;
            cout << "\nEnter second number : ";
            cin >> number2;
            calc(number1, number2, op);

            break;
        }
        case 'e':
        {
            a = false;
            break;
        }

        default:
        {
            cout << "\nInvalid Response.";
            break;
        }
        }
    };
    return 0;
}

void calc(float a, float b, char o) //calculator function
{
    switch (o)
    {
    case '+':
    {
        cout << "\nResult : " << a + b;
        break;
    }

    case '-':
    {
        cout << "\nResult : " << a - b;
        break;
    }

    case '*':
    {
        cout << "\nResult : " << a * b;
        break;
    }

    case '/':
    {
        cout << "\nResult : " << a / b;
        break;
    }

    default:
    {
        cout << "\nInvalid response .";
        break;
    }
    }
}