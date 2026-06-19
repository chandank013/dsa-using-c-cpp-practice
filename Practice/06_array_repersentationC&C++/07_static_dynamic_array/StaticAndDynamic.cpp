#include<iostream>

using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Static array

    int *dynamicArr;
    dynamicArr = new int[5]; // Dynamic array

    // Initializing dynamic array
    for (int i = 0; i < 5; i++) {
        dynamicArr[i] = i + 1;
    }

    // Displaying static array
    cout << "Static Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Displaying dynamic array
    cout << "Dynamic Array: ";
    for (int i = 0; i < 5; i++) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    // Freeing the dynamically allocated memory
    delete[] dynamicArr;

    return 0;
}