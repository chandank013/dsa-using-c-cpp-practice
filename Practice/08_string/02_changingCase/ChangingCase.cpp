#include <iostream>
using namespace std;



int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    // Changing case
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // Convert to lowercase
        } else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  // Convert to uppercase
        }
    }

    cout << "String after changing case: " << str << endl;
    return 0;
}