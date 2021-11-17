/*Find the minimum element in unsorted array and swap it with element at beginning

* elements get sorted from the start

eg: array =>      12  ,  45  ,  23  ,  51  ,  19  ,  08

    iteration 1: |12| , |45| ,  23  ,  51  ,  19  ,  08 
    iteration 2: |12| , |23| , |45| ,  51  ,  19  ,  08
    iteration 3: |12| , |23| , |45| , |51| ,  19  ,  08
    iteration 4: |12| , |19| , |23| , |45| , |51| ,  08
    iteration 5: |08| , |12| , |19| , |23| , |45| , |51| 
    
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

    for (int i = 1; i < n; i++) //sorting (MAIN PART)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    cout << "Array after sorting is : \n"; //Display
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
