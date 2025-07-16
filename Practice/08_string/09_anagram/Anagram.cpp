#include <iostream>
using namespace std;

// function to check if two strings are anagrams by cheaking each character from another string
void checkAnagramByCount(char str[], char str1[])
{
    int count[256] = {0}; // Assuming ASCII characters

    for (int i = 0; str[i] && str1[i]; i++) {
        count[str[i]]++;
        count[str1[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            cout << "Not an anagram" << endl;
            return;
        }
    }
    cout << "Anagram" << endl;
}


int main()
{
    char str[100]="decimal";
    char str1[100]="medical";

    cout << "Checking anagram status by count:" << endl;
    checkAnagramByCount(str, str1);

    return 0;
}