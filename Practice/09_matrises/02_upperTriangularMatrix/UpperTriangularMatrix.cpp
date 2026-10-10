#include <iostream>
using namespace std;

class UpperTriangularMatrix
{
private:
    int n; // Size of the matrix
    int *A; // Pointer to the array that holds the upper triangular elements from column measure
public:
    UpperTriangularMatrix()
    {
        n = 2;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the upper triangular elements
    }
    UpperTriangularMatrix(int size)
    {
        n = size;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the upper triangular elements
    }

    ~UpperTriangularMatrix();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int GetDimension() { return n; } // Function to get the dimension of the matrix
};

// Function to set the value using row-major mapping
void UpperTriangularMatrix::set(int i, int j, int x)
{
    if (i <= j)
        A[j * (j-1)/2+i-1] = x; // Store only upper triangular elements
}

// Function to get the value using row-major mapping
int UpperTriangularMatrix::get(int i, int j)
{
    if (i <= j)
        return A[j * (j-1)/2+i-1]; // Return only upper triangular elements
    else
        return 0; // Non-diagonal elements are zero
}

// //Function to set the value using column-major mapping
// void UpperTriangularMatrix::set(int i, int j, int x)
// {
//     if (i <= j)
//         A[n * (i-1) - (i-2) * (i-1) / 2 + j - i] = x; // Store only upper triangular elements
// }

// //Function to get the value using column-major mapping
// int UpperTriangularMatrix::get(int i, int j)
// {
//     if (i <= j)
//         return A[n * (i-1) - (i-2) * (i-1) / 2 + j - i]; // Return only upper triangular elements
//     else
//         return 0; // Non-diagonal elements are zero
// }

void UpperTriangularMatrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << A[j * (j-1)/2+i-1] << " "; // Print Upper triangular elements
            else
                cout << "0 "; // Non-diagonal elements are zero
        }
        cout << endl;
    }
}

UpperTriangularMatrix::~UpperTriangularMatrix()
{
    delete[] A; // Free dynamically allocated memory
}


int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    UpperTriangularMatrix um(size);
    int x;
    cout << "Enter the upper triangular elements of the matrix:\n";
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cin >> x;
            um.set(i, j, x);
        }
    }
    cout << "Upper triangular matrix is:\n";
    um.display(); // Display the upper triangular matrix

    return 0;
}