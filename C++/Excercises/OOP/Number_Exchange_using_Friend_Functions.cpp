#include <iostream>
using namespace std;

class c1;
class c2;
void exchange(c1 &, c2 &);

class c1
{
    int val1;
    friend void exchange(c1 &, c2 &); // declaring friend

public:
    void setVal1()
    {
        cout << "\nEnter first value : ";
        cin >> val1;
    };
    void showVal1()
    {
        cout << "\nValue of first number : " << val1;
    };
};

class c2
{
    int val2;
    friend void exchange(c1 &, c2 &); // declaring friend

public:
    void setVal2()
    {
        cout << "\nEnter second value : ";
        cin >> val2;
    };
    void showVal2()
    {
        cout << "\nValue of second number : " << val2;
    };
};

void exchange(c1 &a, c2 &b)
{
    int temp;
    temp = a.val1;
    a.val1 = b.val2;
    b.val2 = temp;
}

int main()
{
    c1 x;
    x.setVal1();
    c2 y;
    y.setVal2();
    cout << "\n------Before Exchange-------";
    x.showVal1();
    y.showVal2();

    exchange(x, y);

    cout << "\n------After Exchange-------";
    x.showVal1();
    y.showVal2();

    return 0;
}