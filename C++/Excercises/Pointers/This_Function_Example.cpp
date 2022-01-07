#include <iostream>
using namespace std;

class A
{
    int number;
    float decimal;

public:
    void setData(int number, float decimal)
    {
        this->number = number;
        this->decimal = decimal;
        // this is a pointer which points to the object (num). And hence when you use
        // this -> [data member].
        // It will point to every data member of the object.
    }
    void getData()
    {
        cout << "\nNumber is : " << number;
        cout << "\nDecimal is : " << decimal;
    }
};

int main()
{
    A num;
    num.setData(4, 4.4);
    num.getData();
    // cout << "Hello World.";
    return 0;
}