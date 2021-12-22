// Program to handle bank accounts of 10 customers
#include <iostream>
#include <string.h>
using namespace std;

class BankAccount
{
    string depositor_name;
    long int account_number;
    int time_period;
    double amount;

public:
    void enter();
    void display();
    void withdrawl_determiner();
};

void BankAccount ::enter()
{
    cout << "\n********** Enter Data **********";
    cout << "\nEnter Name : ";
    getline(cin, depositor_name);
    cout << "\nEnter Account number : ";
    cin >> account_number;
    cout << "\nEnter Time Period : ";
    cin >> time_period;
    cout << "\nEnter Amount : ";
    cin >> amount;
}

void BankAccount::display()
{
    cout << "\n********** Displaying Data **********";
    cout << "\nName : " << depositor_name;
    cout << "\nAccount Number : " << account_number;
    cout << "\nTime Period : " << time_period;
    cout << "\nAmount : " << amount;
    withdrawl_determiner();
}

void BankAccount::withdrawl_determiner()
{
    if (time_period >= 3)
        cout << "\nCan Withdraw !";
    else
        cout << "\nCannot Withdraw !";
}

int main()
{
    int n;
    cout << "\nEnter number of accounts : ";
    cin >> n;
    BankAccount accounts[n];
    for (int i = 0; i < n; i++)
    {
        accounts[i].enter();
        accounts[i].display();
    }
    return 0;
}