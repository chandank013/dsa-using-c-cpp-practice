#include<iostream>

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

    //function to add two sparse matrices
    Sparse add(Sparse &s);

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
            if (k < num && e[k].i == i && e[k].j == j)
            {
                cout << e[k].x << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Function to add two sparse matrices
Sparse Sparse::add(Sparse &s)
{
    if (m != s.m || n != s.n)
    {
        cout << "Matrices dimensions do not match for addition." << endl;
        return Sparse(0, 0, 0);
    }

    Sparse sum(m, n, num + s.num);
    int i = 0, j = 0, k = 0;

    while (i < num && j < s.num)
    {
        if (e[i].i < s.e[j].i || (e[i].i == s.e[j].i && e[i].j < s.e[j].j))
        {
            sum.e[k++] = e[i++];
        }
        else if (s.e[j].i < e[i].i || (s.e[j].i == e[i].i && s.e[j].j < e[i].j))
        {
            sum.e[k++] = s.e[j++];
        }
        else
        {
            sum.e[k] = e[i];
            sum.e[k++].x += s.e[j++].x;
            i++;
        }
    }

    while (i < num)
    {
        sum.e[k++] = e[i++];
    }

    while (j < s.num)
    {
        sum.e[k++] = s.e[j++];
    }

    sum.num = k; // Update the number of non-zero elements in the sum
    return sum;
}

int main()
{
    int m, n, num1, num2;

    cout << "Enter dimensions (rows and columns): ";
    cin >> m >> n;

    cout << "Enter the number of non-zero elements for first matrix: ";
    cin >> num1;
    Sparse s1(m, n, num1);
    s1.create();

    cout << "Enter the number of non-zero elements for second matrix: ";
    cin >> num2;
    Sparse s2(m, n, num2);
    s2.create();

    cout << "First Sparse Matrix:" << endl;
    s1.display();

    cout << "Second Sparse Matrix:" << endl;
    s2.display();

    Sparse sum = s1.add(s2);
    cout << "Sum of Sparse Matrices:" << endl;
    sum.display();

    return 0;
}