// {Driver Code Starts
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// } Driver Code Ends

// User function template for C

// function to rotate an array by d elements in counter-clockwise direction
void rotateArr(int arr[], int d, int n) {
    // To handle the case when d >= n
    d = d % n;
    
    // Reverse the first d elements
    for (int i = 0; i < d / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[d - i - 1];
        arr[d - i - 1] = temp;
    }
    
    // Reverse the remaining n - d elements
    for (int i = d; i < (n + d) / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n + d - i - 1];
        arr[n + d - i - 1] = temp;
    }
    
    // Reverse the entire array
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}


// { Driver Code Starts

int main() {
    char ts[1001];

    fgets(ts, sizeof(ts), stdin); // Read the first line of input
    int t = atoi(ts);

    while (t--) {
        
        char *line = NULL;
        size_t len = 0;
        long read = getline(&line, &len, stdin);

        int *nums = (int *)malloc(1000000 * sizeof(int));
        int n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        int x;
        scanf("%d", &x);
        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }

        rotateArr(brr, x, n);
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                printf("%d\n", brr[i]);
            } else {
                printf("%d ", brr[i]);
            }
        }
        printf("~\n");
        free(nums);
        free(line);
    }
    return 0;

}

// } Driver Code Ends

