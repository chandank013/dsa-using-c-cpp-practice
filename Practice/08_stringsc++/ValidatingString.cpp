#include<iostream>

using namespace std;

int main()
{
    // Validating a string to check if it contains only alphabets
    string str = "HelloWorld";
    bool isValid = true;

    for (char c : str) {
        if (!isalpha(c)) {
            isValid = false;
            break;
        }
    }
    if (isValid) {
        cout << "The string is valid and contains only alphabets." << endl;
    } else {
        cout << "The string is invalid and contains non-alphabet characters." << endl;
    }
    return 0;
}