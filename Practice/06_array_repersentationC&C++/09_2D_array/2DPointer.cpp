#include<iostream>

using namespace std;

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };


    // Accessing elements using array indexing
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int *A[3]; // Array of pointers to int
    A[0] = new int[4]{1, 2, 3, 4};
    A[1] = new int[4]{5, 6, 7, 8};
    A[2] = new int[4]{9, 10, 11, 12};

    // Accessing elements using pointer notation
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    /// using double pointer
    int **B = new int*[3]; // Array of pointers to int
    B[0] = new int[4]{1, 2, 3, 4};
    B[1] = new int[4]{5, 6, 7, 8};
    B[2] = new int[4]{9, 10, 11, 12};

    // Alternatively, you can use a loop to allocate memory for each row
    for (int i = 0; i < 3; i++) {
        B[i] = new int[4]{1, 2, 3, 4};
    }

    // Accessing elements using double pointer notation
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] B;

    return 0;
}