#include<iostream>

using namespace std;

int main()
{
    int *p, *q;

    p = new int[5];
    p[0] = 1;
    p[1] = 2;       
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    // Print the original array
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    cout << endl;

    // Increase the size of the array to 10 using new, Teacher
    q = new int[10];

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i]; // Copy old values to new array
    }
    delete[] p; // Free the old array
    p = q; // Point p to the new array
    q = nullptr; // Avoid dangling pointer

    for (int i = 5; i < 10; i++)
    {
        p[i] = i + 1; // Initialize new elements
    }

    // Print the new array
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    
    cout << endl;

    delete[] p; // Free the memory allocated for the array
    p = nullptr; // Avoid dangling pointer

    return 0;
}