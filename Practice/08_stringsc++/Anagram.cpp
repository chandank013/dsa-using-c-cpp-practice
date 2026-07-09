#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    // Check if the two strings with no duplicates are anagrams using hashing technique 
    int alpha[26] = {0};  // Assuming ASCII character set
    for(int i=0; i<str1.length(); i++) {
        alpha[str1[i] - 'a']++;
    }

    for(int i=0; i<str2.length(); i++) {
        alpha[str2[i] - 'a']--;
    }

    bool isAnagram = true;
    for(int i=0; i<26; i++) {
        if(alpha[i] != 0) {
            isAnagram = false;
            break;
        }
    }

    if(isAnagram) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}