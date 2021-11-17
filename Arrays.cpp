#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "\nEnter number of elements : ";
    cin >> n;
    int arr[n]; //Always define array after number of elements is known.
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << endl
         << "Elements are : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
