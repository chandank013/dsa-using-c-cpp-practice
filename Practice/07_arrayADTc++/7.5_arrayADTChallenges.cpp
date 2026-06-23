#include<iostream>

using namespace std;

class ArrayADT {
    int *A;
    int size;
    int length;
public:
    ArrayADT(int size);
    ~ArrayADT();
    int getlength() { return length; }
    void Display();
    void Append(int x);
    int missingElement();
    int missingElement2();
    int multipleMissingElements();
    int missingElementUnsortedArray();

    int dublicateElementInSortedArray();
    int countDublicateElementInSortedArray();
    int count1DublicateElementInSortedArray();
    int dublicateElementInSortedArrayUsingHash();
    int dublicateElementInUnsortedArray();
    int dublicateElementInUnsortedArrayUsingHash();

    int findSumOfPairs(int sum);
    int findSumOfPairsInSortedArray(int sum);

    int findMinAndMax();
};

ArrayADT::ArrayADT(int size) {
    this->size = size;
    A = new int[size];
    length = 0;
}

ArrayADT::~ArrayADT() {
    delete[] A;
}

// function to display the elements of the array
void ArrayADT::Display() {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

// function to append an element to the array
void ArrayADT::Append(int x) {
    if (length < size)
        A[length++] = x;
}

// Function to find the missing element in a sorted array
int ArrayADT::missingElement() {   // if array is natural numbers starting from 1, then missing element is 1 + (n*(n+1)/2 - sum of array elements)
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++) {
        if (A[i] - i != diff) {
            return i + diff;   // The missing element is the index plus the initial difference
        }
    }
    return -1; // No missing element
}

int ArrayADT::missingElement2() {
    int total = (length + 1) * (length + 2) / 2; // Sum of first n natural numbers
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += A[i]; // Sum of elements in the array
    }
    return total - sum; // The missing element is the difference between total and sum
}

// Function to find multiple missing elements in a sorted array
int ArrayADT::multipleMissingElements() {
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++) {
        if (A[i] - i != diff) {
            while (diff < A[i] - i) {
                cout << i + diff << " "; // Print the missing element
                diff++;
            }
        }
    }
    cout << endl;
    return 0; // Return value is not used in this function
}

// Function to find the missing element in an unsorted array using a hash table
int ArrayADT::missingElementUnsortedArray() {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i]; // Find the maximum element in the array
        }
    }
    int *H = new int[max + 1](); // Create a hash table initialized to 0
    for (int i = 0; i < length; i++) {
        H[A[i]]++; // Mark the presence of elements in the hash table
    }
    for (int i = 1; i <= max; i++) {
        if (H[i] == 0) {
            cout << i << " "; // Print the missing element
            delete[] H; // Clean up memory
        }
    }
    delete[] H; // Clean up memory
    return -1; // No missing element found
}

// Function to find duplicate elements in a sorted array
int ArrayADT::dublicateElementInSortedArray() {
    int lastDuplicate = -1; // Variable to track the last duplicate found
    for (int i = 0; i < length - 1; i++) {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate) {
            cout << A[i] << " "; // Print the duplicate element
            lastDuplicate = A[i]; // Update the last duplicate found
        }
    }
    return 0; // Return value is not used in this function
}

// Function to count duplicate elements in a sorted array
int ArrayADT::countDublicateElementInSortedArray() {
    int lastDuplicate = -1; // Variable to track the last duplicate found
    for (int i = 0; i < length - 1; i++) {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate) {
            int count = 1; // Initialize count for the current duplicate
            while (i < length - 1 && A[i] == A[i + 1]) {
                count++; // Count occurrences of the duplicate
                i++;
            }
            cout << A[i] << " occurs " << count << " times" << endl; // Print the duplicate and its count
            lastDuplicate = A[i]; // Update the last duplicate found
        }
    }
    return 0; // Return value is not used in this function
}

// Function to count duplicate elements in a sorted array
int ArrayADT::count1DublicateElementInSortedArray() {
    for (int i = 0; i < length - 1; i++) {
        if (A[i] == A[i + 1]) {
            int j=i+1;
            while (j < length && A[j] == A[i]) {
                j++;
            }
            cout << A[i] << " occurs " << (j - i) << " times" << endl; // Print the duplicate and its count
            i = j - 1; // Move the index to the last occurrence of the duplicate
        }
    }
    return 0;
}

// function to find duplicate elements in a sorted array using a hash table
int ArrayADT::dublicateElementInSortedArrayUsingHash() {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i]; // Find the maximum element in the array
        }
    }
    int *H = new int[max + 1](); // Create a hash table initialized to 0
    for (int i = 0; i < length; i++) {
        H[A[i]]++; // Mark the presence of elements in the hash table
    }
    for (int i = 0; i <= max; i++) {
        if (H[i] > 1) {
            cout << i << " "; // Print the duplicate element
        }
    }
    delete[] H; // Clean up memory
    return 0; // Return value is not used in this function
}

// Function to find duplicate elements in an unsorted array
int ArrayADT::dublicateElementInUnsortedArray() {
    for (int i = 0; i < length - 1; i++) {
        int count = 0;
        if (A[i] != -1) { // Check if the element is not marked as duplicate
            for (int j = i + 1; j < length; j++) {
                if (A[i] == A[j]) {
                    count++;
                    A[j] = -1; // Mark the duplicate element as -1 to avoid counting it again
                }
            }
            if (count > 0) {
                cout << A[i] << " occurs " << count + 1 << " times" << endl;
            }
        }
    }
    return 0; // Return value is not used in this function
}

// Function to find duplicate elements in an unsorted array using a hash table
int ArrayADT::dublicateElementInUnsortedArrayUsingHash() {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i]; // Find the maximum element in the array
        }
    }
    int *H = new int[max + 1](); // Create a hash table initialized to 0
    for (int i = 0; i < length; i++) {
        H[A[i]]++; // Mark the presence of elements in the hash table
    }
    for (int i = 0; i <= max; i++) {
        if (H[i] > 1) {
            cout << i << " occurs " << H[i] << " times" << endl; // Print the duplicate and its count
        }
    }
    delete[] H; // Clean up memory
    return 0; // Return value is not used in this function
}

// function to find the sum of pairs in an array that equal a given sum
int ArrayADT::findSumOfPairs(int sum) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (A[i] + A[j] == sum) {
                cout << A[i] << " + " << A[j] << " = " << sum << endl;
            }
        }
    }
    return 0;
}

// function to find the sum of pairs in an array that equal a given sum in a sorted array
int ArrayADT::findSumOfPairsInSortedArray(int sum) {
    int i = 0;
    int j = length - 1;
    while (i < j) {
        if (A[i] + A[j] == sum) {
            cout << A[i] << " + " << A[j] << " = " << sum << endl;
            i++;
            j--;
        } else if (A[i] + A[j] < sum) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}

// function to find min and max in single scan
int ArrayADT::findMinAndMax() {
    int min = A[0];
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < min) {
            min = A[i];
        } else if (A[i] > max) {
            max = A[i];
        }
    }
    cout << "Min: " << min << ", Max: " << max << endl;
    return 0;
}

int main() {
    ArrayADT arr(10);
    arr.Append(3);
    arr.Append(3);
    arr.Append(3);
    arr.Append(4);
    arr.Append(4);
    arr.Append(4);
    arr.Append(9);

    // cout << "Missing element: " << arr.missingElement() << endl;

    // cout << "Multiple missing elements: ";
    // arr.multipleMissingElements();

    // cout << "Missing element in unsorted array: " << arr.missingElementUnsortedArray() << endl;

    cout << "Duplicate elements in sorted array: ";
    arr.dublicateElementInSortedArray();
    cout << endl;

    cout << "Count of duplicate elements in sorted array: " << endl;
    arr.countDublicateElementInSortedArray();
    cout << endl;

    cout << "Count of duplicate elements in sorted array (method 2): " << endl;
    arr.count1DublicateElementInSortedArray();
    cout << endl;

    cout << "Duplicate elements in sorted array using hash: ";
    arr.dublicateElementInSortedArrayUsingHash();
    cout << endl;

    cout << "Duplicate elements in unsorted array: ";
    arr.dublicateElementInUnsortedArray();
    cout << endl;

    cout << "Duplicate elements in unsorted array: ";
    arr.dublicateElementInUnsortedArrayUsingHash();
    cout << endl;

    cout << "Sum of pairs equal to 7: " << endl;
    arr.findSumOfPairs(7);
    cout << endl;

    cout << "Sum of pairs equal to 7 in sorted array: " << endl;
    arr.findSumOfPairsInSortedArray(7);
    cout << endl;

    cout << "Finding min and max in single scan: " << endl;
    arr.findMinAndMax();
    cout << endl;

    cout << "Array elements: ";
    arr.Display();
    return 0;
} 