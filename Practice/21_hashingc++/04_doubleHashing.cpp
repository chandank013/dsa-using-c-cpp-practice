#include <iostream>
using namespace std;

#define SIZE 11      // Prime number
#define PRIME 7      // Largest prime smaller than SIZE

int Hash1(int key)
{
    return key % SIZE;
}

int Hash2(int key)
{
    return PRIME - (key % PRIME);
}

int Hash(int key, int i)
{
    return (Hash1(key) + i * Hash2(key)) % SIZE;
}

void Insert(int HT[], int key)
{
    int index = Hash1(key);

    if (HT[index] == 0)
    {
        HT[index] = key;
        return;
    }

    int i = 1;

    while (HT[Hash(key, i)] != 0)
    {
        i++;
    }

    HT[Hash(key, i)] = key;
}

int Search(int HT[], int key)
{
    int i = 0;
    int index;

    while (i < SIZE)
    {
        index = Hash(key, i);

        if (HT[index] == key)
            return index;

        if (HT[index] == 0)
            return -1;

        i++;
    }

    return -1;
}


void Delete(int HT[], int key)
{
    int index = Search(HT, key);

    if (index == -1)
    {
        cout << key << " not found.\n";
        return;
    }

    HT[index] = -1;        // Mark as deleted
    cout << key << " deleted successfully.\n";
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

    Insert(HT, 22);
    Insert(HT, 33);
    Insert(HT, 44);
    Insert(HT, 55);
    Insert(HT, 66);

    Display(HT);

    cout << "\nSearching 44 : " << Search(HT, 44) << endl;
    cout << "Searching 99 : " << Search(HT, 99) << endl;

    cout << "\nDeleting 33...\n";
    Delete(HT, 33);
    Display(HT);

    return 0;
}