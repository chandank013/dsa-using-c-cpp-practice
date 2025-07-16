#include <iostream>
using namespace std;


// Function to reverse a string
void ReverseString(char *str, char *str1)
{
    int i, j;
    for(i=0; str[i]!='\0'; i++)
    {
    }
    i=i-1; // Adjust i to point to the last character

    for(j=0; i>=0; j++, i--)
    {
        str1[j] = str[i]; // Copy characters in reverse order
    } 
    str1[j] = '\0'; // Null-terminate the reversed string
}

// function for swapping the string
void  StringSwap(char *str)
{
    int i=0,j;
    for(j=0;str[j]!='\0';j++)
    {

    }j=j-1; // Adjust j to point to the last character

    while(i<j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

}


int main()
{
    char str[100]="Programming";
    char str1[100];

    /*int i, j;
    for(i=0; str[i]!='\0'; i++)
    {
    }
    i=i-1; // Adjust i to point to the last character

    for(j=0; i>=0; j++, i--)
    {
        str1[j] = str[i]; // Copy characters in reverse order
    } str1[j] = '\0'; // Null-terminate the reversed string

    cout << "Original string: " << str << endl;
    cout << "Reversed String: " << str1 << endl;*/

    ReverseString(str, str1);
    cout << "Original string: " << str << endl;
    cout << "Reversed String: " << str1 << endl;
    StringSwap(str);
    cout << "Swapped String: " << str << endl;

    
    return 0;
}