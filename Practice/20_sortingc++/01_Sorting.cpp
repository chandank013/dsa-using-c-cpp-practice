#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Bubble sort function with optimization (adaptive)
void bubbleSortAdaptive(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then break
        if (swapped == false)
            break;
    }
}

// function for insertion sort
void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// selection sort function of an array
void selectionSort(int arr[], int n) {
    int i, j, k;
    for(i = 0; i < n-1; i++) {
        for(j = k = i; j < n; j++) {
            if(arr[j] < arr[k]) {
                k = j;
            }
        }
        swap(&arr[i], &arr[k]);
    }
}

// Quick sort function of an array
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // pivot
    int i = low, j = high;

    do {
        do {
            i++;
        } while (arr[i] <= pivot);
        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) 
            swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

// function for merge sort
void mergeWithTwoArrays(int A[], int B[], int m, int n) {
    int *c = new int[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            c[k++] = A[i++];
        } else {
            c[k++] = B[j++];
        }
    }

    while (i < m) {
        c[k++] = A[i++];
    }

    while (j < n) {
        c[k++] = B[j++];
    }

    for (int idx = 0; idx < k; idx++) {
        cout << c[idx] << " ";
    }

    delete[] c;
}

// merge sort using single array
void mergeWithSingleArray(int arr[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int *b = new int[h + 1];

    while (i <= mid && j <= h) {
        if (arr[i] < arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        b[k++] = arr[i++];
    }

    while (j <= h) {
        b[k++] = arr[j++];
    }

    for (int idx = l; idx <= h; idx++) {
        arr[idx] = b[idx];
    }

    delete[] b;
}

// Function to merge multiple arrays into a single sorted array
void mergeMultipleArrays(int arr[][5], int n, int m) {
    int *result = new int[n * m];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[k++] = arr[i][j];
        }
    }

    // Sort the merged array
    bubbleSort(result, n * m);

    cout << "Merged and sorted array: ";
    for (int i = 0; i < n * m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
}

// m-way merge function for merging multiple sorted arrays
void mWayMerge(int arr[][5], int n, int m) {
    int *result = new int[n * m];
    int *indices = new int[n](); // Initialize indices for each array to 0
    int k = 0;

    while (k < n * m) {
        int minIndex = -1;
        int minValue = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (indices[i] < m && arr[i][indices[i]] < minValue) {
                minValue = arr[i][indices[i]];
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            result[k++] = arr[minIndex][indices[minIndex]];
            indices[minIndex]++;
        }
    }

    cout << "Merged and sorted array using m-way merge: ";
    for (int i = 0; i < n * m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
    delete[] indices;
}

// function for iterative version of merge sort
void iterativeMergeSort(int arr[], int n) {
    int p,i,l,mid,h;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            mergeWithSingleArray(arr, l, mid, h);
        }
    }
    if (p / 2 < n)
        mergeWithSingleArray(arr, 0, (p / 2) - 1, n - 1);
}

// function for recursive version of merge sort
void recursiveMergeSort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        recursiveMergeSort(arr, l, mid);
        recursiveMergeSort(arr, mid + 1, h);
        mergeWithSingleArray(arr, l, mid, h);
    }
}

// count sort function
void countSort(int arr[], int n) {
    int max = *max_element(arr, arr + n);
    int *count = new int[max + 1]();

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int k = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[k++] = i;
            count[i]--;
        }
    }

    delete[] count;
}

// bin/bucket sort function
void bucketSort(int arr[], int n) {
    int max = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    
    int bucketCount = max - min + 1;
    int* buckets = new int[bucketCount]();

    // initialize buckets with 0
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = 0;
    }

    // count the elements in each bucket
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - min]++;
    }

    // reconstruct the sorted array
    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        while (buckets[i] > 0) {
            arr[k++] = i + min;
            buckets[i]--;
        }
    }

    delete[] buckets;
}

// bin/bucket sort function using linked list
struct Node {
    int data;
    Node* next;
};

void bucketSortLinkedList(int arr[], int n) {
    int max = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    
    int bucketCount = max - min + 1;
    Node** buckets = new Node*[bucketCount]();

    // initialize buckets with nullptr
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = nullptr;
    }

    // insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] - min;
        Node* newNode = new Node{arr[i], buckets[index]};
        buckets[index] = newNode;
    }

    // reconstruct the sorted array
    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        Node* current = buckets[i];
        while (current != nullptr) {
            arr[k++] = current->data;
            Node* temp = current;
            current = current->next;
            delete temp; // free memory
        }
    }

    delete[] buckets;
}

// Counting sort for each digit
void countingSort(int arr[], int n, int exp) {

    int* output = new int[n];
    int count[10] = {0};

    // Count digits
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--) {

        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];

        count[digit]--;
    }

    // Copy output back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSort(int arr[], int n) {

    // Find maximum element
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Sort by each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// shell sort function
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset the array for adaptive bubble sort
    bubbleSortAdaptive(arr, n);
    
    cout << "Sorted array (adaptive): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset the array for insertion sort
    insertionSort(arr, n);

    cout << "Sorted array (insertion sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset the array for selection sort
    selectionSort(arr, n);

    cout << "Sorted array (selection sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset the array for quick sort
    int arr1[] = {64, 34, 25, 12, 22, 11, INT_MAX}; // Adding INT32_MAX as a sentinel value
    quickSort(arr1, 0, n - 1);

    cout << "Sorted array (quick sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Merge sort demonstration
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int m = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    mergeWithTwoArrays(A, B, m, n2);
    cout << endl;

    // Merge sort using single array demonstration
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr2) / sizeof(arr2[0]);
    mergeWithSingleArray(arr2, 0, (arr_size - 1) / 2, arr_size - 1);
    cout << "Sorted array (merge sort): ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Merging multiple arrays using the mergeMultipleArrays function
    int arr3[3][5] = {
        {1, 4, 7, 10, 13},
        {2, 5, 8, 11, 14},
        {3, 6, 9, 12, 15}
    };
    mergeMultipleArrays(arr3, 3, 5);
    cout << endl;

    // Merging multiple arrays using m-way merge
    int arr4[3][5] = {
        {1, 4, 7, 10, 13},
        {2, 5, 8, 11, 14},
        {3, 6, 9, 12, 15}
    };
    mWayMerge(arr4, 3, 5);
    cout << endl;

    // Iterative merge sort demonstration
    int arr5[] = {12, 11, 13, 5, 6, 7};
    int arr5_size = sizeof(arr5) / sizeof(arr5[0]);
    iterativeMergeSort(arr5, arr5_size);
    cout << "Sorted array (iterative merge sort): ";
    for (int i = 0; i < arr5_size; i++) {
        cout << arr5[i] << " ";
    }
    cout << endl;

    // Recursive merge sort demonstration
    int arr6[] = {12, 11, 13, 5, 6, 7};
    int arr6_size = sizeof(arr6) / sizeof(arr6[0]);
    recursiveMergeSort(arr6, 0, arr6_size - 1);
    cout << "Sorted array (recursive merge sort): ";
    for (int i = 0; i < arr6_size; i++) {
        cout << arr6[i] << " ";
    }
    cout << endl;

    // Count sort demonstration
    int arr7[] = {4, 2, 2, 8, 3, 3, 1};
    int arr7_size = sizeof(arr7) / sizeof(arr7[0]);
    countSort(arr7, arr7_size);
    cout << "Sorted array (count sort): ";
    for (int i = 0; i < arr7_size; i++) {
        cout << arr7[i] << " ";
    }
    cout << endl;

    // Bucket sort demonstration
    int arr8[] = {4, 2, 2, 8, 3, 3, 1};
    int arr8_size = sizeof(arr8) / sizeof(arr8[0]);
    bucketSort(arr8, arr8_size);
    cout << "Sorted array (bucket sort): ";
    for (int i = 0; i < arr8_size; i++) {
        cout << arr8[i] << " ";
    }
    cout << endl;

    // Bucket sort using linked list demonstration
    int arr9[] = {4, 2, 2, 8, 3, 3, 1};
    int arr9_size = sizeof(arr9) / sizeof(arr9[0]);
    bucketSortLinkedList(arr9, arr9_size);
    cout << "Sorted array (bucket sort with linked list): ";
    for (int i = 0; i < arr9_size; i++) {
        cout << arr9[i] << " ";
    }
    cout << endl;

    // Radix sort demonstration
    int arr10[] = {170, 45, 75, 90,802, 24, 2, 66};
    int arr10_size = sizeof(arr10) / sizeof(arr10[0]);
    radixSort(arr10, arr10_size);
    cout << "Sorted array (radix sort): ";
    for (int i = 0; i < arr10_size; i++) {
        cout << arr10[i] << " ";
    }
    cout << endl;

    // Shell sort demonstration
    int arr11[] = {12, 34, 54, 2, 3};
    int arr11_size = sizeof(arr11) / sizeof(arr11[0]);
    shellSort(arr11, arr11_size);
    cout << "Sorted array (shell sort): ";
    for (int i = 0; i < arr11_size; i++) {
        cout << arr11[i] << " ";
    }
    cout << endl;

    return 0;
}