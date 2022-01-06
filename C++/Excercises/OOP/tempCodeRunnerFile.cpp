#include <iostream>
using namespace std;

class savings;
class current;

class account //Base class
{
    friend void MainMenu(savings, current);
    friend void SavingsMenu(savings);
    friend void CurrentMenu(current);

protected:
    char customer_name[31];
    long int account_number;
    float balance;

public:
    void getdata()
    {
        cout << "\nEnter name : ";
        cin >> customer_name;
        cout << "\nEnter account number (10 digits) : ";
        cin >> account_number;
        cout << "\nEnter balance : ";
        cin >> balance;
    }
    void showdata()
    {
        cout << "\nName : " << customer_name;
        cout << "\nAccount number : " << account_number;
        cout << "\nBalance : " << balance;
    }
};

class current : public account //Derived class -> Current
{
    friend void MainMenu(savings, current);
    friend void SavingsMenu(savings);
    friend void CurrentMenu(current);

public:
    void cheque_book()
    {
        cout << "\nAmount to pay : ";
        float cheque_amount;
        cin >> cheque_amount;
        if (balance <= 1000)
        {
            cout << "\nInsufficient funds. Minimum balance amount reached.";
        }
        else
            balance = balance - cheque_amount;
    }
    void deposit()
    {
        float amount;
        cout << "\nEnter amount to deposit : ";
        cin >> amount;
        balance = balance + amount;
    }

    void getdata()
    {
    account:
        getdata();
    }
};

class savings : public account // Derived class -> Savings
{
    friend void MainMenu(savings, current);
    friend void SavingsMenu(savings);
    friend void CurrentMenu(current);

public:
    void withdraw()
    {
        float amount;
        cout << "\nEnter amount to deposit : ";
        cin >> amount;
        balance = balance - amount;
    }

    void deposit()
    {
        float amount;
        cout << "\nEnter amount to deposit : ";
        cin >> amount;
        balance = balance + amount;
    }

    void getdata()
    {
    account:
        getdata();
    }
};