#include <iostream>
using namespace std;

int main() {

    char A[] = "Hello World";
    int wordCount = 0;
    bool inWord = false;

    for(int i = 0; A[i] != '\0'; i++) {
        if(A[i] == ' ' || A[i] == '\n' || A[i] == '\t') {
            if(inWord) {
                inWord = false; // We are now outside a word
            }
        } else {
            if(!inWord) {
                inWord = true; // We have found the start of a new word
                wordCount++;
            }
        }
    }

    int word = 1;
    for (int i = 0; A[i] != '\0'; i++) {
        if(A[i] == ' ' && A[i-1] != ' ') {
            word++;
        }
    }

    cout << "Number of words in the string: " << wordCount << endl;
    cout << "Number of words in the string: " << word << endl;
    return 0;
}