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

    // Find the next empty location
    while (HT[index] != 0)
    {
        index = (index + 1) % SIZE;
    }

    HT[index] = key;
}

int Search(int HT[], int key)
{
    int index = Hash(key);
    int start = index;

    while (HT[index] != 0)
    {
        if (HT[index] == key)
            return index;

        index = (index + 1) % SIZE;

        // Came back to starting position
        if (index == start)
            break;
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
    int *HT = new int[SIZE](); // Initialize hash table with zeros

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 32);
    Insert(HT, 25);

    Display(HT);

    cout << "\n22 is at index " << Search(HT, 22) << endl;
    cout << "25 is at index " << Search(HT, 25) << endl;
    cout << "50 is at index " << Search(HT, 50) << endl;

    Delete(HT, 22);
    cout << "\nAfter deleting 22:\n";
    Display(HT);

    delete[] HT; // Free the allocated memory

    return 0;
}