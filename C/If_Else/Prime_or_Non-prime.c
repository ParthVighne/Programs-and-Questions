#include <stdio.h>

int main()
{
    int number;
    printf("\nEnter number :");
    scanf("%d", &number);
    if (number % 2 == 0)
        printf("Not Prime");
    else
        printf("Prime");
    return 0;
}