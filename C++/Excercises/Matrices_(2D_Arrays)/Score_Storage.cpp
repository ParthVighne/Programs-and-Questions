// Program to calculate grades of n students from m test scores
// ! NOT WORKING I DON'T KNOW WHY !!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
using namespace std;

int main()
{
    int student, test;
    float scores[student][test];
    cout << "\nEnter number of students : ";
    cin >> student;
    cout << "\nEnter number of tests : ";
    cin >> test;
    cout << "\nEnter Scores -> " << endl;

    cout << "\n-----Entering----";
    for (int i = 0; i < student; i++) //Entry
    {
        cout << "\nFor student number " << i + 1 << " : ";
        for (int j = 0; j < test; j++)
        {
            cout << "\nTest " << j + 1 << " : ";
            cin >> scores[i][j];
        }
    }

    cout << "\n-----Displaying----";
    for (int i = 0; i < student; i++) //Display
    {
        cout << "\nStudent number " << i + 1 << " : ";
        for (int j = 0; j < test; j++)
        {
            cout << "\nTest " << j + 1 << " : ";
            cout << scores[i][j];
        }
    }

    return 0;
}
