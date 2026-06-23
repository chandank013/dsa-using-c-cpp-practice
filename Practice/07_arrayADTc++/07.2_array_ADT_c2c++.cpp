// #include <iostream>

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

// void Display(struct Array arr)
// {
//     int i;
//     printf("Elements are\n");
//     for (i = 0; i < arr.length; i++)
//         printf("%d ", arr.A[i]);
//     printf("\n");
// }

// void Append(struct Array *arr, int x)
// {
//     if (arr->length < arr->size)
//         arr->A[arr->length++] = x;
// }

// void Insert(struct Array *arr, int index, int x);
// int Delete(struct Array *arr, int index);
// int LinearSearch(struct Array arr, int key);
// int BinarySearch(struct Array arr, int key);
// int Get(struct Array arr, int index);
// void Set(struct Array *arr, int index, int x);
// int Max(struct Array arr);
// int Min(struct Array arr);
// int Sum(struct Array arr);
// float Avg(struct Array arr);
// void Reverse(struct Array *arr);
// void InsertSort(struct Array *arr, int x);
// int isSorted(struct Array arr);
// void Rearrange(struct Array *arr);
// struct Array* Merge(struct Array *arr1, struct Array *arr2);
// struct Array* Union(struct Array *arr1, struct Array *arr2);
// struct Array* Intersection(struct Array *arr1, struct Array *arr2);
// struct Array* Difference(struct Array *arr1, struct Array *arr2);


// int main()
// { 
//         struct Array arr;
//         arr = (struct Array *)malloc(sizeof(struct Array));
//         arr.size = 10;
//         arr.length = 0;

//         arr.A = (int *)malloc(arr.size * sizeof(int));

//         Append(&arr, 2);
//         Append(&arr, 3);
        
//     struct Array arr = {{2,3,4,5,6}, 5, 5};
//     int n, i;

    // or

//     struct Array arr;
//     int n, i;
//     printf("Enter size of array: ");
//     scanf("%d", &arr.size);
//     arr.A = (int *)malloc(arr.size * sizeof(int));
//     arr.length = 0;

//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     printf("Enter all elements: ");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr.A[i]);
//     }
//     arr.length = n;

//     Display(arr);

//     Append(&arr, 10);
//     Display(arr);

//     Insert(&arr, 0, 1);
//     Display(arr);

//     Delete(&arr, 0);
//     Display(arr);


//     return 0;
// }




// C program is related to logic and prosesure the code
// C++ is related to designing and orginising the code


// // Process of converting c program to c++ program

// // Change File Extension: Rename the file from .c to .cpp.
// // Include C++ Headers: Replace C standard library headers with C++ headers.

// #include <iostream>
// #include <cstdlib>

// // Use std Namespace: Use the std namespace for C++ standard library functions.
// using namespace std;

// // Replace struct with class: Convert C struct to C++ class and make member variables private.
// class Array {
//     private:  // data members
//         int *A;
//         int size;
//         int length;
//     public: // function

        
//         Array(int size);
//         ~Array();

//         //or

//         Array()  // non-paramiterised constructor
//         {
//             size=10;
//             length=0;
//             A=new int[size];
//         }

//         Array(int sz) // paramiterised constructor
//         {
//             size=sz;
//             length=0;
//             A=new int[size];
//         }

//         ~Array() // destructor
//         {
//             delete[]A;
//         }


//         void Display();
//         void Append(int x);
//         void Insert(int index, int x);
//         int Delete(int index);
//     };

// // Constructor and Destructor: Add constructor and destructor to manage dynamic memory.
// Array::Array(int size) {
//     this->size = size;
//     A = new int[size];
//     length = 0;
// }

// Array::~Array() {
//     delete[] A;
// }

// // Member Functions: Convert functions to member functions of the class.
// void Array::Display() {
//     for (int i = 0; i < length; i++)
//         cout << A[i] << " ";
//     cout << endl;
// }

// void Array::Append(int x) {
//     if (length < size)
//         A[length++] = x;
// }


// // Main Function: Update the main function to use the Array class.
// int main() {
//     Array arr(10);
//     arr.Append(2);
//     arr.Append(3);
//     arr.Append(5);
//     arr.Append(10);
//     arr.Append(15);

//     arr.Display();

//     return 0;
// }





#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
public:
    Array(int size);  //  Constructor
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int getlength() { return length; }
    int BinarySearchRecursion(int key, int l, int h); // Binary search using recursion
    void LeftShift();
    void RotateLeft();
    void RightShift();
    void RotateRight();
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
    ~Array();   // Destructor
};

Array::Array(int size) {
    this->length = 0;
    this->size = size;
    A = new int[size];
}

Array::~Array() {
    delete[] A;
}

void Array::Display() {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::Append(int x) {
    if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index) {
    int x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

int Array::LinearSearch(int key) {
    for (int i = 0; i < length; i++) {
        if (A[i] == key)
            return i;
    }
    return -1;
}

// Binary search
int Array::BinarySearch(int key) {
    int l = 0, h = length - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

// getlength function is used to get the length of the array
int Array::getlength() {
    return length;
}

// Binary search using recursion
int Array::BinarySearchRecursion(int key, int l, int h)
{
    if(l <= h)
    {
        int mid = (l + h) / 2;

        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            return BinarySearchRecursion(key, mid + 1, h);
        else
            return BinarySearchRecursion(key, l, mid - 1);
    }

    return -1;
}

// Get and Set functions are used to get and set the value of the array at a specific index
int Array::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::Set(int index, int x) {
    if (index >= 0 && index < length)
        A[index] = x;
}


// Max, Min, Sum, and Avg functions are used to get the maximum, minimum, sum, and average of the array
int Array::Max() {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min() {
    int min = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum() {
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

float Array::Avg() {
    return (float)Sum() / length;
}

// Reverse function is used to reverse the array
void Array::Reverse() {
    int *B = new int[length];
    for (int i = 0, j = length - 1; i < length; i++, j--)
        B[j] = A[i];
    for (int i = 0; i < length; i++)
        A[i] = B[i];
    delete[] B;
}

// Reverse by swapping elements
void Array::Reverse() {
    for (int i = 0, j = length - 1; i < j; i++, j--)
        swap(A[i], A[j]);
}

// left shift 
void Array::LeftShift() {
    if (length == 0)
        return;
    for (int i = 0; i < length - 1; i++)
        A[i] = A[i + 1];
    length--;
}

// rotate left
void Array::RotateLeft() {
    if (length == 0)
        return;
    int temp = A[0];
    for (int i = 0; i < length - 1; i++)
        A[i] = A[i + 1];
    A[length - 1] = temp;
}

// right shift
void Array::RightShift() {
    if (length == 0)
        return;
    for (int i = length - 1; i > 0; i--)
        A[i] = A[i - 1];
    length--;
}

// rotate right
void Array::RotateRight() {
    if (length == 0)
        return;
    int temp = A[length - 1];
    for (int i = length - 1; i > 0; i--)
        A[i] = A[i - 1];
    A[0] = temp;
}

// InsertSort function is used to insert an element in a sorted array
void Array::InsertSort(int x) {
    if (length == size)
        return;
    int i = length - 1;
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

// isSorted function is used to check if the array is sorted or not
int Array::isSorted() {
    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

// Rearrange function is used to rearrange the array such that all negative numbers are on the left side and all positive numbers are on the right side
void Array::Rearrange() {
    int i = 0, j = length - 1;
    while (i < j) {
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;
        if (i < j) swap(A[i], A[j]);
    }
}

// Merge, Union, Intersection, and Difference functions are used to perform set operations on two arrays
Array* Array::Merge(Array *arr2) {    // we can write arr[] instead of *arr2
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(size + arr2->size);
    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = length + arr2->length;
    return arr3;
}

// Union function is used to find the union of two arrays
Array* Array::Union(Array *arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(size + arr2->size);
    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    return arr3;
}

// Intersection function is used to find the intersection of two arrays
Array* Array::Intersection(Array *arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(size + arr2->size);
    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            i++;
        else if (A[i] > arr2->A[j])
            j++;
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    arr3->length = k;
    return arr3;
}

// Difference function is used to find the difference of two arrays
Array* Array::Difference(Array *arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(size + arr2->size);
    while (i < length && j < arr2->length) {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2->A[j])
            j++;
        else {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    arr3->length = k;
    return arr3;
}

int main() {
        Array arr(10);
        arr.Append(2);  
        arr.Append(3);
        arr.Append(5);
        arr.Append(10);
        arr.Append(15);

        // Display the array
        arr.Display();

        // Insert an element at a specific index
        arr.Insert(2, 4);
        arr.Display();
        cout << "Deleted element: " << arr.Delete(3) << endl;

        // Search for an element
        int index = arr.LinearSearch(5);
        if (index != -1)
            cout << "Element found at index: " << index << endl;
        else
            cout << "Element not found" << endl;

        // Binary search (array must be sorted)
        index = arr.BinarySearch(10);

        // Binary search using recursion
        index = arr.BinarySearchRecursion(10, 0, arr.getlength() - 1);

        // Get and Set an element
        cout << "Element at index 1: " << arr.Get(1) << endl;
        if(index != -1)
            cout << "Element found at index: " << index << endl;
        else
            cout << "Element not found" << endl;
        
        arr.Set(1, 20);
        arr.Display();

        // Find max, min, sum, and average
        cout << "Max: " << arr.Max() << endl;
        cout << "Min: " << arr.Min() << endl;
        cout << "Sum: " << arr.Sum() << endl;
        cout << "Average: " << arr.Avg() << endl;

        // Reverse the array
        arr.Reverse();
        cout << "Reversed array: ";
        arr.Display();

        // Reverse by swapping elements
        arr.Reverse();
        cout << "Reversed array by swapping: ";
        arr.Display();

        // Left shift the array
        arr.LeftShift();
        cout << "Array after left shift: ";
        arr.Display();

        // Rotate left the array
        arr.RotateLeft();
        cout << "Array after left rotation: ";
        arr.Display();

        // Right shift the array
        arr.RightShift();
        cout << "Array after right shift: ";
        arr.Display();

        // Rotate right the array
        arr.RotateRight();
        cout << "Array after right rotation: ";
        arr.Display();


        // Insert in sorted array
        arr.InsertSort(12);
        cout << "Array after inserting 12 in sorted order: ";
        arr.Display();

        // Check if the array is sorted
        cout << "Is the array sorted? " << (arr.isSorted() ? "Yes" : "No") << endl;

        // Rearrange the array        arr.Rearrange();
        cout << "Rearranged array: ";   
        arr.Display();

        // Create another array for merging, union, intersection, and difference
        Array arr2(10);
        arr2.Append(1);
        arr2.Append(3);
        arr2.Append(5);
        arr2.Append(7);
        arr2.Append(9);

        // Merge
        Array *mergedArr = arr.Merge(&arr2);
        cout << "Merged array: ";
        mergedArr->Display();

        // Union
        Array *unionArr = arr.Union(&arr2);
        cout << "Union of arrays: ";
        unionArr->Display();

        // Intersection
        Array *intersectionArr = arr.Intersection(&arr2);
        cout << "Intersection of arrays: ";
        intersectionArr->Display();

        // Difference
        Array *differenceArr = arr.Difference(&arr2);
        cout << "Difference of arrays: ";
        differenceArr->Display();

        // Clean up dynamically allocated memory
        delete mergedArr;
        delete unionArr;
        delete intersectionArr;
        delete differenceArr;

    return 0;
}
