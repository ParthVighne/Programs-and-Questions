/*
A college maintains a list of its students graduating every year. At the end of the year, the college
produces a report that lists the following :

Year -------------
Number of Working graduates : 
Number of Non-Working graduates : 
Details of the Top-Most Scorer : 
    Name          :
    Age           :
    Subject       :
    Average Marks :

x % of the graduates this year are non-working and n% are first divisioners.

Write a program for it that uses the following inheritance path : 
Person   --->        Student     --->   Graduate Student
(name,age)  (roll no,average marks)     (subject,employed)
*/
#include <iostream>
using namespace std;

// --------------------------------------------------

class Person // Base / Super-Class
{
protected:
    char name[31];
    int age;

public:
    void getdata();
    void showdata();
};

void Person ::getdata()
{
    cout << "\nEnter Name : ";
    cin >> name;
    cout << "\nEnter Age : ";
    cin >> age;
}

void Person ::showdata()
{
    cout << "\nName : " << name;
    cout << "\nAge : " << age;
}

// --------------------------------------------------

class Student : public Person // Derived Class from Base Class
{
protected:
    int roll_no;
    float marks[3];
    float average_marks;

public:
    void getdata();
    void showdata();
    float calcAverage();
};

void Student ::getdata()
{
    Person::getdata();
    cout << "\nEnter roll number : ";
    cin >> roll_no;
    cout << "\nEnter Marks in 3 subjects : ";
    for (int i = 0; i < 3; i++)
    {
        cin >> marks[i];
        cout << " , ";
    }
}

float Student ::calcAverage()
{
    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    average_marks = sum / 3;
    return average_marks;
}

void Student ::showdata()
{
    Person ::showdata();
    cout << "\nRoll number :" << roll_no;
    cout << "\nMarks in 3 subjects :";
    for (int i = 0; i < 3; i++)
    {
        cout << marks[i] << " , ";
    }
    cout << "\nAverage Marks :" << calcAverage();
}

// --------------------------------------------------

class Graduate : public Student //Derived class from derived class
{
protected:
    char subject[20];
    char working;

public:
    void getdata();
    void showdata();
    char check_working();
};

void Graduate ::getdata()
{
    Student ::getdata();
    cout << "\nEnter Subject : ";
    cin >> subject;
    cout << "\nWhether Working ( Yes(Y) or No(N) ) : ";
    cin >> working;
}

char Graduate ::check_working()
{
    return working;
}

void Graduate::showdata()
{
    Student::showdata();
    cout << "\nSubject : " << subject;
    cout << "\nWorking : " << check_working();
}

// --------------------------------------------------

int main()
{
    int n, year, working = 0, non_working = 0, total = 0 /*total students*/;
    int div1 = 0 /*number of first division students*/, number /*stores ith number of graduate*/;
    float topscore = 0 /*stores top score*/, score /*stores the average of the grad student*/;
    float working_percentage /*stores percentage of working*/;
    float non_working_percentage /*stores percentage of non-working*/;
    cout << "\nEnter number of Grad Students : ";
    cin >> n;
    Graduate grad[n];
    cout << "\nEnter year : ";
    cin >> year;

    //Entry - Loop for processing

    for (int i = 0; i < n; i++)
    {
        grad[i].getdata();
        total++;

        // Counting Working & non-working

        if (grad[i].check_working() == 'Y' || grad[i].check_working() == 'y')
            working++;
        else
            non_working++;

        // Top Scorer

        score = grad[i].calcAverage();
        if (score > topscore)
        {
            topscore = score;
            number = i;
        }

        // Number of First divisions

        if (score >= 70)
            div1++;
        cout << "\t --------------------";
    }

    //Print The Report

    cout << "\t -------------------- ";
    cout << "\nReport for the year : " << year << endl;
    cout << "\t -------------------- ";
    cout << "\nNumber of Working graduates : " << working;
    cout << "\nNumber of Non-Working graduates : " << non_working;
    cout << "\nDetails of the Top Scorer : " << endl;
    grad[number].showdata();
    working_percentage = (working / total) * 100;
    non_working_percentage = (non_working / total) * 100;
    cout << "\nPercentage of Working Graduates are : " << working_percentage;
    cout << "\nPercentage of Non-Working Graduates are : " << non_working_percentage;
    cout << "\nNumber of first divisioners are : " << div1;

    return 0;
}