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
    return 0;
}