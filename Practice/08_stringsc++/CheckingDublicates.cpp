#include<iostream>
#include<string>

using namespace std;

int main() {

    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // Check for duplicate characters in the string
    int length = str.length();
    bool hasDuplicate = false;

    for(int i=0; i<length; i++) {
        for(int j=i+1; j<length; j++) {
            if(str[i] == str[j]) {
                hasDuplicate = true;
                break;
            }
        }
        if(hasDuplicate) {  // If a duplicate is found, break the outer loop as well
            break;
        }
    }

    if(hasDuplicate) {
        cout << "The string has duplicate characters." << endl;
    } else {
        cout << "The string does not have duplicate characters." << endl;
    }

    // finding dublicates in string 
    for(int i=0; i<length; i++) {
        for(int j=i+1; j<length; j++) {
            if(str[i] == str[j]) {
                cout << "Duplicate character found: " << str[i] << endl;
                break;  // Break the inner loop after finding the first duplicate for this character
            }
        }
    }

    // checking dublicates in string using hashing technique
    int alpha[26] = {0};  // Assuming ASCII character set
    for(int i=0; i<length; i++) {
        alpha[str[i] - 'a']++;
    }

    for(int i=0; i<26; i++) {
        if(alpha[i] > 1) {
            cout << "Duplicate character found: " << char(i + 'a') << endl;
        }
    }


    // checking dublicates in string using bitwise operator
    long long int checker = 0;

    for(int i=0; i<length; i++) {
        int bitAtIndex = str[i] - 'a';

        if((checker & (1 << bitAtIndex)) > 0) {  // If bit is already set, then character is duplicate (Masking technique)
            cout << "Duplicate character found: " << str[i] << endl;
        } else {
            checker |= (1 << bitAtIndex);  // Set the bit for this character (Mersing technique)
        }
    }

    return 0;   
}