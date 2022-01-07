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
    // ! 1. Simple Way of initializing an object

    // A num;
    // num.setData(4, 4.4);
    // num.getData();

    // ! 2. Pointer Way of initializing an object

    // A *pointer = new A;
    // (*pointer).setData(4, 4.4); // (*pointer) is dereferencing the pointer
    // (*pointer).getData();

    // ! 3. Pointer Way of initializing an object using ( -> ) operator

    A *pointer = new A;
    pointer->setData(4, 4.4);
    pointer->getData();
    delete pointer;
    pointer->getData(); //will return garbage value as pointer is deleted
    return 0;
}