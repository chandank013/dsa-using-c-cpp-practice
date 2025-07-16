#include <iostream>
using namespace std;

// function for cheaking duplicate characters in a string by comparing each character to every other character
void checkDuplicateCharactersByComparison(char str[])
{
    int i, j;
    bool foundDuplicate = false;

    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                cout << "Character '" << str[i] << "' is duplicated at positions " << i << " and " << j << endl;
                foundDuplicate = true;
            }
        }
    }

    if (!foundDuplicate)
    {
        cout << "No duplicate characters found." << endl;
    }
}

// function for cheaking dublicate characters in a string using hash table
void checkDuplicateCharacters(char str[])
{
    int H[26]={0}, i ;
    for (i=0;str[i] != '\0'; i++)
    {
        H[str[i] - 97]+= 1 ;
    }
    for(i=0; i<26; i++)
    {
        if (H[i] > 1)
        {
            printf("Character %c is duplicated %d times\n", i + 97, H[i]);
        }
    }
}

// function to check duplicate characters in a string using bitwise operations
void checkDuplicateCharactersUsingBitwise(char str[])
{
    long int H=0,x=0;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        x=1;
        x = 1 << (str[i] - 97);
        if (H & x)
        {
            cout << "Character '" << str[i] << "' is duplicated." << endl;
        }
        else
        {
            H |= x;
        }
    }
}

int main()
{
    char str1[]="Painting";


    cout << "Checking duplicate characters in string 1 using comparison:" << endl;
    checkDuplicateCharactersByComparison(str1);

    cout << "Checking duplicate characters in string 1:" << endl;
    checkDuplicateCharacters(str1);

    cout << "Checking duplicate characters in string 1 using bitwise:" << endl;
    checkDuplicateCharactersUsingBitwise(str1);

    return 0;
}