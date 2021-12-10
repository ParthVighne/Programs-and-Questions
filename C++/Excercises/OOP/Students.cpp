/*Program to hold details of 5 students and provide the facility of viewing details of the topper as well as
of specific student by providing his/her roll number.*/
#include <iostream>
#include <string.h>

using namespace std;

int n; //for number of students

class student
{
private:
    char name[30];
    float marks[5];
    float totalmarks;

public:
    int rollnumber;
    void enter(void);
    void display(void);
    float total();
};

void student ::enter() //Enter information
{
    cout << "\n Enter Roll number : ";
    cin >> rollnumber;

    cout << "\n Enter Name : ";
    cin >> name;

    cout << "\n Enter Marks in 5 subjects: ";
    for (int i = 0; i < 5; i++)
    {
        cout << "\n Subject no. " << i + 1 << " : ";
        cin >> marks[i];
    }
    cout << "\n---------------------";
    totalmarks = total();
}

void student ::display() //Displaying information
{
    cout << "\n Roll number : " << rollnumber << "\tName : " << name << endl;

    cout << "\n Marks in 5 subjects : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\n Subject no. " << i + 1 << " : " << marks[i];
    }
    cout << "\n Total Marks : " << totalmarks << endl
         << "-------";
}

float student ::total() //Totaling marks
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    return sum;
}

int main() //Main
{
    cout << "\nEnter number of students : ";
    cin >> n;
    student students[n];
    cout << "\nEnter details of students  : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent number : " << i + 1 << endl;
        students[i].enter();
    }
    char ch;
    bool a = true;
    while (a) //Main menu
    {
        cout << "\nEnter choice display(a), search(by roll number) (b), topper(c), exit(d) : ";
        cin >> ch;
        switch (ch)
        {
        case 'a': //display
        {
            for (int i = 0; i < n; i++)
            {
                students[i].display();
            }
            break;
        }
        case 'b': //search
        {
            int tempRoll;
            bool s = false;
            cout << "\n Enter roll number to search : ";
            cin >> tempRoll;
            for (int i = 0; i < n; i++)
            {
                if (tempRoll == students[i].rollnumber)
                {
                    cout << "\n Entry Found !";
                    students[i].display();
                    s = true;
                    break;
                }
            }
            if (s == false)
                cout << "\n Entry NOT found.";
            break;
        }
        case 'c': //topper
        {
            float max = 0;
            int index;
            for (int i = 0; i < n; i++)
            {
                if (students[i].total() > max)
                {
                    max = students[i].total();
                    index = i;
                }
            }
            cout << "\n The topper is :";
            students[index].display();
            cout << endl;
            break;
        }
        case 'd': //end
        {
            a = false;
            break;
        }

        default: // invalid response
        {
            cout << "\nInvalid response !";
            break;
        }
        }
    }
    return 0;
}
