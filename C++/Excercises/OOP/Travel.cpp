#include <iostream>
#include <string.h>
using namespace std;

class Travel
{
private:
    char T_Code[5];
    int No_of_Adults;
    int No_of_Children;
    int Distance;
    float TotalFare;

public:
    Travel() //Default Constructor
    {
        strcpy(T_Code, "NULL");
        No_of_Adults = 0;
        No_of_Children = 0;
        Distance = 0;
        TotalFare = 0;
    };

    void AssignFare() //Fare Calculator
    {
        if (Distance >= 1000)
        {
            TotalFare = No_of_Adults * 500 + No_of_Children * 250;
        }
        else if (Distance < 1000 && Distance >= 500)
        {
            TotalFare = No_of_Adults * 300 + No_of_Children * 150;
        }
        else
        {
            TotalFare = No_of_Adults * 200 + No_of_Children * 100;
        }
    };

    void EnterTravel()
    {
        cout << "\nEnter of Travel Code : ";
        cin >> T_Code;
        cout << "\nEnter number of adults : ";
        cin >> No_of_Adults;
        cout << "\nEnter number of children : ";
        cin >> No_of_Children;
        cout << "\nEnter Distance : ";
        cin >> Distance;
        AssignFare();
    };

    void ShowTravel()
    {
        cout << "\nTravel Code : " << T_Code;
        cout << "\nNumber of adults : " << No_of_Adults;
        cout << "\nNumber of Children : " << No_of_Children;
        cout << "\nDistance : " << Distance;
        cout << "\nTotal Fare : " << TotalFare;
    };
};

int main()
{
    Travel T1;
    // T1.EnterTravel();
    T1.ShowTravel();
    return 0;
}