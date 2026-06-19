#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;

    p = (int *)malloc(5 * sizeof(int));
    p[0] = 1;
    p[1] = 2;       
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }

    printf("\n");

    // Increase the size of the array to 10 using realloc, AI
    p = realloc(p, 10 * sizeof(int)); // This is a better way to increase the size of an array
    if (p == NULL) // Check if realloc failed
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 5; i < 10; i++)
    {
        p[i] = i + 1; // Initialize new elements
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p); // Free the memory allocated for the array
    p = NULL; // Avoid dangling pointer


    // Increase the size of the array to 10 using malloc, Teacher
    q = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i]; // Copy old values to new array
    }

    free(p); // Free the old array
    p = q; // Point p to the new array
    q = NULL; // Avoid dangling pointer
    return 0;
}
