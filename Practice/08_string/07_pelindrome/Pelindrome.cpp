#include <iostream>
using namespace std;


// function for comparing two strings
void compareStrings(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            cout << "Strings are not equal" << endl;
            return;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl;
    }
}

// Function for checking if a string is palindrome or not
void isPalindrome(char str[])
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            cout << "Not a palindrome" << endl;
            return;
        }
    }
    cout << "Is a palindrome" << endl;
}



int main()
{
    char str[100]="Painter";
    char str1[100]="Painter";
    char str2[100]="naman";

    cout << "Comparing strings:" << endl;
    compareStrings(str, str1);

    cout << "Checking if strings are palindromes:" << endl;
    isPalindrome(str);
    isPalindrome(str2);

    return 0;
}