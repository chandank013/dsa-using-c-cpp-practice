#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int vowelCount = 0, ccount = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
           ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
        else if ((str[i]>= 'A' && str[i] <= 'Z') ||
                 (str[i] >= 'a' && str[i] <= 'z')) {
            // This condition is not necessary for counting vowels, but included for completeness
            // It can be used to handle other cases if needed
        } ccount++; 
    }
    
    cout << "Number of vowels in the string: " << vowelCount << endl;
    cout << "Total characters in the string: " << ccount << endl;
    cout << "Number of consonants in the string: " << (ccount - vowelCount) << endl;
    cout << "Number of non-alphabetic characters: " << (ccount - vowelCount) << endl;
    
    return 0;
}