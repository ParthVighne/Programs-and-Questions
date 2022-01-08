#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    ofstream out;
    string s;
    cout << "\nEnter word : ";
    cin >> s;
    out.open("Example.txt");
    // out << "This is an example.\n";
    // out << "You are a genius !";
    out << s;
    out.close();

    ifstream in;
    string p;
    in.open("Example.txt");
    while (in.eof() == 0)
    {
        getline(in, p);
        cout << p;
    }
    in.close();
    return 0;
}