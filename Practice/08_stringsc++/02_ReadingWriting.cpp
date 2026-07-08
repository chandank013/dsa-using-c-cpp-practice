#include<iostream>

using namespace std;

int main() {

    // char S[10];
    // cout<< "Enter the name: " << S;
    // cin>>S;
    // cout<< S<< endl;


    // During get function we cannot thke input of two consecutively name if want to take we have to add cin.ignore()
    char S[50];
    cout<< "Enter the name: " << S;
    cin.get(S,50);
    cout<< S<< endl;

    cin.ignore();   // To ignore the newline character left in the input buffer

    char S2[50];
    cout<< "Enter the name: " << S2;
    cin.get(S2,50);
    cout<< S2 << endl;


    // Directly take two consecutive name as input
    // char S1[50];
    // cout<< "Enter the name: " << S1;
    // cin.getline(S1,50);
    // cout<< S1<< endl;

    return 0;
}