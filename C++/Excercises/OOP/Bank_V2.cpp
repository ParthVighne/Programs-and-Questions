/*
Assume that a bank maintains two kinds of accounts for customers, 
one called as savings account and the other as current account.
  The savings account provides simple interest and withdrawal facilities but not cheque book facilities. 
 The current account provides cheque booked facility but to no interest. 
   Current account holders should also maintain a minimum balance
 and if the balance falls below this level, a service charge is imposed. 

Create a class account() that stores Customer name, account number and opening balance.

From this derive the classes Current() and Saving() to make them more specific to their requirements. INclude necessary member functons
in order to achievethe following tasks
* deposit an amount for a customer and update the balance
* display the account details 
* withdraw amount for a customer after checking the balance and update the balance.
* check for the minimum balance(for current account holders ),impose penalty, if necessary and update the balance
*/

#include <iostream>
#include <string.h>
using namespace std;

class savings;
class current;
class account;

class account
{
protected:
    char customer_name[31];
    long int acc_number;
    float balance;

public:
    account() //default constructor
    {
        strcpy(customer_name, "Parth");
        acc_number = 123;
        balance = 10000;
    }
    void getdata()
    {
        cout << "\nEnter name : ";
        cin >> customer_name;
        cout << "\nEnter account number (10 digits) : ";
        cin >> acc_number;
        cout << "\nEnter balance : ";
        cin >> balance;
    }
    void showdata()
    {
        cout << "\nName : " << customer_name;
        cout << "\nAccount number : " << acc_number;
        cout << "\nBalance : " << balance;
    }
    float check_balance()
    {
        return balance;
    }
    void withdraw()
    {
        float amount;
        if (check_balance() <= 1000)
        {
            cout << "\nInsufficient Funds ! Balance is :" << check_balance();
        }
        else
        {
            cout << "\nEnter amount to with draw : ";
            cin >> amount;
            balance -= amount;
        }
    }
    void cheque()
    {
        float amount;
        if (check_balance() <= 1000)
        {
            cout << "\nInsufficient Funds ! Balance is :" << check_balance();
        }
        else
        {
            cout << "\nEnter amount to write cheque : ";
            cin >> amount;
            balance -= amount;
        }
    }
    void deposit()
    {
        float amount;
        cout << "\nEnter amount to deposit : ";
        cin >> amount;
        balance += amount;
    }
};

class savings : public account
{
public:
    void compound_interest()
    {
        float p, r;
        int t;
        cout << "\nPrinciple : ";
        cin >> p;
        cout << "\nRate : ";
        cin >> r;
        cout << "\nTime : ";
        cin >> t;
        cout << "\nSimle Interest : " << (p * r * t / 100);
    }
};

class current : public account
{
public:
    void min_balance_fine()
    {
        if (check_balance() < 1000)
        {
            cout << "\nFunds less than minimum balance, fine imposed of Rs.100";
            balance -= 100;
            cout << "\nCurrent Balance : " << check_balance();
        }
        else
            cout << "\nCurrent Balance : " << check_balance();
    }
};

void SavingsMenu(savings S)
{
    S.getdata();
    char choice;
    bool a = true;
    while (a)
    {
        cout << "\nWithdraw(w) or Deposit(d) or exit(any key) : ";
        cin >> choice;
        switch (choice)
        {
        case 'w':
        {
            S.withdraw();
            S.showdata();
            break;
        }
        case 'd':
        {
            S.deposit();
            S.showdata();
            break;
        }
        default:
        {
            a = false;
            break;
        }
        }
    }
}

void CurrentMenu(current C)
{
    C.getdata();
    char choice;
    bool a = true;
    while (a)
    {
        cout << "\nCheque(c) or Deposit(d) or Balance Check(b) or exit(any key) : ";
        cin >> choice;
        switch (choice)
        {
        case 'd':
        {
            C.deposit();
            C.showdata();
            break;
        }
        case 'c':
        {
            C.deposit();
            C.showdata();
            break;
        }
        case 'b':
        {
            C.min_balance_fine();
            break;
        }
        default:
        {
            a = false;
            break;
        }
        }
    }
}

void MainMenu()
{
    char choice;
    bool a = true;
    while (a)
    {
        cout << "\nSavings(s) or Current(c) or exit(any key) : ";
        cin >> choice;
        switch (choice)
        {
        case 's':
        {
            savings S1;
            SavingsMenu(S1);
            break;
        }
        case 'c':
        {
            current C1;
            CurrentMenu(C1);
            break;
        }
        default:
        {
            a = false;
            break;
        }
        }
    }
}

int main()
{
    MainMenu();
    return 0;
}