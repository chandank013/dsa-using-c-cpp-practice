// {Driver Code Starts
// Inital Template for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// } Driver Code Ends

int* findMajority(int arr[], int n, int* resultSize) {
    int count = 0, candidate = -1;
    
    // Step 1: Find candidate using Boyer-Moore Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    // If candidate appears more than n/2 times, return it
    if (count > n / 2) {
        *resultSize = 1;
        int* result = (int*)malloc(sizeof(int));
        result[0] = candidate;
        return result;
    }

    // No majority element found
    *resultSize = 0;
    return NULL;
}

// { Driver Code Starts

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // to consume the newline character after the integer input

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
        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }
        int resultSize = 0;
        int *result = findMajority(brr, n, &resultSize);

        if (resultSize == 0) {
            printf("[]\n");
            printf("%s\n", "~");
        }else {
            for (int i = 0; i < resultSize; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
            printf("%s\n", "~");
        }
        free(nums);
        free(result);

    }
    return 0;

}

// } Driver Code Ends
