#include <iostream>

using namespace std;

class TriBandMatrix
{
    private:
        int n; // Size of the matrix
        int k; // Bandwidth
        int *A; // Pointer to the array

    public:
        TriBandMatrix(int size, int bandwidth);
        ~TriBandMatrix();
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};

// Default constructor
TriBandMatrix::TriBandMatrix()
{
    n = 0;
    k = 0;
    A = nullptr;
}

// Constructor to initialize the matrix size and bandwidth
TriBandMatrix::TriBandMatrix(int size, int bandwidth)
{
    n = size;
    k = bandwidth;
    A = new int[n * (k + 1)]; // Allocate memory for the banded matrix
}

// Destructor to free the allocated memory
TriBandMatrix::~TriBandMatrix()
{
    delete[] A; // Free the dynamically allocated memory
}

// Function to set the value at position (i, j)
void TriBandMatrix::set(int i, int j, int x)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (abs(i - j) > k)
    {
        cout << "Element is outside the bandwidth" << endl;
        return;
    }
    A[i * (k + 1) + (j - i + k)] = x; // Store the value in the banded matrix
}

// Function to get the value at position (i, j)
int TriBandMatrix::get(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
    {
        cout << "Index out of bounds" << endl;
        return 0; // Return 0 for out of bounds
    }
    if (abs(i - j) > k)
    {
        return 0; // Return 0 for elements outside the bandwidth
    }
    return A[i * (k + 1) + (j - i + k)]; // Retrieve the value from the banded matrix
}

// Function to display the matrix
void TriBandMatrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(i - j) > k)
            {
                cout << "0 "; // Print 0 for elements outside the bandwidth
            }
            else
            {
                cout << A[i * (k + 1) + (j - i + k)] << " "; // Print the value from the banded matrix
            }
        }
        cout << endl;
    }
}


int main()
{
    int size, bandwidth;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    cout << "Enter the bandwidth: ";
    cin >> bandwidth;

    TriBandMatrix matrix(size, bandwidth);

    // Set values in the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = max(0, i - bandwidth); j <= min(size - 1, i + bandwidth); j++)
        {
            int value;
            cout << "Enter value for element (" << i << ", " << j << "): ";
            cin >> value;
            matrix.set(i, j, value);
        }
    }

    // Display the matrix
    cout << "The tri-band matrix is:" << endl;
    matrix.display();

    return 0;
}