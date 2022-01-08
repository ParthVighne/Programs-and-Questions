#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string flight_number, name, destination, origin;
    char ans = 'y';

    ofstream enter;
    enter.open("Flight.txt");

    cout << "\n - - - - - - - E N T E R  D E T A I L S - - - - - - -\n";
    while (ans == 'Y' || ans == 'y')
    {
        cout << "\nFlight number : ";
        cin >> flight_number;
        cout << "\nPassenger Name : ";
        cin >> name;
        cout << "\nFlight from : ";
        cin >> origin;
        cout << "\nFlight to : ";
        cin >> destination;

        enter << "Flight number : " << flight_number << "\n";
        enter << "Passenger Name : " << name << "\n";
        enter << "Flight from : " << origin << "\n";
        enter << "Flight to : " << destination << "\n\n";

        cout << "\nDo you want to continue? Yes(y) or No(n) : ";
        cin >> ans;
    }
    enter.close();

    ifstream display;
    string disp;
    display.open("Flight.txt");

    cout << "\n - - - - - - - D I S P L Y I N G - - - - - - -\n";
    while (display.eof() == 0)
    {
        getline(display, disp);
        cout << disp << endl;
    }
    display.close();

    return 0;
}