/* program using a class to store price list of 10 items and to 
print the largest price as well as the sum of all prices.*/
#include <iostream>
#include <string>
using namespace std;

class pricelist
{
private:
    char item[10];
    float price[10];

public:
    void write();
    void enter();
    void largest_price();
    void sum();
};

void pricelist ::enter() //Entering data
{
    cout << "\n-------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\nEnter item name : ";
        cin >> item[i];

        cout << "\nEnter price : ";
        cin >> price[i];
        cout << endl;
    }
    cout << "\n_________________________";
}

void pricelist ::write() //Writing data
{

    cout << "\n-------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\n item name : " << item[i] << "\tPrice : " << price[i] << endl;
    }
    cout << "\n---------------------";
}

void pricelist ::largest_price() //Largest price
{
    float max = 0;
    int temp;
    cout << "\n-------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        if (price[i] > max)
        {
            max = price[i];
            temp = i;
        }
    }
    cout << "\nLargest Price is : " << item[temp] << " of Rs. " << price[temp] << endl;
}

void pricelist ::sum() //Sum
{
    float sum = 0;
    cout << "\n-------------------------\n";
    for (int i = 0; i < 10; i++)
    {
        sum += price[i];
    }
    cout << "\nSum of Price is : " << sum << endl;
}

int main() //main
{
    pricelist listA;
    char ch;
    bool a = true;
    cout << "\n**********Welcome**********\n";
    listA.enter();
    while (a) // Main menu
    {
        cout << "\nChoose display(a), largest price(b), sum(c), exit(d) : ";
        cin >> ch;

        switch (ch)
        {
        case 'a':
        {
            listA.write();
            a = true;
            break;
        }
        case 'b':
        {
            listA.largest_price();
            a = true;
            break;
        }
        case 'c':
        {
            listA.sum();
            a = true;
            break;
        }
        case 'd':
        {
            a = false;
            break;
        }

        default:
            cout << "\nInvalid response.";
            break;
        }
    }
    return 0;
}
