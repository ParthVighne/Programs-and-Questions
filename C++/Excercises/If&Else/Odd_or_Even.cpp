//Check odd or even
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter the number : ";
    cin >> n;
    if (n % 2 == 0)
        cout << "Even";
    else
        cout << "Odd";
    return 0;
}