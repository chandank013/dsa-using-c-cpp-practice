#include<iostream>

using namespace std;

int main()
{
    string s="welcome";

    // using for loop to traverse the string
    cout<< "Using for loop: ";
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;

    // Using iterator to traverse the string
    cout<< "Using iterator: ";
    for(string::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // Using reverse iterator to traverse the string in reverse order
    cout<< "Using reverse iterator: ";
    for(string::reverse_iterator it=s.rbegin();it!=s.rend();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // Using const iterator to traverse the string
    cout<< "Using const iterator: ";
    for(string::const_iterator it=s.cbegin();it!=s.cend();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // Using const reverse iterator to traverse the string in reverse order
    cout<< "Using const reverse iterator: ";
    for(string::const_reverse_iterator it=s.crbegin();it!=s.crend();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    // Using auto keyword to traverse the string (auto = string::iterator)
    cout<< "Using auto keyword: ";
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}