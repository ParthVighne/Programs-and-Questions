// Program to check if a string is palindrome or not 

#include<iostream>
#include<string.h>
using namespace std; 

int main()
{
    int i,flag=1; char string[100];
    cout<<"\nEnter string (Max. 100 characters): ";cin>>string;
    cout<<endl<<"-------Searching--------"<<endl;
    int length = strlen(string);
    for(int i=0,j=length-1;i<length;i++,j--)
    {
        if(string[i]!=string[j])
        {
            flag = 0;
        }
    }
    if(flag!=0)
    {
        cout<<"\n Palindrome ";
    }
    else
    cout<<"\n Not Palindrome";    

    return 0;
}