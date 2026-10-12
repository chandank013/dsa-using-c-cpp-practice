#include<iostream>
#include<climits>

using namespace std;

class TriDiagonalMatrix
{
private:
    int n; // Size of the matrix
    int *A; // Pointer to the array that holds the symmetric elements from column measure
public:
    // Default constructor
    TriDiagonalMatrix()
    {
        n = 2;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the symmetric elements
    }
    // Parameterized constructor
    TriDiagonalMatrix(int size)
    {
        n = size;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the symmetric elements
    }
    // Destructor
    ~TriDiagonalMatrix();

    // Function to set the value
    void set(int i, int j, int x);
    // Function to get the value
    int get(int i, int j);

    // Function to display the matrix
    void display();
    // Function to get the dimension of the matrix
    int GetDimension() { return n; } // Function to get the dimension of the matrix
};

// Function to set the value using diagonal mapping
void TriDiagonalMatrix::set(int i, int j, int x)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
        A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] = x; // Store only tri-diagonal elements
}

// Function to get the value using diagonal mapping
int TriDiagonalMatrix::get(int i, int j)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
        return A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i]; // Return only tri-diagonal elements
    else
        return 0; // Non-diagonal elements are zero
}

// Function to display the matrix using diagonal mapping
void TriDiagonalMatrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1 || i - j == 0 || i - j == -1)
                cout << A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] << " "; // Print tri-diagonal elements
            else
                cout << "0 "; // Non-diagonal elements are zero
        }
        cout << endl;
    }
}


// Function to set the value using row-major mapping
void TriDiagonalMatrix::set(int i, int j, int x)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
        A[j * (j - 1) / 2 + i - 1] = x; // Store only tri-diagonal elements
}

// Function to get the value using row-major mapping
int TriDiagonalMatrix::get(int i, int j)
{
    if (i - j == 1 || i - j == 0 || i - j == -1)
        return A[j * (j - 1) / 2 + i - 1]; // Return only tri-diagonal elements
    else
        return 0; // Non-diagonal elements are zero
}

// Function to display the matrix
void TriDiagonalMatrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1 || i - j == 0 || i - j == -1)
                cout << A[j * (j - 1) / 2 + i - 1] << " "; // Print tri-diagonal elements
            else
                cout << "0 "; // Non-diagonal elements are zero
        }
        cout << endl;
    }
}


// // Function to set the value using column-major mapping
// void TriDiagonalMatrix::set(int i, int j, int x)
// {
//     if (i - j == 1 || i - j == 0 || i - j == -1)
//         A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] = x; // Store only tri-diagonal elements
// }

// // Function to get the value using column-major mapping
// int TriDiagonalMatrix::get(int i, int j)
// {
//     if (i - j == 1 || i - j == 0 || i - j == -1)
//         return A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i]; // Return only tri-diagonal elements
//     else
//         return 0; // Non-diagonal elements are zero
// }

// // Function to display the matrix using column-major mapping
// void TriDiagonalMatrix::display()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i - j == 1 || i - j == 0 || i - j == -1)
//                 cout << A[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] << " "; // Print tri-diagonal elements
//             else
//                 cout << "0 "; // Non-diagonal elements are zero
//         }
//         cout << endl;
//     }
// }

// Destructor
TriDiagonalMatrix::~TriDiagonalMatrix()
{
    delete[] A; // Free the dynamically allocated memory
}

// Function to get the dimension of the matrix
int TriDiagonalMatrix::GetDimension()
{
    return n; // Return the dimension of the matrix
}

int main()
{
    int n;
    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    TriDiagonalMatrix T(n);

    cout << "Enter the elements of the matrix (only tri-diagonal elements):" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            T.set(i, j, x);
        }
    }

    cout << "The matrix is:" << endl;
    T.display();

    cout << "The dimension of the matrix is: " << T.GetDimension() << endl;

    return 0;
}