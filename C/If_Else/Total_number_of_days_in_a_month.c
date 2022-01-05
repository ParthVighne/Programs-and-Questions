#include <stdio.h>

int main()
{
    int number;
    printf("\nEnter month number : ");
    scanf("%d", &number);
    if (number == 1 || number == 3 || number == 5 || number == 7 || number == 8 || number == 10 || number == 12)
        printf("\nHas 31 days.");
    else if (number == 2)
        printf("\nHas 28 days.");
    else
        printf("\nHas 30 days.");

    return 0;
}