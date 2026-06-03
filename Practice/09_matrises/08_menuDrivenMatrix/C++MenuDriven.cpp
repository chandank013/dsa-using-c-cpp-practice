#include <iostream>
using namespace std;

class DiagonalMatrix {
private:
    int *A;
    int n;

public:
    // Constructor
    DiagonalMatrix(int size) {
        n = size;
        A = new int[n];  // Only n elements for the diagonal
    }

    // Destructor
    ~DiagonalMatrix() {
        delete[] A;
    }

    // Input diagonal elements
    void input() {
        cout << "Enter " << n << " diagonal elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
    }

    // Get value at (i, j)
    void get(int i, int j) {
        if (i >= 1 && i <= n && j >= 1 && j <= n) {
            if (i == j)
                cout << "Value: " << A[i - 1] << endl;
            else
                cout << "Value: 0\n";
        } else {
            cout << "Invalid indices! Must be between 1 and " << n << ".\n";
        }
    }

    // Set value at (i, j)
    void set(int i, int j, int value) {
        if (i >= 1 && i <= n && j >= 1 && j <= n) {
            if (i == j)
                A[i - 1] = value;
            else
                cout << "Only diagonal elements can be set in a diagonal matrix.\n";
        } else {
            cout << "Invalid indices! Must be between 1 and " << n << ".\n";
        }
    }

    // Display full matrix
    void display() {
        cout << "Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    cout << A[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

// Menu function
int menu() {
    int choice;
    cout << "\nMenu:\n";
    cout << "1. Input Diagonal Elements\n";
    cout << "2. Get Value at Index (i, j)\n";
    cout << "3. Set Value at Index (i, j)\n";
    cout << "4. Display Matrix\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Main function
int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Matrix size must be positive!\n";
        return 1;
    }

    DiagonalMatrix mat(n);
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1:
                mat.input();
                break;
            case 2: {
                int i, j;
                cout << "Enter indices (i j): ";
                cin >> i >> j;
                mat.get(i, j);
                break;
            }
            case 3: {
                int i, j, x;
                cout << "Enter row, column and value (i j x): ";
                cin >> i >> j >> x;
                mat.set(i, j, x);
                break;
            }
            case 4:
                mat.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
