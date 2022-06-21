/*#include <stdio.h>

void display(int *A, int n)
{
    printf("\n - - - - - - - - - \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sorting left subarray
        quickSort(A, partitionIndex + 1, high); // sorting right subarray
    }
}

int main()
{
    int A[] = {100, 24, 14, 6, 67, 78, 33};
    int n = 7;
    display(A, n);
    quickSort(A, 0, n - 1);
    display(A, n);
    return 0;
}*/
#include <stdio.h>

void display(int *A, int n)
{
    printf("\n- - - - - \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low]; // pivot is the first element
    int i = low + 1;    // i will begin just after pivot
    int j = high;       // j will begin at last element
    int temp;           // temp variable for swapping

    do // do-while loop to loop until i>j
    {
        while (A[i] <= pivot) // to find A[i] greater than pivot
            i++;

        while (A[j] > pivot) // to find A[j] smaller than pivot
            j--;

        if (i < j) // after finding both above, if i<j, swap both elements
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

        // at last i > j and loop exits
    } while (i < j);

    // swap A[j] and element at pivot
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; //  return j as the index of partition
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sorting the left side
        quickSort(A, partitionIndex + 1, high); // sorting the right side
    }
}

int main()
{
    int A[] = {1, 56, 2, 0, 33, 42, 20, 16, 7};
    int n = 9;
    display(A, n);
    quickSort(A, 0, n - 1);
    display(A, n);
    return 0;
}