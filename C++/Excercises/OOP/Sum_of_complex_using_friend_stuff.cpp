#include <iostream>
using namespace std;

class calculator;

class complex
{
    int real;
    int imaginary;
    friend calculator; //declaring the  whole class as a friend

public:
    void setValue()
    {
        cout << "\nEnter real part : ";
        cin >> real;

        cout << "\nEnter imaginary part : ";
        cin >> imaginary;
    };
    void showValue()
    {
        cout << "\nnumber : " << real << " + i" << imaginary << endl;
    }
};

class calculator
{
public:
    int addReal(complex a, complex b)
    {
        int RealSum = a.real + b.real;
        return RealSum;
    };
    int addImaginary(complex a, complex b)
    {
        int ImaginarySum = a.imaginary + b.imaginary;
        return ImaginarySum;
    };
};

int main()
{
    complex c1, c2;
    calculator calc;
    c1.setValue();
    c2.setValue();
    c1.showValue();
    c2.showValue();
    int r = calc.addReal(c1, c2);
    int i = calc.addImaginary(c1, c2);
    cout << "\nSum is : " << r << " + i" << i;
    return 0;
}