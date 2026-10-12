
#include <iostream>
using namespace std;

class Element
{
public:
    int i, j, x;
};

class Sparse
{
public:
    int m, n, num;
    Element *e;

    // Default constructor
    Sparse()
    {
        m = n = num = 0;
        e = nullptr;
    }

    // Parameterized constructor
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[num];
    }

    // Function declarations
    void create();

    // Function to display the sparse matrix
    void display();

    // Destructor to free allocated memory
    ~Sparse()
    {
        delete[] e;
    }
};

// Function to create a sparse matrix
void Sparse::create()
{
    cout << "Enter the non-zero elements (row, column, value):" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> e[i].i >> e[i].j >> e[i].x;
    }
}

// Function to display the sparse matrix
void Sparse::display()
{
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k < num && i == e[k].i && j == e[k].j)
            {
                cout << e[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int m, n, num;

    cout << "Enter dimensions (rows and columns): ";
    cin >> m >> n;

    cout << "Enter the number of non-zero elements: ";
    cin >> num;

    Sparse s(m, n, num);

    s.create();
    s.display();

    return 0;
}
