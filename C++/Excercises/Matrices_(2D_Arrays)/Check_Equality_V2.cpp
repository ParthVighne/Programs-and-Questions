//Program to check equality of two matrices
#include <iostream>
using namespace std;

const int MAX = 3;

// int rows, columns;

class matrices
{
    int matrix[MAX][MAX];

public:
    void entry();
    void display();
    void compare(matrices a, matrices b);
};

void matrices ::entry()
{
    cout << "\nEnter Values For Matrix : \n "; //Entering values for matrix A
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " : ";
            cin >> matrix[i][j];
        }
    }
}

void matrices ::display()
{
    cout << "\n--------------Displaying--------------\n";
    cout << "\n Matrix : \n "; //Displaying values for matrix A
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " : ";
            cout << matrix[i][j];
            cout << endl;
        }
    }
}

void matrices ::compare(matrices a, matrices b)
{
    cout << "\n--------------Comparing------------"; //comparing
    bool flag = true;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (a.matrix[i][j] != b.matrix[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            break;
    }
    if (flag == false)
    {
        cout << "\n NOT IDENTICAL !";
    }
    else
    {
        cout << "\nIDENTICAL ! ";
    }
}

int main()
{
    cout << "\n<------ Disclaimer ------>";
    cout << "\nThese are 3x3 matrices.\n <---------------> ";
    matrices A, B;
    A.entry();
    B.entry();
    A.display();
    B.display();
    A.compare(A, B);

    return 0;
}
