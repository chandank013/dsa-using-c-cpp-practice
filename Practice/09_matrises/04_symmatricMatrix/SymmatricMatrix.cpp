#include<iostream>
#include<climits>

using namespace std;

class SymmatricMatrix
{
private:
    int n; // Size of the matrix
    int *A; // Pointer to the array that holds the symmetric elements from column measure
public:
    // Default constructor
    SymmatricMatrix()
    {
        n = 2;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the symmetric elements
    }
    // Parameterized constructor
    SymmatricMatrix(int size)
    {
        n = size;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the symmetric elements
    }
    // Destructor
    ~SymmatricMatrix();

    // Function to set the value using row-major mapping
    void set(int i, int j, int x);
    // Function to get the value using row-major mapping
    int get(int i, int j);

    // Function to display the matrix
    void display();
    // Function to get the dimension of the matrix
    int GetDimension() { return n; } // Function to get the dimension of the matrix
};

// Function to set the value using row-major mapping
void SymmatricMatrix::set(int i, int j, int x)
{
    if (i <= j)
        A[j * (j - 1) / 2 + i - 1] = x; // Store only symmetric elements
    else
        A[i * (i - 1) / 2 + j - 1] = x; // Store only symmetric elements
}

// Function to get the value using row-major mapping
int SymmatricMatrix::get(int i, int j)
{
    if (i <= j)
        return A[j * (j - 1) / 2 + i - 1]; // Return only symmetric elements
    else
        return A[i * (i - 1) / 2 + j - 1]; // Return only symmetric elements
}

// Function to display the matrix using row-major mapping
void SymmatricMatrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << A[j * (j - 1) / 2 + i - 1] << " "; // Print symmetric elements
            else
                cout << A[i * (i - 1) / 2 + j - 1] << " "; // Print symmetric elements
        }
        cout << endl;
    }
}


// // Function to set the value using column-major mapping
// void SymmatricMatrix::set(int i, int j, int x)
// {
//     if (i <= j)
//         A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] = x; // Store only symmetric elements
//     else
//         A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = x; // Store only symmetric elements
// }

// // Function to get the value using column-major mapping
// int SymmatricMatrix::get(int i, int j)
// {
//     if (i <= j)
//         return A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i]; // Return only symmetric elements
//     else
//         return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j]; // Return only symmetric elements
// }

// // // Function to display the matrix using column-major mapping
// void SymmatricMatrix::display()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i <= j)
//                 cout << A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] << " "; // Print symmetric elements
//             else
//                 cout << A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " "; // Print symmetric elements
//         }
//         cout << endl;
//     }
// }

// Destructor to free the allocated memory
SymmatricMatrix::~SymmatricMatrix()
{
    delete[] A; // Free dynamically allocated memory
}

// Main function to demonstrate the usage of SymmatricMatrix class
int main()
{
    int size;
    cout << "Enter the size of the symmetric matrix: ";
    cin >> size;

    SymmatricMatrix sm(size);

    // Set values in the symmetric matrix
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            int value;
            cout << "Enter value for element (" << i << ", " << j << "): ";
            cin >> value;
            sm.set(i, j, value);
        }
    }

    // Display the symmetric matrix
    cout << "The symmetric matrix is:" << endl;
    sm.display();

    return 0;
}
