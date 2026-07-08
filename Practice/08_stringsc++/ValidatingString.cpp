#include<iostream>

using namespace std;

int valid(char *name) {
    int i;
    for(i=0; name[i]!='\0'; i++) {
        if(!((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z'))) {
            return 0; // Invalid character found
        }
    }
    return 1; // All characters are valid
}

int main()
{
    char name[100];
    cout << "Enter a string: ";
    cin.getline(name, 100);

    int isValid = valid(name);
    if (isValid) {
        cout << "The string is valid and contains only alphabets." << endl;
    } else {
        cout << "The string is invalid and contains non-alphabet characters." << endl;
    }
    return 0;
}