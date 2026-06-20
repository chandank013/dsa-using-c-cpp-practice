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
Array* Array::Merge(Array *arr2) {
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
        cout << "Element at index 1: " << arr.Get(1) << endl
                << "Setting element at index 1 to 20" << endl;
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




// // Main Function: Update the main function to use the Array class and provide a menu-driven interface for testing all functionalities.
// int main() {
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;

//     Array arr(size);
//     int choice, x, index;

//     do {
//         cout << "\nMenu\n";
//         cout << "1. Display\n";
//         cout << "2. Append\n";
//         cout << "3. Insert\n";
//         cout << "4. Delete\n";
//         cout << "5. Linear Search\n";
//         cout << "6. Binary Search\n";
//         cout << "7. Get\n";
//         cout << "8. Set\n";
//         cout << "9. Max\n";
//         cout << "10. Min\n";
//         cout << "11. Sum\n";
//         cout << "12. Average\n";
//         cout << "13. Reverse\n";
//         cout << "14. Insert in Sorted Array\n";
//         cout << "15. Check if Sorted\n";
//         cout << "16. Rearrange\n";
//         cout << "17. Merge\n";
//         cout << "18. Union\n";
//         cout << "19. Intersection\n";
//         cout << "20. Difference\n";
//         cout << "21. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 arr.Display();
//                 break;
//             case 2:
//                 cout << "Enter element to append: ";
//                 cin >> x;
//                 arr.Append(x);
//                 break;
//             case 3:
//                 cout << "Enter index and element to insert: ";
//                 cin >> index >> x;
//                 arr.Insert(index, x);
//                 break;
//             case 4:
//                 cout << "Enter index to delete: ";
//                 cin >> index;
//                 x = arr.Delete(index);
//                 if (x != 0)
//                     cout << "Deleted element is " << x << endl;
//                 else
//                     cout << "Invalid index\n";
//                 break;
//             case 5:
//                 cout << "Enter element to search: ";
//                 cin >> x;
//                 index = arr.LinearSearch(x);
//                 if (index != -1)
//                     cout << "Element found at index " << index << endl;
//                 else
//                     cout << "Element not found\n";
//                 break;
//             case 6:
//                 cout << "Enter element to search: ";
//                 cin >> x;
//                 index = arr.BinarySearch(x);
//                 if (index != -1)
//                     cout << "Element found at index " << index << endl;
//                 else
//                     cout << "Element not found\n";
//                 break;
//             case 7:
//                 cout << "Enter index to get element: ";
//                 cin >> index;
//                 x = arr.Get(index);
//                 if (x != -1)
//                     cout << "Element at index " << index << " is " << x << endl;
//                 else
//                     cout << "Invalid index\n";
//                 break;
//             case 8:
//                 cout << "Enter index and element to set: ";
//                 cin >> index >> x;
//                 arr.Set(index, x);
//                 break;
//             case 9:
//                 cout << "Max element is " << arr.Max() << endl;
//                 break;
//             case 10:
//                 cout << "Min element is " << arr.Min() << endl;
//                 break;
//             case 11:
//                 cout << "Sum of elements is " << arr.Sum() << endl;
//                 break;
//             case 12:
//                 cout << "Average of elements is " << arr.Avg() << endl;
//                 break;
//             case 13:
//                 arr.Reverse();
//                 cout << "Array reversed\n";
//                 break;
//             case 14:
//                 cout << "Enter element to insert in sorted array: ";
//                 cin >> x;
//                 arr.InsertSort(x);
//                 break;
//             case 15:
//                 if (arr.isSorted())
//                     cout << "Array is sorted\n";
//                 else
//                     cout << "Array is not sorted\n";
//                 break;
//             case 16:
//                 arr.Rearrange();
//                 cout << "Array rearranged\n";
//                 break;
//             case 17: {
//                 cout << "Enter the size of the second array: ";
//                 int size2;
//                 cin >> size2;
//                 Array arr2(size2);
//                 cout << "Enter elements of the second array:\n";
//                 for (int i = 0; i < size2; i++) {
//                     cin >> x;
//                     arr2.Append(x);
//                 }
//                 Array *arr3 = arr.Merge(&arr2);
//                 cout << "Merged array: ";
//                 arr3->Display();
//                 delete arr3;
//                 break;
//             }
//             case 18: {
//                 cout << "Enter the size of the second array: ";
//                 int size2;
//                 cin >> size2;
//                 Array arr2(size2);
//                 cout << "Enter elements of the second array:\n";
//                 for (int i = 0; i < size2; i++) {
//                     cin >> x;
//                     arr2.Append(x);
//                 }
//                 Array *arr3 = arr.Union(&arr2);
//                 cout << "Union of arrays: ";
//                 arr3->Display();
//                 delete arr3;
//                 break;
//             }
//             case 19: {
//                 cout << "Enter the size of the second array: ";
//                 int size2;
//                 cin >> size2;
//                 Array arr2(size2);
//                 cout << "Enter elements of the second array:\n";
//                 for (int i = 0; i < size2; i++) {
//                     cin >> x;
//                     arr2.Append(x);
//                 }
//                 Array *arr3 = arr.Intersection(&arr2);
//                 cout << "Intersection of arrays: ";
//                 arr3->Display();
//                 delete arr3;
//                 break;
//             }
//             case 20: {
//                 cout << "Enter the size of the second array: ";
//                 int size2;
//                 cin >> size2;
//                 Array arr2(size2);
//                 cout << "Enter elements of the second array:\n";
//                 for (int i = 0; i < size2; i++) {
//                     cin >> x;
//                     arr2.Append(x);
//                 }
//                 Array *arr3 = arr.Difference(&arr2);
//                 cout << "Difference of arrays: ";
//                 arr3->Display();
//                 delete arr3;
//                 break;
//             }
//             case 21:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice\n";
//         }
//     } while (choice != 21);

//     return 0;
// }





// // Code for template Class

// template <class T> // for creating generic array to coverting in to template class


// class Array
// {
// private:
//     T *A; // for dynamically ceate an array
//     int size;
//     int length;

// public:
//     Array() // non-parameterised constructure
//     {
//         size=10;
//         A=new T[10];
//         length=0;
//     }
//     Array(int sz)  // parameterised constructure
//     {
//         size=sz;
//         length=10;
//         A=new T[10];
//     }

//     ~Array()
//     {
//         delete[]A;
//     }

//     void Display();
//     void Insert(int index,T element);
//     T Delete(int index);

// };

// template<class T>

// void Array<T>::Display()
// {
//     for(int i=0;i<length;i++)
//     {
//         cout<<A[i]<<" ";
//     cout<<endl;

//     }
// }

// template <class T>
// void Array<T>::Insert(int index,T element)
// {
//     if (index>=0 && index<=length)
//     {
//         for(int i=length-1;i>=index;i--)
//             A[i+1]=A[i];
//         A[index]=element;
//         length++;
//     }
// }

// template <class T>
// T Array<T>::Delete(int index)
// {
//     T x=0;
//     if (index>=0 && index<length)
//     {
//         x=A[index];
//         for(int i=index;i<length-1;i++)
//         A[i]=A[i+1];
//         length--;
//     }
// }

// // Menu driven funtion of int function
// int main()
// {
//     Array <int> arr(10);   // we can take any data type
//     arr.Insert(0,5);
//     arr.Insert(1,6);
//     arr.Insert(2,9);
//     arr.Insert(3,11);
//     arr.Insert(4,63);

//     cout<<arr.Delete(0)<<endl;
//     arr.Display();

//     return 0;
// }