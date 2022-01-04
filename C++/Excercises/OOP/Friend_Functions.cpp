// Example of friend functions
#include <iostream>
using namespace std;

class c1;
class c2;
void add(c1, c2);

class c1
{
    int value1;

public:
    void setValue1()
    {
        cout << "\nEnter value :";
        cin >> value1;
    };
    void showValue1()
    {
        cout << "Value is : " << value1 << endl;
    };
    friend void add(c1, c2);
};

class c2
{
    int value2;

public:
    void setValue2()
    {
        cout << "\nEnter value :";
        cin >> value2;
    };
    void showValue2()
    {
        cout << "Value is : " << value2 << endl;
    };
    friend void add(c1, c2);
};

void add(c1 a, c2 b)
{
    int sum = a.value1 + b.value2;
    cout << "\nSum is : " << sum;
}

int main()
{
    c1 a;
    a.setValue1();
    a.showValue1();

    c2 b;
    b.setValue2();
    b.showValue2();

    add(a, b);
    return 0;
}

/*Properties of Friend Functions : 
 * 
 * Not in the scope of class
 * Since it is not in the scope of the class, it cannnot be called by the objects of the class.
 * Can be invoked without the help of any object.
 * Usually contains objects as arguments.
 * Can be declared inside public and private sections of the class.
 * It cannot access the members directly by their names and need -> objectName.memberName to access any number.
*/
