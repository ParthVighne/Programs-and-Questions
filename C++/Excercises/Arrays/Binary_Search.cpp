#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int element) //Searching algorithm as function
{
    int start = 0, end = n;
    while (start <= end) //Sorting
    {
        int mid = (start + end) / 2;
        if (arr[mid] == element)
        {
            cout << "\nElement Found @ position : ";
            return mid + 1;
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    int element;
    cout << "\nEnter number of elements : ";
    cin >> n;
    int arr[n];
    cout << endl;
    for (int i = 0; i < n; i++) //Entering values
    {
        cout << "\nEnter element no. " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "\n---------SORTING ARRAY------------\n";

    for (int i = 0; i < n - 1; i++) // Selection Sort
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

    cout << "Array after sorting : "; //Display after sorting
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nEnter element to be searched : "; //Entering element to be searched
    cin >> element;

    cout << BinarySearch(arr, n, element) << endl;

    return 0;
}