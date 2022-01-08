#include <iostream>
using namespace std;

template <class P, class Q>

class Base
{
protected:
    P data1;
    Q data2;

public:
    Base(P p, Q q) : data1(p), data2(q) {}
    void display()
    {
        cout << "\nThis is data1 : " << this->data1;
        cout << "\nThis is data2 : " << this->data2;
    }
};

int main()
{
    Base<bool, float> B1(true, 5.645);
    B1.display();
    return 0;
}