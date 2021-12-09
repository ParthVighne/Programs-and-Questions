/* C++ allows us to assign default value(s) to a function's parameter(s) which is usefull in case a matching 
 arguments is not passed in the function call statement.
 
 The default values are specified at the time of function declaration
 
 ! Any argument cannot have a default value unless all arguments appearing on ts right have their default values.
 ! That is : Write all default arguments on the RIGHT !
*/

#include <iostream>
using namespace std;

//float simpleinterest(float p, float t, float r = 6.5) //! --> legal

// float simpleinterest(float p, float t=2.4, float r = 6.5) //! --> legal

// float simpleinterest(float p=10000, float t=2.4, float r = 6.5) //! --> legal

// float simpleinterest(float p, float t=2.4, float r) //! --> illegal

// float simpleinterest(float p=10000, float t=2.4, float r ) //! --> illegal

float simpleinterest(float p, float t, float r = 6.5)
{
    return (p * t * r) / 100;
}

int main()
{
    float principal, rate, time;
    char answer;
    cout << "\nEnter principal : ";
    cin >> principal;
    cout << "\nEnter Time : ";
    cin >> time;
    cout << "\nDo you have a rate ( y/n ) : ";
    cin >> answer;
    if (answer == 'y')
    {
        cout << "\nEnter Rate : ";
        cin >> rate;
        cout << "\n-------------CALCULATING-------------\n";
        cout << "\nInterest is : " << simpleinterest(principal, time, rate);
    }
    else if (answer == 'n')
    {
        cout << "\nA default rate of 6.5% will be applied. ";
        cout << "\n-------------CALCULATING-------------\n";
        cout << "\nInterest is : " << simpleinterest(principal, time);
    }
    else
    {
        cout << "\nInvalid response ! A default rate of 6.5% will be applied. ";
        cout << "\n-------------CALCULATING-------------\n";
        cout << "\nInterest is : " << simpleinterest(principal, time);
    }

    return 0;
}
