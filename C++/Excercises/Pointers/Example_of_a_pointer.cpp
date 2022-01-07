#include <iostream>
using namespace std;

// int main() //Simple Way of initializing a pointer
// {
//     int num = 6;
//     int *pointer = &num;
//     cout << "\nNumber " << *pointer;
//     return 0;
// }

int main() //Initializing pointer using new & delete
{
    //Use of new
    int *pointer = new int(69);
    cout << "\nNumber " << *pointer;
    //Use of delete
    delete pointer;
    cout << "\nNumber " << *pointer; // will give garbage value

    return 0;
}