// Program to replace every space in a string with a hyphen
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int i;
    char string[100];
    cout << "\nEnter string : ";
    cin.getline(string, 100);
    int length = strlen(string);
    for (i = 0; i < length; i++)
    {
        if (string[i] == ' ')
            string[i] = '-';
    }
    cout.write(string, length);

    return 0;
}