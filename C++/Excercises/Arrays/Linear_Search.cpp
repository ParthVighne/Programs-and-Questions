#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "\nEnter number of elements : ";
    cin >> n;
    int arr[n];
    cout << endl;
    for (int i = 0; i < n; i++) //Entering elements
    {
        cout << "\nEnter element no. " << i + 1 << " : ";
        cin >> arr[i];
    }
    int element;
    cout << "\nEnter element to search : "; // Enter item to be searched
    cin >> element;
    for (int i = 0; i <= n; i++) //Searching algorithm
    {
        if (element == arr[i])
        {
            cout << "\nElement found !" << endl;
            cout << "Position @ index no. : " << i + 1;
            break;
        }
        else if (i == n)
        {
            cout << "\nElement not found !" << endl;
        }
    }
    return 0;
}