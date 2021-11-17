/*Armstrong number is a number whos sum of cube of it's individual digits is the number itself
eg : 153
 */
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int number, lastdigit, sum = 0, n;
    cout << "\nEnter number : ";
    cin >> number;
    cout << endl;
    n = number;
    while (number > 0)
    {
        lastdigit = number % 10;
        sum += pow(lastdigit, 3);
        number = number / 10;
    }
    if (sum == n)
    {
        cout << "The number " << n << " is an armstrong number. ";
    }
    else
    {
        cout << "The number " << n << " is not an armstrong number. ";
    }
    return 0;
}