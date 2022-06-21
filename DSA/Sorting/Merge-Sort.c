/*#include <stdio.h>

void display(int A[], int n)
{
    printf("\n - - - - - - - \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
        A[i] = B[i];
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    display(A, n);
    mergeSort(A, 0, 6);
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

void merge(int A[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) // compare elements from both sub-Arrays and copy the smaller one to array B
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid) // copy rest elements to B
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high) // copy rest elements to B
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = 0; i <= high; i++) // copy B to A
        A[i] = B[i];
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {56, 22, 1, 78, 34, 2, 6, 7, 13, 59};
    int n = sizeof(A) / sizeof(A[0]);
    display(A, n);
    mergeSort(A, 0, n - 1);
    display(A, n);
    return 0;
}