/*
Program to impleacent a "circle" class. Each object of this class will represent a circle,
storing its "radius" & the "x" and "y" coordinate of its centre as floats.
Include two access functions for : 
1) calculating area of circle
2) calculating the circumference of circle
*/
#include <iostream>
using namespace std;

// #define PI = 3.147;

class circle
{
    float radius;
    float x_axis;
    float y_axis;

public:
    void Enter_Info();
    void CalcArea();
    void CalcCircumference();
    void display();
};

void circle ::CalcArea()
{
    float area;
    area = 3.147 * radius * radius;
    cout << "\nArea : " << area;
}

void circle ::CalcCircumference()
{
    float circumference;
    circumference = 2 * 3.147 * radius;
    cout << "\nCircumference : " << circumference;
}

void circle ::Enter_Info()
{
    cout << "\nEnter x coordinate : ";
    cin >> x_axis;
    cout << "\nEnter y coordinate : ";
    cin >> y_axis;
    cout << "\nEnter radius : ";
    cin >> radius;
}

void circle ::display()
{
    cout << "\n Coordinates  : ( " << x_axis << " , " << y_axis << " )";
    cout << "\n Radius : " << radius;
    CalcArea();
    CalcCircumference();
}

int main()
{
    circle A;
    A.Enter_Info();
    A.display();
    return 0;
}