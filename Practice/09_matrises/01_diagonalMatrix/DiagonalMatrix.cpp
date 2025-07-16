#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int n; // Size of the matrix
    int *A; // Pointer to the array that holds the diagonal elements
public:
    DiagonalMatrix(int size)
    {
        n = size;
        A = new int[n]; // Dynamically allocate memory for the diagonal elements
        for (int i = 0; i < n; i++)
            A[i] = 0; // Initialize diagonal elements to zero
    }
    
    void set(int i, int j, int x)
    {
        if (i == j)
            A[i - 1] = x; // Store only diagonal elements
    }

    void get(int i, int j)
    {
        if (i == j)
            cout << A[i - 1] << " "; // Print only diagonal elements
        else
            cout << "0 "; // Non-diagonal elements are zero
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    cout << A[i - 1] << " "; // Print diagonal elements
                else
                    cout << "0 "; // Non-diagonal elements are zero
            }
            cout << endl;
        }
    }
    ~DiagonalMatrix()
    {
        delete[] A; // Free dynamically allocated memory
    }
};

int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    DiagonalMatrix m(size);
    int x;
    cout << "Enter the diagonal elements of the matrix:\n";
    for (int i = 1; i <= size; i++)
    {
        cin >> x;
        m.set(i, i, x); // Set diagonal elements
    }
    
    cout << "Diagonal matrix is:\n";
    m.display(); // Display the diagonal matrix

    return 0;
}