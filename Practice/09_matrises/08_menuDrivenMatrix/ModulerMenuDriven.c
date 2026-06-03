#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int *A, int n) {
    printf("Enter %d diagonal elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

void getValue(int *A, int n) {
    int i, j;
    printf("Enter indices (i j): ");
    if (scanf("%d %d", &i, &j) != 2) {
        printf("Invalid input! Please enter two integers.\n");
        while (getchar() != '\n');
        return;
    }

    if (i >= 1 && i <= n && j >= 1 && j <= n) {
        if (i == j)
            printf("Value: %d\n", A[i - 1]);
        else
            printf("Value: 0\n");
    } else {
        printf("Invalid indices! i and j must be between 1 and %d.\n", n);
    }
}

void setValue(int *A, int n) {
    int i, j, x;
    printf("Enter row, column and value (i j x): ");
    if (scanf("%d %d %d", &i, &j, &x) != 3) {
        printf("Invalid input! Please enter three integers.\n");
        while (getchar() != '\n');
        return;
    }

    if (i >= 1 && i <= n && j >= 1 && j <= n) {
        if (i == j)
            A[i - 1] = x;
        else
            printf("Only diagonal elements can be set in a diagonal matrix.\n");
    } else {
        printf("Invalid indices! i and j must be between 1 and %d.\n", n);
    }
}

void displayMatrix(int *A, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                printf("%d ", A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int menu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Input Diagonal Elements\n");
    printf("2. Get Value at Index (i, j)\n");
    printf("3. Set Value at Index (i, j)\n");
    printf("4. Display Matrix\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n'); // Clear buffer
        return -1;
    }
    return choice;
}

int main() {
    int *A, n, choice;

    printf("Enter matrix size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid matrix size!\n");
        return 1;
    }

    A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        choice = menu();
        switch (choice) {
            case 1: inputMatrix(A, n); break;
            case 2: getValue(A, n); break;
            case 3: setValue(A, n); break;
            case 4: displayMatrix(A, n); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    free(A);
    return 0;
}
