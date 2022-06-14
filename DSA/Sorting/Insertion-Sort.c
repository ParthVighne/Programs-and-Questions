#include <stdio.h>

void display(int a[], int n)
{
    printf("\n- - - - - Display - - - - \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n- - - - - - - - - - - - \n");
}

void insertionSort(int *A, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {100, 24, 14, 6, 67, 78, 33};
    int n = 7;
    display(A, n);
    insertionSort(A, n);
    display(A, n);
    return 0;
}