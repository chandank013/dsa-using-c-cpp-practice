#include <iostream>
using namespace std;

#define SIZE 10

int Hash(int key)
{
    return key % SIZE;
}

void Insert(int HT[], int key)
{
    int index = Hash(key);
    int i = 0;

    while (HT[(index + i * i) % SIZE] != 0)
    {
        i++;
    }

    HT[(index + i * i) % SIZE] = key;
}

int Search(int HT[], int key)
{
    int index = Hash(key);
    int i = 0;

    while (HT[(index + i * i) % SIZE] != 0 && i < SIZE)
    {
        if (HT[(index + i * i) % SIZE] == key)
            return (index + i * i) % SIZE;

        i++;
    }

    return -1;
}

void Delete(int HT[], int key)
{
    int index = Search(HT, key);

    if (index != -1)
    {
        HT[index] = 0; // Mark as deleted
    }
}

void Display(int HT[])
{
    cout << "Index\tValue\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";

        if (HT[i] == 0)
            cout << "-";
        else
            cout << HT[i];

        cout << endl;
    }
}

int main()
{
    int HT[SIZE] = {0};

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 32);
    Insert(HT, 42);

    Display(HT);

    cout << "\n22 is at index " << Search(HT, 22) << endl;
    cout << "32 is at index " << Search(HT, 32) << endl;
    cout << "50 is at index " << Search(HT, 50) << endl;

    cout << "\nDeleting 22...\n";
    Delete(HT, 22);
    Display(HT);

    return 0;
}