#include<iostream>

using namespace std;

int main() {

    // char S[10]="Hello";
    // cout<< S<< endl;

    // char S1[10]={'H','E','L','L','O','\0'};
    // cout<< S1 << endl;

    // char S2[10]={65, 66, 67, 68, '\0'};  // we can write 0 at the place of '\0'
    // cout<< S2 << endl;

    char *S={"HELLO"};  // It will show the warning
    cout<< S << endl;


    string S1={"HELLO"};  // C++ 11 follow string class at the place of character pointer.
    cout<< S1 << endl;

    return 0;
}