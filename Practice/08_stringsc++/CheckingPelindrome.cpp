#include<iostream>
#include<string>

using namespace std;

int main() {

    string str;
    cout<< "Enter the string to check Pelindrome: ";
    getline(cin,str);

    string rev = "";

    for(int i=str.length()-1; i>=0; i--)
    {
        rev += str[i];
    }


    cout<< "Reverse of the string is: " << rev << endl;
    if(str == rev)
    {
        cout<< "The string is a Pelindrome." << endl;
    }
    else
    {
        cout<< "The string is not a Pelindrome." << endl;
    }


    return 0;
}