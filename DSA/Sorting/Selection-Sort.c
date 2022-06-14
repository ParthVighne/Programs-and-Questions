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

void selectionSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexofMin])
            {
                indexofMin = j;
            }
        }
        int temp = A[i];
        A[i] = A[indexofMin];
        A[indexofMin] = temp;
    }
}

int main()
{
    int A[] = {100, 24, 14, 6, 67, 78, 33};
    int n = 7;
    display(A, n);
    selectionSort(A, n);
    display(A, n);
    return 0;
}