// Program to create two array to store roll numbers and marks of some students, whose number would be
// known at run time .

//!    Without static int count

// #include <iostream>
// using namespace std;

// class student
// {
//     int roll_no;
//     int marks;

// public:
//     void setData(int r, int m)
//     {
//         roll_no = r;
//         marks = m;
//     }
//     void getData()
//     {
//         cout << "Roll number : " << roll_no << endl;
//         cout << "Marks : " << marks << endl;
//     }
// };

// int main()
// {
//     int size = 2, i, p, q;
//     student *s = new student[size];
//     student *sTemp = s;
//     for (i = 0; i < size; i++)
//     {
//         cout << "\nEnter roll number & marks of student " << i + 1 << " : ";
//         cin >> p >> q;
//         s->setData(p, q);
//         s++;
//     }

//     for (i = 0; i < size; i++)
//     {
//         cout << "\nStudent : " << i + 1 << endl;
//         sTemp->getData();
//         sTemp++;
//     }

//     return 0;
// }

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

//!    With static int count

#include <iostream>
using namespace std;

class student
{
    int roll_no;
    int marks;
    static int count;

public:
    void setData(int r, int m)
    {
        roll_no = r;
        marks = m;
        count++;
    }
    void getData()
    {
        cout << "Roll number : " << roll_no << endl;
        cout << "Marks : " << marks;
    }
    static void getCount()
    {
        cout << "\nValue of count is : " << count << endl
             << endl;
    }
};

int student ::count = 100;

int main()
{
    int r, m;
    student s[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter roll number : ";
        cin >> r;
        cout << "\nEnter marks : ";
        cin >> m;
        cout << endl;
        s[i].setData(r, m);
        s[i].getData();
        student::getCount();
    }

    return 0;
}
