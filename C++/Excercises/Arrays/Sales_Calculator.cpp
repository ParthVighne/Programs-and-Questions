// Program to accept sales of each day of the month and print the total sales and average sales of the month.
#include <iostream>
using namespace std;

void entry(int n, float sales[]);
void display(int n, float sales[]);
float totalsales = 0;
float average = 0;

int main()
{
    int n;
    int month;
    cout << "\nEnter month (1,2. . .12) : ";
    cin >> month;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        n = 30;
    }
    else if (month == 2)
    {
        n = 28;
    }
    else
    {
        n = 30;
    }
    float sales[n];

    entry(n, sales);
    display(n, sales);

    return 0;
}

void entry(int n, float sales[])
{
    cout << "\nEnter sales : ";
    for (int i = 0; i < n; i++)
    {
        cout << "\nDay " << i + 1 << " : ";
        cin >> sales[i];
        totalsales += sales[i];
    }
    average = totalsales / n;
}

void display(int n, float sales[])
{
    cout << "\nDisplaying Sales : ";
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Day " << i + 1 << " : " << sales[i];
    }
    cout << endl
         << "Total sales : " << totalsales;
    cout << endl
         << "Average sales : " << average;
}