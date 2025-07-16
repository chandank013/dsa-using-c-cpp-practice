#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x; // Store only diagonal elements
}

void get(struct Matrix m, int i, int j)
{
    if (i == j)
        printf("%d ", m.A[i - 1]); // Print only diagonal elements
    else
        printf("0 "); // Non-diagonal elements are zero
}

void display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i - 1]); // Print diagonal elements
            else
                printf("0 "); // Non-diagonal elements are zero
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i, x;
    printf("Enter the size of the matrix: ");
    scanf("%d", &m.n);

    printf("Enter the diagonal elements of the matrix:\n");
    for (i = 1; i <= m.n; i++)
    {
        scanf("%d", &x);
        set(&m, i, i, x); // Set diagonal elements
    }

    printf("Diagonal matrix is:\n");
    display(m); // Display the diagonal matrix

    return 0;
}


/*// Diagonal matrix using 2D array but not efficiend due to its time complexity

#include <stdio.h>

#define MAX 100

struct Matrix {
    int A[MAX][MAX];
    int n;
};

// Function to print diagonal elements
void printDiagonal(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Function to print lower triangular matrix
void printLowerTriangular(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Function to print upper triangular matrix
void printUpperTriangular(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.A[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i, j;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &m.n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            scanf("%d", &m.A[i][j]);
        }
    }

    printf("Diagonal elements of the matrix:\n");
    printDiagonal(m);

    printf("Lower triangular matrix:\n");
    printLowerTriangular(m);

    printf("Upper triangular matrix:\n");
    printUpperTriangular(m);

}*/