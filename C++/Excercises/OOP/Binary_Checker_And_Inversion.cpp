#include <iostream>
#include <string>
using namespace std;

class binary //Declaring Class
{
private:
    string s;

public:
    void read(void);
    void write(void);
    void check_binary(void);
    void convertor(void);
};

void binary ::read() //Defining read() function
{
    cout << "\nEnter binary string : ";
    cin >> s;
    cout << endl;
}

void binary ::write() //Defining write() function
{
    cout << "\nBinary String : ";
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

void binary ::check_binary() //Defining check_binary() function
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "\nInvalid entry ! Digits not binary" << endl;
            exit(0);
        }
    }
}

void binary ::convertor() //Defining convertor() function
{
    cout << "\n----------Converting----------" << endl;
    check_binary();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
            s.at(i) = '1';
        else
            s.at(i) = '0';
    }
}

int main()
{
    binary a;
    a.read();
    a.write();
    a.convertor();
    a.write();
    return 0;
}