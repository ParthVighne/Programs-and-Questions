// Program to calculate grades of 3 students from 4 test scores
#include <iostream>
using namespace std;

const int students = 3;
const int tests = 4;

class student
{
    int score[students][tests];
    float TotalMarks[students];

public:
    void entry();
    void display();
    void grade(int i);
};

void student ::entry()
{
    cout << "\n-----Entering----";
    for (int i = 0; i < students; i++) //Entry
    {
        int sum = 0;
        cout << "\nFor student number " << i + 1 << " : ";
        for (int j = 0; j < tests; j++)
        {
            cout << "\nTest " << j + 1 << " : ";
            cin >> score[i][j];
            sum += score[i][j];
            TotalMarks[i] = sum;
        }
    }
}

void student ::display()
{
    cout << "\n-----Displaying----";
    for (int i = 0; i < students; i++) //Display
    {
        cout << "\nStudent number " << i + 1 << " : ";
        for (int j = 0; j < tests; j++)
        {
            cout << "\nTest " << j + 1 << " : ";
            cout << score[i][j];
        }
        cout << "\nGrade is : ";
        grade(i);
    }
}

void student ::grade(int i)
{
    if (TotalMarks[i] >= 350)
    {
        cout << "A";
    }
    else if (TotalMarks[i] < 350 && TotalMarks[i] >= 250)
    {
        cout << "B";
    }
    else if (TotalMarks[i] < 250 && TotalMarks[i] >= 100)
    {
        cout << "C";
    }
    else
        cout << "D";
}

int main()
{
    student A;
    /* int student, test;
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
    */
    A.entry();
    A.display();
    return 0;
}
