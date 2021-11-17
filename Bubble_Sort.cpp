/*Repeatedly swap two adjacent elements if they are in a wrong order

* elements get sorted from the back

eg: array => 12 , 45 , 23 , 51 , 19 , 8

    1) |12| , |45| ,  23  ,  51  ,  19  ,  08
        12  , |45| , |23| ,  51  ,  19  ,  08
        12  ,  23  , |45| , |51| ,  19  ,  08
        12  ,  23  ,  45  , |51| , |19| ,  08
        12  ,  23  ,  45  ,  19  , |51| , |08|
        12  ,  23  ,  45  ,  19  ,  08  ,  51
    
    2) |12| , |23| ,  45  ,  19  ,  08  ,  51
        12  , |23| , |45| ,  19  ,  08  ,  51
        12  ,  23  , |45| , |19| ,  08  ,  51
        12  ,  23  ,  19  , |45| , |08| ,  51
        12  ,  23  ,  19  ,  08  ,  45  ,  51
    
    3) |12| , |23| ,  19  ,  08  ,  45  ,  51
        12  , |23| , |19| ,  08  ,  45  ,  51
        12  ,  19  , |23| , |08| ,  45  ,  51
        12  ,  19  ,  08  ,  23  ,  45  ,  51
    
    4) |12| , |19| ,  08  ,  23  ,  45  ,  51
        12  , |19| ,  08  ,  23  ,  45  ,  51
        12  ,  08  ,  19  ,  23  ,  45  ,  51
    
    5) |08| , |12| ,  19  ,  23  ,  45  ,  51
        08  ,  12  ,  19  ,  23  ,  45  ,  51
    
    
    Result : 8 , 12 , 19 , 23 , 45 , 51
    
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

    for (int counter = 1; counter < n; counter++) //Sorting (MAIN PART )
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
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
