#include<iostream>
#include<string.h>
#include<cstring>

using namespace std;

int main() {

    // char S[50];
    // cout<< "Enter the name: " << S;
    // cin.get(S,50);

    // cout<< strlen(S)<< endl;

    // // dynamic memory allocation for strings
    // char *s;
    // s = new char[50];
    // cout<< "Enter the name: " << s;
    // cin.get(s,50);

    // cout<< strlen(s)<< endl;
    // delete [] s;

    // // concatanation of strings
    // char s1[50], s2[50];
    // cout<< "Enter the first name: " << s1;
    // cin.getline(s1,50);
    // cout<< "Enter the second name: " << s2;
    // cin.getline(s2,50);

    // strcat(s1, s2);
    // cout<< "Concatenated string: " << s1 << endl;

    // // concatanation of strings using length of string
    // char s3[50], s4[50];
    // cout<< "Enter the first name: " << s3;
    // cin.getline(s3,50);
    // cout<< "Enter the second name: " << s4;
    // cin.getline(s4,50);

    // strncat(s3, s4, 2);
    // cout<< "Concatenated string: " << s3 << endl;


    // // strstr function
    // char s5[50], s6[50];
    // cout<< "Enter the first name: " << s5;
    // cin.getline(s5,50);
    // cout<< "Enter the second name: " << s6;
    // cin.getline(s6,50);

    // char *ptr = strstr(s5, s6);
    // cout<< "Substring: " << ptr << endl;
    // if(ptr != NULL) {
    //     cout<< "Substring found at position: " << ptr - s5 << endl;
    // }
    // else {
    //     cout<< "Substring not found" << endl;
    // }

    // // strchar function (character search)
    // char s7[50];
    // cout<< "Enter the name: " << s7;
    // cin.getline(s7,50);

    // char *ptr1 = strchr(s7, 'a');
    // if(ptr1 != NULL) {
    //     cout<< "Character found at position: " << ptr1 - s7 << endl;
    // }
    // else {
    //     cout<< "Character not found" << endl;
    // }

    // //strcmp function (string comparison)
    // char s8[50], s9[50];
    // cout<< "Enter the first name: " << s8;
    // cin.getline(s8,50);
    // cout<< "Enter the second name: " << s9;
    // cin.getline(s9,50);

    // int result = strcmp(s8, s9);
    // if(result == 0) {
    //     cout<< "Strings are equal" << endl;
    // }
    // else if(result < 0) {
    //     cout<< "First string is less than second string" << endl;
    // }
    // else {
    //     cout<< "First string is greater than second string" << endl;
    // }


    // // strncmp function (string comparison with specified length)
    // char s10[50], s11[50];
    // cout<< "Enter the first name: " << s10;
    // cin.getline(s10,50);
    // cout<< "Enter the second name: " << s11;
    // cin.getline(s11,50);

    // int result1 = strncmp(s10, s11, 3);
    // if(result1 == 0) {
    //     cout<< "First 3 characters of strings are equal" << endl;
    // }
    // else if(result1 < 0) {
    //     cout<< "First 3 characters of first string are less than second string" << endl;
    // }
    // else {
    //     cout<< "First 3 characters of first string are greater than second string" << endl;
    // }


    // // strcpy function (string copy)
    // char s12[50], s13[50];
    // cout<< "Enter the name: " << s12;
    // cin.getline(s12,50);
    // strcpy(s13, s12);
    // cout<< "Copied string: " << s13 << endl;


    // // strtol function (long int conversion)
    // char s14[50];
    // cout<< "Enter the number: " << s14;
    // cin.getline(s14,50);
    // char *ptr2;
    // long int num = strtol(s14, &ptr2, 10);
    // if(*ptr2 == '\0') {
    //     cout<< "Converted number: " << num << endl;
    // }
    // else {
    //     cout<< "Invalid number" << endl;
    // }

    // // strtod function (double conversion)
    // char s15[50];
    // cout<< "Enter the number: " << s15;
    // cin.getline(s15,50);
    // char *ptr3;
    // double num1 = strtod(s15, &ptr3);
    // if(*ptr3 == '\0') {
    //     cout<< "Converted number: " << num1 << endl;
    // }
    // else {
    //     cout<< "Invalid number" << endl;
    // }

    // // strtof function  (float conversion)
    // char s16[50];
    // cout<< "Enter the number: " << s16;
    // cin.getline(s16,50);
    // char *ptr4;
    // float num2 = strtof(s16, &ptr4);
    // if(*ptr4 == '\0') {
    //     cout<< "Converted number: " << num2 << endl;
    // }
    // else {
    //     cout<< "Invalid number" << endl;
    // }


    // strtok function (tokenization of string)
    char s17[50];
    cout<< "Enter the string: " << s17;
    cin.getline(s17,50);

    char *token = strtok(s17, " =;");
    while(token != NULL) {
        cout<< token << endl;
        token = strtok(NULL, " =;");
    }
   
    // cout<< strtok(s17, " =;") << endl; // first token

    

    return 0;
}