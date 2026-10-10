#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

// function for set row measure Upper triangular matrix
void set(struct Matrix *m, int i, int j, int x)
{
    if (i <= j) // Only set value if it's in the upper triangular part
    {
        m->A[m->n*(i-1)+(i-2)*(i-1)/2+j-i] = x; // Calculate the index for upper triangular matrix storage
    }
   
}

// function for set column measure Upper triangular matrix
void set_col(struct Matrix *m, int i, int j, int x)
{
    if (i <= j) // Only set value if it's in the upper triangular part
    {
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x; // Calculate the index for upper triangular matrix storage
    }
}

// function for get value from row measure Upper triangular matrix from row measure
int get(struct Matrix m, int i, int j)
{
    if (i <= j) // Only get value if it's in the upper triangular part
    {
        return m.A[m.n*(i-1)+(i-2)*(i-1)/2+j-i]; // Calculate the index for upper triangular matrix storage
    }
    else
    {
        return 0; // Return 0 for Upper triangular part
    }
}

// function for get value from column measure Upper triangular matrix
int get_col(struct Matrix m, int i, int j)
{
    if (i <= j) // Only get value if it's in the upper triangular part
    {
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]; // Calculate the index for upper triangular matrix storage
    }
    else
    {
        return 0; // Return 0 for lower triangular part
    }
}

void display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j) // Only display Upper triangular part
            {
                printf("%d ", m.A[m.n*(i-1)+(i-2)*(i-1)/2+j-i]); // Calculate the index for Upper triangular matrix storage
            }
            else
            {
                printf("0 "); // Display 0 for lower triangular part
            }
        }
        printf("\n");
    }
   
}

int main()
{
    struct Matrix m;
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n+1) / 2 * sizeof(int)); // Allocate memory for upper triangular matrix

    printf("Enter the elements of the upper triangular matrix:\n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            int x;
            scanf("%d", &x);
            set(&m, i, j, x); // Set value in the matrix
        }
    }
    printf("\n\n");

    printf("The upper triangular matrix is:\n");
    display(m); // Display the matrix
   
    free(m.A); // Free allocated memory
    printf("\n");

    return 0;
}

