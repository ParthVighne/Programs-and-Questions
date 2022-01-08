#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ans = 'Y';
    string name;
    float marks;

    //Entry

    ofstream file_out;                      //declaring object for writing
    file_out.open("Student.txt", ios ::in); //opening document

    cout << "\n - - - - - - - E N T E R  D E T A I L S - - - - - - -";
    do
    {
        cout << "\nEnter Name : "; //Entering name and marks
        cin >> name;
        cout << "\nEnter Marks : ";
        cin >> marks;

        file_out << name << " scored " << marks << " out of 100.\n"; //Writing as a string to document

        cout << "\nDo you want to enter more ? Yes(y) or No(n) : "; //asking wether to continue entering data
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');

    file_out.close(); // closing document

    // Display

    ifstream file_in;                      //declaring object for reading
    file_in.open("Student.txt", ios::out); //opening document

    cout << "\n - - - - - - - D I S P L Y I N G - - - - - - -\n";
    while (file_in.eof() == 0)
    {
        getline(file_in, name);
        cout << name << endl;
    }

    file_in.close(); //closing document
    return 0;
}