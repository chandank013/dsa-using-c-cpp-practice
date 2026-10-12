#include <iostream>

using namespace std;

class TriDiagonalMatrix
{
    private:
        int n;
        int *A;
    public:
        // Default constructor
        TriDiagonalMatrix()
        {
            n = 2;
            A = new int[3*n-2];
        }

        // Parameterized constructor
        TriDiagonalMatrix(int n)
        {
            this->n = n;
            A = new int[3*n-2];
        }
        
        // Destructor
        ~TriDiagonalMatrix()
        {
            delete []A;
        }
        
        // Member functions to set and get elements of the matrix
        void Set(int i, int j, int x);\
        int Get(int i, int j);

        // Function to display the matrix
        void Display();

        // Function to get the size of the matrix
        int Size()
        {
            return n;
        }
}

// Function to set the value of an element in the matrix
void TriDiagonalMatrix::Set(int i, int j, int x)
{
    if (i - j == 1)
        A[i - 2] = x; // Lower diagonal
    else if (i - j == 0)
        A[n - 1 + i - 1] = x; // Main diagonal
    else if (i - j == -1)
        A[2*n - 1 + i - 1] = x; // Upper diagonal
}

// Function to get the value of an element in the matrix
int TriDiagonalMatrix::Get(int i, int j)
{
    if (i - j == 1)
        return A[i - 2]; // Lower diagonal
    else if (i - j == 0)
        return A[n - 1 + i - 1]; // Main diagonal
    else if (i - j == -1)
        return A[2*n - 1 + i - 1]; // Upper diagonal
    else
        return 0; // Elements not in the tridiagonal positions are zero
}

// Function to display the matrix
void TriDiagonalMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << Get(i, j) << " ";
        }
        cout << endl;
    }
}

// Deconstructor to free the allocated memory
TriDiagonalMatrix::~TriDiagonalMatrix()
{
    delete []A;
}

// Function to get the size of the matrix
int TriDiagonalMatrix::Size()
{
    return n;
}

// Main function to demonstrate the usage of the TriDiagonalMatrix class
int main()
{
    int n;
    cout << "Enter the size of the tridiagonal matrix: ";
    cin >> n;

    TriDiagonalMatrix matrix(n);

    // Setting values in the tridiagonal matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1 || i - j == 0 || i - j == -1)
            {
                int value;
                cout << "Enter value for element (" << i << ", " << j << "): ";
                cin >> value;
                matrix.Set(i, j, value);
            }
        }
    }

    // Displaying the tridiagonal matrix
    cout << "The tridiagonal matrix is:" << endl;
    matrix.Display();

    return 0;
}