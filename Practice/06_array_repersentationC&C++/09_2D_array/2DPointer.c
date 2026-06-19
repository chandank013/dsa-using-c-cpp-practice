#include <stdio.h>
#include <stdlib.h>

// Total three ways to create 2D array in C

int main()
{
    // 01 Creating an array in stack
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};

    // 02 Creating array in heap in 02 we take single pointer 
    int *B[3];
    int **C;
    int i, j;

    // 02 Creating array in heap
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));


    // Initializing array B
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            B[i][j] = i + j; // Example initialization
        }
    }

     // Printing array B
     printf("Array B:\n");
     for (i = 0; i < 3; i++)
     {
         for (j = 0; j < 4; j++)
         {
             printf("%d ", B[i][j]);
         }
         printf("\n");
     }

    // Freeing allocated memory for B
    for (i = 0; i < 3; i++)
    {
        free(B[i]);
    }


      // 03 Creating array in heap. we take double pointer
      C = (int **)malloc(3 * sizeof(int *));
      C[0] = (int *)malloc(4 * sizeof(int));
      C[1] = (int *)malloc(4 * sizeof(int));
      C[2] = (int *)malloc(4 * sizeof(int));

    // Initializing array C
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            C[i][j] = i * j; // Example initialization
        }
    }



    // Printing array C
    printf("Array C:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Freeing allocated memory
    for (i = 0; i < 3; i++)
    {
        free(C[i]);
    }
    free(C);

    return 0;
}




// int main()
// {
    
//     // creating 1D array in stack
//     int A[5];

//     // creating 2D array in stack
//     int B[3][4];

//     // creating 3D array in stack
//     int C[3][4][5];

//     // creating 1D array in heap
//     int *A;
//     A = (int *)malloc(5 * sizeof(int));

//     // creating 2D array in heap
//     int **B;
//     B = (int **)malloc(3 * sizeof(int *));
//     B[0] = (int *)malloc(4 * sizeof(int));
//     B[1] = (int *)malloc(4 * sizeof(int));
//     B[2] = (int *)malloc(4 * sizeof(int));

//     // creating 3D array in heap
//     int ***C;
//     C = (int ***)malloc(3 * sizeof(int **));
//     C[0] = (int **)malloc(4 * sizeof(int *));
//     C[1] = (int **)malloc(4 * sizeof(int *));
//     C[2] = (int **)malloc(4 * sizeof(int *));
//     C[0][0] = (int *)malloc(5 * sizeof(int));
//     C[0][1] = (int *)malloc(5 * sizeof(int));
//     C[0][2] = (int *)malloc(5 * sizeof(int));
//     C[0][3] = (int *)malloc(5 * sizeof(int));
//     C[1][0] = (int *)malloc(5 * sizeof(int));
//     C[1][1] = (int *)malloc(5 * sizeof(int));
//     C[1][2] = (int *)malloc(5 * sizeof(int));
//     C[1][3] = (int *)malloc(5 * sizeof(int));
//     C[2][0] = (int *)malloc(5 * sizeof(int));
//     C[2][1] = (int *)malloc(5 * sizeof(int));
//     C[2][2] = (int *)malloc(5 * sizeof(int));
//     C[2][3] = (int *)malloc(5 * sizeof(int));

//     // freeing memory
//     for (i = 0; i < 3; i++)
//     {
//         free(C[i]);
//     }
//     free(C);

//     // freeing memory
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             free(B[i][j]);
//         }
//         free(B[i]);
//     }
//     free(B);

//     // freeing memory
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             free(C[i][j]);
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         free(C[i]);
//     }
//     free(C);
    
//     // freeing memory
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             free(A[i][j]);
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         free(A[i]);
//     }
//     free(A);

    



    
//     return 0;

// }
