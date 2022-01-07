// Just testing strucutres
#include <iostream>
using namespace std;

struct address
{
     int HouseNumber;
     char street[30];
     char city[30];
     char state[40];
     char country[40];
     void getData();
     void display();
};

void address ::getData()
{
     cout << "\nEnter house number : ";
     cin >> HouseNumber;
     cout << "\nEnter street : ";
     cin >> street;
     cout << "\nEnter city : ";
     cin >> city;
     cout << "\nEnter statr : ";
     cin >> state;
     cout << "\nEnter country : ";
     cin >> country;
     cout << endl
          << "-------------";
}

void address ::display()
{
     cout << "\n\t        DISPLAYING INFORMATION\n";
     cout << endl
          << "House Number : "
          << HouseNumber;
     cout << endl
          << "Street :  "
          << street;
     cout << endl
          << "city : "
          << city;
     cout << endl
          << "state : "
          << state;
     cout << endl
          << "country : "
          << country;
}

int main()
{
     struct address Parth;
     Parth.getData();
     Parth.display();
     return 0;
}