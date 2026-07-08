#include<iostream>
#include <string>

using namespace std;

int main()
{
  // Reverse a string using for loop
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);

    string rev = "";

    for(int i = str.length() - 1; i >= 0; i--)
    {
        rev += str[i];
    }

    cout << "Reversed string: " << rev << endl;


    
    // using two pointer approach
    string str2;
    cout << "Enter a string to reverse: ";
    getline(cin, str2);

    int i=0;
    int j=str2.length()-1;
    int t;

    for(; i<j; i++, j--)
    {
        t = str2[i];   // or we can use swap(str2[i], str2[j]);
        str2[i] = str2[j];
        str2[j] = t;
    }

    cout << "Reversed string: " << str2 << endl;

    return 0;
}