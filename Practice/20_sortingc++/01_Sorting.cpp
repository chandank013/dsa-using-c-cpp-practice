#include <iostream>
#include <algorithm>
#include <climits>

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



int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

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
    int arr1[] = {64, 34, 25, 12, 22, 11, INT_MAX}; // Adding INT_MAX as a sentinel value
    quickSort(arr1, 0, n - 1);

    cout << "Sorted array (quick sort): ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}