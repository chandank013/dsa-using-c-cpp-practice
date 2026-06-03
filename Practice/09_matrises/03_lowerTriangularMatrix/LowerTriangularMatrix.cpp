#include <iostream>
using namespace std;

class LowerTriangularMatrix
{
private:
    int n; // Size of the matrix
    int *A; // Pointer to the array that holds the lower triangular elements
public:
    LowerTriangularMatrix()
    {
        n = 2;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the lower triangular elements
    }
    LowerTriangularMatrix(int size)
    {
        n = size;
        A = new int[n * (n + 1) / 2]; // Dynamically allocate memory for the lower triangular elements
    }
    
    ~LowerTriangularMatrix();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int GetDimension() { return n; } // Function to get the dimension of the matrix
};

void LowerTriangularMatrix::set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i-1)/2+j-1] = x; // Store only lower triangular elements
}

int LowerTriangularMatrix::get(int i, int j)
{
    if (i >= j)
        return A[i * (i-1)/2+j-1]; // Return only lower triangular elements
    else
        return 0; // Non-diagonal elements are zero
}

void LowerTriangularMatrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i * (i-1)/2+j-1] << " "; // Print lower triangular elements
            else
                cout << "0 "; // Non-diagonal elements are zero
        }
        cout << endl;
    }
}

LowerTriangularMatrix::~LowerTriangularMatrix()
{
    delete[] A; // Free dynamically allocated memory
}


int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    LowerTriangularMatrix lm(size);
    int x;
    cout << "Enter the lower triangular elements of the matrix:\n";
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> x;
            lm.set(i, j, x);
        }
    }
    cout << "Lower triangular matrix is:\n";
    lm.display(); // Display the lower triangular matrix

    return 0;
}