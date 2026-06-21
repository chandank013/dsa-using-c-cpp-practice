#include<iostream>
#include<string>

using namespace std;

int main() {

    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // Change cases of each character
    for(int i=0; i<str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';    // Mathematics of this is: 
                                            // 'a' - 'a' + 'A' = 'A'
                                            // 'b' - 'a' + 'A' = 'B'
                                            // and so on...
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';  // Mathematics of this is:
                                           // 'A' - 'A' + 'a' = 'a'
                                           // 'B' - 'A' + 'a' = 'b'
                                           // and so on...
        }
    }

    cout << "String with changed cases: " << str << endl;

    // logic by adding 32 to the ASCII value of uppercase letters to convert them to lowercase
    // and subtracting 32 from the ASCII value of lowercase letters to convert them to uppercase
    for(int i=0; i<str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;    // Mathematics of this is: 
                                            // 'a' - 32 = 'A'
                                            // 'b' - 32 = 'B'
                                            // and so on...
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // Mathematics of this is:
                                           // 'A' + 32 = 'a'
                                           // 'B' + 32 = 'b'
                                           // and so on...
        }
    }


    return 0;
}