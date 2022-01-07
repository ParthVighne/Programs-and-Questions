/*
Program to read and display information about employees and managers. EMPLOYEE is a class that contains
->employee number 
-> name 
-> address 
-> department

Manager class contains all information of the employee class and a list of employees woking under a manager.
*/

#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
protected:
    int Emp_number;
    char name[31];
    char address[31];
    char department[31];

public:
    Employee()
    {
        Emp_number = 001;
        strcpy(name, "NULL");
        strcpy(address, "NULL");
        strcpy(department, "NULL");
    }

    Employee(int e, char n[], char a[], char d[])
    {
        Emp_number = e;
        strcpy(name, n);
        strcpy(address, a);
        strcpy(department, d);
    }

    void getdata()
    {
        cout << "\nEnter employee number :";
        cin >> Emp_number;
        cout << "\nEnter employee name :";
        cin >> name;
        cout << "\nEnter address :";
        cin >> address;
        cout << "\nEnter department :";
        cin >> department;
    }
    void showdata()
    {
        cout << "\n - - - - - - - - - - - ";
        cout << "\nEmployee number :" << Emp_number;
        cout << "\nEmployee name :" << name;
        cout << "\nEmployee address :" << address;
        cout << "\nEmployee department :" << department;
    }
};

class Manager : public Employee
{
protected:
    char ManagerName[31];

public:
    Manager()
    {
        Employee();
        strcpy(ManagerName, "NULL");
    }
    Manager(int e, char n[], char a[], char d[], char m[])
    {
        Employee(e, n, a, d);
        strcpy(ManagerName, m);
    }
    void getdata()
    {
        Employee ::getdata();
        cout << "\nEnter manager name : ";
        cin >> ManagerName;
    }
    void showdata()
    {
        Employee::showdata();
        cout << "\nManager name : " << ManagerName;
    }
};

int main()
{
    Manager M;
    M.getdata();
    M.showdata();
    return 0;
}