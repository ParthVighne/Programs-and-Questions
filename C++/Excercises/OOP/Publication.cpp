/*
Imagine a publishing company that markets both books and audio-cassette versions of its works. Create a class
[publication] that stores the title(string) and price(float) of a publication.
From this class derive two classes : [book], which adds a page_count(int);and tape(float),which adds time duration in minutes.
Each of these three classes should have a getdata() functions to get its data rom the user, and a putdata() function to display its
data.

Write a main() program to test the book and tape classes by creating instances of them,asking the user to fill in their data with 
getdata(), and then dislaying the data with putdata().

*/

#include <iostream>
using namespace std;

class publication
{
    char title[31];
    float price;

public:
    void getdata()
    {
        cout << "\nEnter title : ";
        cin >> title;
        cout << "\nEnter price : ";
        cin >> price;
    }
    void putdata()
    {
        cout << "\nTitle : " << title;
        cout << "\nprice : " << price;
    }
};

class book : public publication
{
    int page_count;

public:
    void getdata()
    {
        publication::getdata();
        cout << "\nEnter number of pages : ";
        cin >> page_count;
    }
    void putdata()
    {
        publication::putdata();
        cout << "\nNumber of pages : " << page_count;
    }
};

class tape : public publication
{
    float time;

public:
    void getdata()
    {
        publication::getdata();
        cout << "\nEnter time duration in minutes : ";
        cin >> time;
    }
    void putdata()
    {
        publication::putdata();
        cout << "\nTime duration : " << time << " minutes";
    }
};

int main()
{
    char choice;
    bool a = true;
    while (a)
    {
        cout << "\nBook(b) or Tape(t) or exit(e): ";
        cin >> choice;
        switch (choice)
        {
        case 'b':
        {
            book b;
            b.getdata();
            b.putdata();
            break;
        }
        case 't':
        {
            tape t;
            t.getdata();
            t.putdata();
            break;
        }
        case 'e':
        {
            a = false;
            break;
        }
        default:
        {
            cout << "\nInvalid input";
            break;
        }
        }
    }

    return 0;
}