#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    char operation;
    int i;
    double num1, temp_num;
    cout << "\nEnter number : ";
    cin >> num1;
    while (operation != 'e')
    {

        cout << "\nAdd '+' , Subtract '-' , Multiply '*' , Divide '/' , Exponentiate '^' , SqaureRoot 's' , Exit 'e' : ";
        cout << "\nChoose operation : ";
        cin >> operation;
        switch (operation)
        {
        case '+': //sum
        {
            float sum = 0;
            cout << "\nEnter second number : ";
            cin >> temp_num;
            sum = num1 + temp_num;
            cout << "\nResult : " << sum << endl;
            num1 = sum;
        }
        break;

        case '-': //difference
        {
            float differnce = 0;
            cout << "\nEnter second number : ";
            cin >> temp_num;
            differnce = num1 - temp_num;
            cout << "\nResult : " << differnce << endl;
            num1 = differnce;
        }
        break;

        case '*': //product
        {
            float product = 0;
            cout << "\nEnter second number : ";
            cin >> temp_num;
            product = num1 * temp_num;
            cout << "\nResult : " << product << endl;
            num1 = product;
        }
        break;

        case '/': //divide
        {
            float quotient = 0;
            cout << "\nEnter second number : ";
            cin >> temp_num;
            quotient = num1 / temp_num;
            cout << "\nResult : " << quotient << endl;
            num1 = quotient;
        }
        break;

        case '^': //exponentiate
        {
            float power = 0;
            cout << "\nEnter exponent number : ";
            cin >> temp_num;
            power = pow(num1, temp_num);
            cout << "\nResult : " << power << endl;
            num1 = power;
        }
        break;

        case 's': // square root
        {
            float root = 0;
            root = sqrt(num1);
            cout << "\nResult : " << root << endl;
            num1 = root;
        }
        break;

        case 'e': //exit loop
        {
            operation = 'e';
        }
        break;

        default:
        {
            cout << "\nInvalid request ! " << endl;
        }
        break;
        }
    }

    return 0;
}