//  Create 2 classes

//   1.Simple Calculator - Takes inpt of 2 numbers using a utility function and performs +,-,*,/
//                        and displays the results using another function.
//   2.Scientific Calculator - Takes input of 2 numbers using a utility function and performs any four
//                             scientific operations and displays the results using another function.

//   Create another class HybridCalculator and inherit it using these 2 classes.

#include <iostream>
#include <math.h>
using namespace std;

class SimpleCalculator;
class ScientificCalculator;
class HybridCalculator;
void MainMenu(HybridCalculator);

int factorial(int n) //Friend Function
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

/*-------------------------------------------------------*/

class SimpleCalculator //Class SimpleCalculator
{
    friend int factorial();
    friend void MainMenu();
    friend void SimpCalc(HybridCalculator A);
    friend void SciCalc(HybridCalculator A);
    float r;

public:
    void add()
    {
        float num1, num2;
        cout << "\nEnter first number : ";
        cin >> num1;
        cout << "\nEnter second number : ";
        cin >> num2;
        r = num1 + num2;
        showSimpleCalc();
    }

    void subtract()
    {
        float num1, num2, result;
        cout << "\nEnter first number : ";
        cin >> num1;
        cout << "\nEnter second number : ";
        cin >> num2;
        r = num1 - num2;
        showSimpleCalc();
    }

    void multiply()
    {
        float num1, num2, result;
        cout << "\nEnter first number : ";
        cin >> num1;
        cout << "\nEnter second number : ";
        cin >> num2;
        r = num1 * num2;
        showSimpleCalc();
    }

    void divide()
    {
        float num1, num2, result;
        cout << "\nEnter first number : ";
        cin >> num1;
        cout << "\nEnter second number : ";
        cin >> num2;
        r = num1 / num2;
        showSimpleCalc();
    }

    void showSimpleCalc()
    {
        cout << "\nResult is :" << r;
    }
};

/*-------------------------------------------------------*/

class ScientificCalculator //Class ScientificCalculator
{
    friend int factorial(int n);
    friend void MainMenu();
    friend void SimpCalc(HybridCalculator A);
    friend void SciCalc(HybridCalculator A);
    float res;

public:
    void exponentiaite()
    {
        float num1, num2;
        cout << "\nEnter base number : ";
        cin >> num1;
        cout << "\nEnter power : ";
        cin >> num2;
        res = pow(num1, num2);
        showScientificCalc();
    }

    void logarithm()
    {
        float num1;
        cout << "\nEnter number : ";
        cin >> num1;
        res = log(num1);
        showScientificCalc();
    }

    void permutation()
    {
        float num1, num2, result;
        cout << "\nEnter total  : ";
        cin >> num1;
        cout << "\nEnter number of permutations : ";
        cin >> num2;
        res = (factorial(num1) / (factorial(num1 - num2)));
        showScientificCalc();
    }

    void combination()
    {
        float num1, num2, result;
        cout << "\nEnter total  : ";
        cin >> num1;
        cout << "\nEnter number of permutations : ";
        cin >> num2;
        res = (factorial(num1) / (factorial(num1 - num2) * factorial(num2)));
        showScientificCalc();
    }
    void showScientificCalc()
    {
        cout << "\nResult is :" << res;
    }
};

/*-------------------------------------------------------*/

class HybridCalculator : public SimpleCalculator, public ScientificCalculator //Multiply Inherited Class
{
    friend int factorial();
    friend void MainMenu();
    friend void SimpCalc(HybridCalculator A);
    friend void SciCalc(HybridCalculator A);

public:
    void ShowResult()
    {
        showSimpleCalc();
        showScientificCalc();
    }
};

/*-------------------------------------------------------*/

void MainMenu(HybridCalculator A)
{
    char Select_Calculator;
    bool ans = true;
    while (ans)
    {
        cout << "\nSelect Calculator ( Simple(s), Scientific(p) or exit(press any key)) : ";
        cin >> Select_Calculator;
        switch (Select_Calculator)
        {
        case 's': //Sub-Menu For Simple Calculator
        {
            // SimpCalc(A);
            char operation;
            cout << "\nChoose operation ( add(a), subtract(b), multiply(c), divide(d) ) : ";
            cin >> operation;
            switch (operation)
            {
            case 'a':
            {
                A.add();
                break;
            }
            case 'b':
            {
                A.subtract();
                break;
            }
            case 'c':
            {
                A.multiply();
                break;
            }
            case 'd':
            {
                A.divide();
                break;
            }
            default:
            {
                cout << "\nInvalid Opertaion";
                break;
            }
            }
            break;
        }

        case 'p': //Sub-Menu For Scientific Calculator
        {
            // SciCalc(A);
            char operation;
            cout << "\nChoose operation ( exponentiate(a), logarith(b), permutation(c), combinatin(d) ) : ";
            cin >> operation;
            switch (operation)
            {
            case 'a':
            {
                A.exponentiaite();
                break;
            }
            case 'b':
            {
                A.logarithm();
                break;
            }
            case 'c':
            {
                A.permutation();
                break;
            }
            case 'd':
            {
                A.combination();
                break;
            }
            default:
            {
                cout << "\nInvalid Opertaion";
                break;
            }
            }
            break;
        }

        default: //Exit
        {
            ans = false;
            break;
        }
        }
    }
}

int main()
{
    HybridCalculator H1;
    MainMenu(H1);
    return 0;
}
