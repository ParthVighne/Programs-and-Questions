// Program to find number of vowels
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int count = 0;
    char string[100];
    cout << "\nEnter string : ";
    cin.getline(string, 100);
    for (int i = 0; string[i] != '\0'; i++)
    {
        switch (string[i])
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            count += 1;
        }
    }
    cout << "The total number of vowels : " << count;

    return 0;
}