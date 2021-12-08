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
};

int main()
{
     struct address Parth;
     cout << "\nEnter house number : ";
     cin >> Parth.HouseNumber;
     cout << "\nEnter street : ";
     cin >> Parth.street;
     cout << "\nEnter city : ";
     cin >> Parth.city;
     cout << "\nEnter statr : ";
     cin >> Parth.state;
     cout << "\nEnter country : ";
     cin >> Parth.country;
     cout << endl
          << "-------------\n";
     cout << "DISPLAYING INFORMATION :\n";
     cout << endl
          << "House Number : "
          << Parth.HouseNumber;
     cout << endl
          << "Street :  "
          << Parth.street;
     cout << endl
          << "city : "
          << Parth.city;
     cout << endl
          << "state : "
          << Parth.state;
     cout << endl
          << "country : "
          << Parth.country;

     return 0;
}