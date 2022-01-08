#include <iostream>
using namespace std;

template <class V>

class vector
{
protected:
    V a;
    V b;

public:
    vector(V p, V q) : a(p), b(q) {}
    void display()
    {
        cout << "\nvector : " << a << "i + " << b << "j";
    }
    void dotProduct(vector p)
    {
        V dot = 0;
        cout << "\nProduct : " << a * p.a << "i +" << b * p.b << 'j';
    }
};

int main()
{
    vector<int> V1(3.6, 4.2);
    vector<int> V2(2.34, 3.8);
    V1.display();
    V2.display();
    V1.dotProduct(V2);

    return 0;
}