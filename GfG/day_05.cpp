// {Driver Code Starts
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// } Driver Code Ends

// use function Template for C

// Function to find the next permutation 
void nextPermutation(int *arr, int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i < 0) {
        for (int j = 0; j < n / 2; j++) {
            int temp = arr[j];
            arr[j] = arr[n - j - 1];
            arr[n - j - 1] = temp;
        }
        return;
    }
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    for (int k = i + 1, l = n - 1; k < l; k++, l--) {
        temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;
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

        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }

        nextPermutation(brr, n);
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                printf("%d\n", brr[i]);
                continue;
            }
            printf("%d ", brr[i]);
            
        }
        printf("\n","~");
        free(nums);
        free(line);
    }
    return 0;

}

// } Driver Code Ends

