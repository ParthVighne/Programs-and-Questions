// Defining a class Flight with the following specifications
// Data Memebers : int flightNumber, string Destination,float Distance,float Fuel
// Member Fuctions : CalFuel()
//                  Distance                Fuel
//                   <=1000                 500
//                >1000 & <=2000            1100
//                    >2000                 2200
// Public Members :
// Feed_Info()
// Calc Fuel
#include <iostream>
#include <string.h>
using namespace std;

class Flight
{
    int FlightNumber;
    string Destination;
    float Distance;
    float Fuel;

public:
    void Feed_Info();
    void Calc_Fuel();
    void Show_Info();
};

void Flight ::Feed_Info()
{
    cout << "\nEnter Flight Number : ";
    cin >> FlightNumber;
    cout << "\nEnter Destination : ";
    cin >> Destination;
    cout << "\nEnter Distance : ";
    cin >> Distance;
}

void Flight::Calc_Fuel()
{
    if (Distance <= 1000)
        Fuel = 500;
    else if (Distance > 1000 && Distance <= 2000)
        Fuel = 1100;
    else
        Fuel = 2200;

    // cout << "\nAmount of fuel required : " << Fuel << " kilograms";
}

void Flight::Show_Info()
{
    cout << "\n --------Displaying--------\n";
    cout << "\n Flight Number : " << FlightNumber;
    cout << "\n Destination : " << Destination;
    cout << "\n Distance : " << Distance;
    cout << "\n Fuel : " << Fuel;
}

int main()
{
    Flight A;
    A.Feed_Info();
    A.Calc_Fuel();
    A.Show_Info();
    return 0;
}