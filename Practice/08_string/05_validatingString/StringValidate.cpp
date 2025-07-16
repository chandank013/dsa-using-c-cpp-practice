#include <iostream>
using namespace std;

int valid(char *name)
{
    int i;
    for(i=0;name[i]!='\0';i++)
    {
        if (!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57) && name[i]!='_' && name[i]!=' ') 
        {
            return 0; // Invalid character found    

        }
    }
    return 1; // All characters are valid
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    if(valid(str)) {
        cout << "Valid string." << endl;
    } else {
        cout << "Invalid string." << endl;
    }
    
    
    return 0;
}