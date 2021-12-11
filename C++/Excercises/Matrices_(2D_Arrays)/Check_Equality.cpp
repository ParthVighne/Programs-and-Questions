//Program to check equality of two matrices
#include <iostream>
using namespace std;

int main()
{
    int rows, columns;
    cout << "\n<------ Disclaimer ------>";
    cout << "\nRows and columns of both matrices must be same.\n <---------------> ";
    cout << "\nEnter number of rows : ";
    cin >> rows;
    cout << "\nEnter number of columns : ";
    cin >> columns;
    int matrixA[rows][columns], matrixB[rows][columns];

    cout << "\nEnter Values For Matrix : 1\n "; //Entering values for matrix A
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " : ";
            cin >> matrixA[i][j];
        }
    }

    cout << "\nEnter Values For Matrix : 2\n "; //Entering values for matrix B
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " : ";
            cin >> matrixB[i][j];
        }
    }

    cout << "\n Matrix : 1\n "; //Displaying values for matrix A
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " : ";
            cout << matrixA[i][j];
            cout << endl;
        }
    }

    cout << "\n Matrix : 2\n "; //Displaying values for matrix B
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " : ";
            cout << matrixB[i][j];
            cout << endl;
        }
    }

    cout << "\n--------------Comparing------------"; //comparing
    bool flag = true;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrixA[i][j] != matrixB[i][j])
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

    return 0;
}