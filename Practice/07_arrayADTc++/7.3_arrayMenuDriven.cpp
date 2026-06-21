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




// Main Function: Update the main function to use the Array class and provide a menu-driven interface for testing all functionalities.
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Array arr(size);
    int choice, x, index;

    do {
        cout << "\nMenu\n";
        cout << "1. Display\n";
        cout << "2. Append\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Linear Search\n";
        cout << "6. Binary Search\n";
        cout << "7. Binary Search using Recursion\n";
        cout << "8. Get\n";
        cout << "9. Set\n";
        cout << "10. Max\n";
        cout << "11. Min\n";
        cout << "12. Sum\n";
        cout << "13. Average\n";
        cout << "14. Reverse\n";
        cout << "15. Reverse by Swapping\n";
        cout << "16. Left Shift\n";
        cout << "17. Rotate Left\n";
        cout << "18. Right Shift\n";
        cout << "19. Rotate Right\n";
        cout << "20. Insert in Sorted Array\n";
        cout << "21. Check if Sorted\n";
        cout << "22. Rearrange\n";
        cout << "23. Merge\n";
        cout << "24. Union\n";
        cout << "25. Intersection\n";
        cout << "26. Difference\n";
        cout << "27. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr.Display();
                break;
            case 2:
                cout << "Enter element to append: ";
                cin >> x;
                arr.Append(x);
                break;
            case 3:
                cout << "Enter index and element to insert: ";
                cin >> index >> x;
                arr.Insert(index, x);
                break;
            case 4:
                cout << "Enter index to delete: ";
                cin >> index;
                x = arr.Delete(index);
                if (x != 0)
                    cout << "Deleted element is " << x << endl;
                else
                    cout << "Invalid index\n";
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> x;
                index = arr.LinearSearch(x);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found\n";
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> x;
                index = arr.BinarySearch(x);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found\n";
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> x;
                index = arr.BinarySearchRecursion(x, 0, arr.getlength() - 1);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found\n";
                break;
            case 8:
                cout << "Enter index to get element: ";
                cin >> index;
                x = arr.Get(index);
                if (x != -1)
                    cout << "Element at index " << index << " is " << x << endl;
                else
                    cout << "Invalid index\n";
                break;
            case 9:
                cout << "Enter index and element to set: ";
                cin >> index >> x;
                arr.Set(index, x);
                break;
            case 10:
                cout << "Max element is " << arr.Max() << endl;
                break;
            case 11:
                cout << "Min element is " << arr.Min() << endl;
                break;
            case 12:
                cout << "Sum of elements is " << arr.Sum() << endl;
                break;
            case 13:
                cout << "Average of elements is " << arr.Avg() << endl;
                break;
            case 14:
                arr.Reverse();
                cout << "Array reversed\n";
                break;
            case 15:
                arr.Reverse();
                cout << "Array reversed by swapping\n";
                break;
            case 16:
                arr.LeftShift();
                cout << "Array left shifted\n";
                break;
            case 17:
                arr.RotateLeft();
                cout << "Array rotated left\n";
                break;
            case 18:
                arr.RightShift();
                cout << "Array right shifted\n";
                break;
            case 19:
                arr.RotateRight();
                cout << "Array rotated right\n";
                break;
            case 20:
                cout << "Enter element to insert in sorted array: ";
                cin >> x;
                arr.InsertSort(x);
                break;
            case 21:
                if (arr.isSorted())
                    cout << "Array is sorted\n";
                else
                    cout << "Array is not sorted\n";
                break;
            case 22:
                arr.Rearrange();
                cout << "Array rearranged\n";
                break;
            case 23: {
                cout << "Enter the size of the second array: ";
                int size2;
                cin >> size2;
                Array arr2(size2);
                cout << "Enter elements of the second array:\n";
                for (int i = 0; i < size2; i++) {
                    cin >> x;
                    arr2.Append(x);
                }
                Array *arr3 = arr.Merge(&arr2);
                cout << "Merged array: ";
                arr3->Display();
                delete arr3;
                break;
            }
            case 24: {
                cout << "Enter the size of the second array: ";
                int size2;
                cin >> size2;
                Array arr2(size2);
                cout << "Enter elements of the second array:\n";
                for (int i = 0; i < size2; i++) {
                    cin >> x;
                    arr2.Append(x);
                }
                Array *arr3 = arr.Union(&arr2);
                cout << "Union of arrays: ";
                arr3->Display();
                delete arr3;
                break;
            }
            case 25: {
                cout << "Enter the size of the second array: ";
                int size2;
                cin >> size2;
                Array arr2(size2);
                cout << "Enter elements of the second array:\n";
                for (int i = 0; i < size2; i++) {
                    cin >> x;
                    arr2.Append(x);
                }
                Array *arr3 = arr.Intersection(&arr2);
                cout << "Intersection of arrays: ";
                arr3->Display();
                delete arr3;
                break;
            }
            case 26: {
                cout << "Enter the size of the second array: ";
                int size2;
                cin >> size2;
                Array arr2(size2);
                cout << "Enter elements of the second array:\n";
                for (int i = 0; i < size2; i++) {
                    cin >> x;
                    arr2.Append(x);
                }
                Array *arr3 = arr.Difference(&arr2);
                cout << "Difference of arrays: ";
                arr3->Display();
                delete arr3;
                break;
            }
            case 27:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 27);

    return 0;
}
