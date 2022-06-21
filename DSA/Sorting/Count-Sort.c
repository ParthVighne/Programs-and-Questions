/*
#include <stdio.h>
#include <limits.h>

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j;
    // finding the biggest element in array
    int max = maximum(A, n); // size of count array

    // creating "count" array of size max
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // putting every element's value to 0
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Incrementing the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]]++; // the value in A is the index of count
    }

    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i] > 0) // if element in count has some iteration
        {
            A[j] = i;   // copy index of count i.e the value of element of count to array A
            j++;        // increment to next element in A
            count[i]--; // decrement the count of the element
        }
        else
            i++; // increment to next element in count
    }
}

void display(int A[], int n)
{
    printf("\n- - - - - - \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    display(A, n);
    countSort(A, n);
    display(A, n);
    return 0;
}
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void display(int *A, int n)
{
    printf("\n- - - - - \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int A[], int n)
{
    int i, j;

    int max = maximum(A, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[A[i]]++;

    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int A[] = {56, 22, 1, 78, 34, 2, 6, 7, 13, 59};
    int n = sizeof(A) / sizeof(A[0]);
    display(A, n);
    countSort(A, n - 1);
    display(A, n);
    return 0;
}