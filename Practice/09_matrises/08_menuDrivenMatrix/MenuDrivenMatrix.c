#include <stdio.h>
#include <stdlib.h>

int main() {
    int *A, n, ch = 0, x, i, j;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Input Diagonal Elements\n");
        printf("2. Get Value at Index (i, j)\n");
        printf("3. Set Value at Index (i, j)\n");
        printf("4. Display Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // flush input buffer
            continue;
        }

        switch (ch) {
            case 1:
                printf("Enter %d diagonal elements:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &A[i]);
                }
                break;

            case 2:
                printf("Enter indices (i j): ");
                if (scanf("%d %d", &i, &j) != 2) {
                    printf("Invalid input! Please enter two numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (i >= 1 && i <= n && j >= 1 && j <= n) {
                    if (i == j)
                        printf("Value: %d\n", A[i - 1]);
                    else
                        printf("Value: 0\n");
                } else {
                    printf("Invalid indices! i and j must be in range 1 to %d.\n", n);
                }
                break;

            case 3:
                printf("Enter row, column and value (i j x): ");
                if (scanf("%d %d %d", &i, &j, &x) != 3) {
                    printf("Invalid input! Please enter three numbers.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (i >= 1 && i <= n && j >= 1 && j <= n) {
                    if (i == j)
                        A[i - 1] = x;
                    else
                        printf("Only diagonal elements can be set.\n");
                } else {
                    printf("Invalid indices! i and j must be in range 1 to %d.\n", n);
                }
                break;

            case 4:
                printf("Matrix:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        if (i == j)
                            printf("%d ", A[i]);
                        else
                            printf("0 ");
                    }
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 5);

    free(A);
    return 0;
}
