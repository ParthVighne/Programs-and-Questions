/*
* Write a declaration for a class PERSON which has the following : 
* data members -> name , phone 
* SET() & GET() functions for every data members
* a display function
* a destuctor

* 1) For the PERSON class above, write each of the constructors, the assignment operator, and the GETNAME() member function.
*    Use member initialization lists as often as possible.
* 2) Given the PERSON class above,write the declaration for a class SPOUSE that inherits from PERSON and does the following:
*   -> has an extra data member SPOUSENAME
*   -> redifines the display member function.
* 3) For the SPOUSE class above, write each of the construtors and the display member function. Use member initialization 
*    lists as often as possible.
*/
#include <iostream>
#include <string.h>
using namespace std;

class Person
{
protected:
    char name[31];
    long int phoneNumber;

public:
    Person() //Default Constructor
    {
        strcpy(name, "null");
        phoneNumber = 1111111111;
    }
    Person(char n[], long int p) //Parameterized constructor
    {
        strcpy(name, n);
        phoneNumber = p;
    }
    void getName()
    {
        cout << name;
    }
    void getdata()
    {
        cout << "\nEnter Name : ";
        cin >> name;
        cout << "\nEnter phone number : ";
        cin >> phoneNumber;
    }
    void display()
    {
        cout << "\nName : ";
        getName();
        cout << "\nPhone number : " << phoneNumber;
    }
};

class Spouse : public Person
{
protected:
    char spouseName[31];

public:
    void getdata()
    {
        Person::getdata();
        cout << "\nEnter Spouse Name : ";
        cin >> spouseName;
    }
    void display()
    {
        Person ::display();
        cout << "\nSpouse Name : " << spouseName;
    }
    Spouse() //Default Constructor
    {
        strcpy(name, "null");
        strcpy(spouseName, "null");
        phoneNumber = 1111111111;
    }
    Spouse(char n[], char sn[], long int num)
    {
        strcpy(name, "n");
        strcpy(spouseName, "sn");
        phoneNumber = num;
    }
};

int main()
{
    char a;
    cout << "\nAre you married yes(y) or no(n): ";
    cin >> a;
    switch (a)
    {
    case 'n':
    {
        Person P;
        P.getdata();
        P.display();
        break;
    }
    case 'y':
    {
        Spouse S;
        S.getdata();
        S.display();
        break;
    }
    default:
    {
        cout << "\nInvalid input !";
        break;
    }
    }
}