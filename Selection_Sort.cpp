/*Find the minimum element in unsorted array and swap it with element at beginning

* elements get sorted from the start

eg: array => |12| , 45 , 23 , 51 , 19 , |8|

    iteration 1: 8 , |45| , 23 , 51 , 19 , |12| 
    iteration 2: 8 , 12 , |23| , 51 , |19| , 45
    iteration 3: 8 , 12 , 19 , |51| , |23| , 45
    iteration 4: 8 , 12 , 19 , 23 , |51| , |45|
    
    Result : 8 , 12 , 19 , 23 ,  45  ,  51
    
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "\nEnter number of elements : ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) //Entering elements
    {
        cout << "\nEnter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) //sorting (MAIN PART)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << "Array after sorting is : \n"; //Display
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
