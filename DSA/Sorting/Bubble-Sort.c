#include <stdio.h>

void display(int *a, int n)
{
    printf("\n- - - - - - -");
    printf("\nSize : %d \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n- - - - - - -\n");
}

void bubblesort(int *a, int n)
{
    int temp;
    // first loop for number of passes i.e. n-1 passes for n elements
    for (int i = 0; i < n - 1; i++)
    {
        // second loop for comparisons i.e. n-1-i comparisons ,( passes - i)
        // that means for the zeroth pass n-1 comparisons (all elements compared)
        // for the first pass n-2 comparisons (all elements compared except the last)
        // for the second pass n-3 comparisons (all compared except last two)
        // for the third pass n-4 comparisons (all compared except last three)
        // and so on ....
        printf("\nPass no. : %d", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void adaptiveBubbleSort(int *a, int size) // if already sortd , then won's sort
{
    int temp;
    int isSorted;
    for (int i = 0; i < size - 1; i++)
    {
        printf("\nPass no. : %d", i + 1);
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
            else
                isSorted = 1;
        }
        if (isSorted)
            return;
    }
}

int main()
{
    int arr[] = {1, 55, 6, 2, 63, 54, 5, 60, 7, 0};
    int size = sizeof(arr) / sizeof(arr[0]); // size of array
    display(arr, size);
    bubblesort(arr, size);
    display(arr, size);
    adaptiveBubbleSort(arr, size);
    display(arr, size);

    return 0;
}