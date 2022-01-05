#include <stdio.h>

int main()
{
    int number;
    printf("\nEnter number :");
    scanf("%d", &number);
    if (number % 2 == 0)
        printf("Prime");
    else
        printf("Not Prime");
    return 0;
}