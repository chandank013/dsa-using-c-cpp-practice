// // 01 Array ADT (Abstract Data Type) in C 

// #include <stdio.h>
// #include <stdlib.h>

// struct Array 
// {
//     int *A;
//     int size;
//     int length;

// };

// void Display(struct Array arr )
// {
//     int i;
//     printf("\n Elements are \n");
//     for(i=0;i<arr.length;i++)
//         printf("%d",arr.A[i]);


// }
// int main()
// {
//     struct Array arr; 
//     int n,i;
//     printf("Enter the size of an array:");
//     scanf("%d",&arr.size);
//     arr.A=(int *)malloc(arr.size*sizeof(int));
//     arr.length=0; //Initially length is 0 


//     printf("Enter number of elements:");
//     scanf("%d",&n);

//     printf("Enter all Elements:\n");
//     for (i=0;i<n;i++)
//         scanf("%d",&arr.A[i]);
//     arr.length=n;

//     Display(arr);


//     return 0;
// }

// //For array adaptive mean that we can change the size of array at runtime

// #include <stdio.h>
// #include <stdlib.h>


// struct Array
// {
//     int A[20];
//     int size;
//     int length;

// };

// void Display(struct Array arr )
// {
//     int i;
//     printf("\n Elements are \n");
//     for(i=0;i<arr.length;i++)
//         printf("%d",arr.A[i]);


// }
// int main()
// {
//     struct Array arr={{2,3,4,5,6},20,5};

//     Display(arr);


//     return 0;
// }




// create an array of 10 elements and display them.

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;

};


// code for traversing the array
void Display(struct Array arr)
{
    int i;
    printf("Elements are \n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);

}

// code for inserting the element at end in the array
void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

// code for inserting the element at any index in the array
void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

// code for deleting the element at end in the array
int Delete(struct Array *arr)
{
    int x=0;
    if(arr->length>0)
    {
        x=arr->A[arr->length-1];
        arr->length--;
        return x;
    }
    return 0;
}

// code for deleting the element at any index in the array
int AnyDelete(struct Array *arr,int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

// code for swapping the elements in the array
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

// code for linear search in the array
int LinearSearch(struct Array *arr,int key) // * before arr is used to pass the address of the array
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

// code for binary search in the array
int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

// code for binary search in the array using recursion
int RBinarySearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else
            return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}

// code for get function in the array
int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

// code for set function in the array
void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}

// code for max function in the array

int Max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

// code for min function in the array
int Min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

// code for sum function in the array
int Sum(struct Array arr)
{
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
        s+=arr.A[i];
    return s;
}

// code for sum using recursion function in the array
int Rsum(int A[],int n) // n is the length of the array
{
    if(n==0) // base condition
        return 0;
    return Rsum(A,n-1)+A[n-1]; // n-1 is the last element of the array
}

// code for avg function in the array
float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

// code for reverse function of an array using auxilary array
void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    B[j]=arr->A[i];

    for(i=0;i<arr->length;i++)
    arr->A[i]=B[i];

}

// code for reverse function of an array using swapping
void ReverseSwap(struct Array *arr)
{
    int i,j,temp;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
    // swap(arr->A[i],&arr->A[j]);

}


// code for left shift function in the array
void LeftShift(struct Array *arr)
{
    int i;
    for(i=0;i<arr->length;i++)
        arr->A[i]=arr->A[i+1];
    arr->length--;
}

// code for left rotate function in the array
void LeftRotate(struct Array *arr)
{
    int i;
    int temp=arr->A[0];
    for(i=0;i<arr->length;i++)
        arr->A[i]=arr->A[i+1];
    arr->A[arr->length-1]=temp;
}

// code for insert in sorted array function in the array
void insertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
        {
            arr->A[i+1]=arr->A[i];
            i--;
        }
    arr->A[i+1]=x;
    arr->length++;
}

// code for check if array is sorted function in the array
int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

// code for rearrange function in the array
void Rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
    }
}

// code for merge function in the array
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)  // code for adding remaining elements of arr1
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)  // code for adding remaining elements of arr2
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}


// Function to perform union of two arrays when arrays are not sorted
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    arr3->length = 0;

    // Add all elements of arr1 to arr3
    for (i = 0; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
        arr3->length++;
    }

    // Add elements of arr2 to arr3 if they are not already present
    for (j = 0; j < arr2->length; j++)
    {
        int found = 0;
        for (i = 0; i < arr1->length; i++)
        {
            if (arr2->A[j] == arr1->A[i])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            arr3->A[k++] = arr2->A[j];
            arr3->length++;
        }
    }

    return arr3;
}

// Function to perform union of two sorted arrays
struct Array* Union1(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    arr3->length = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else if(arr2->A[j] == arr1->A[i]) 
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)  // code for adding remaining elements of arr1
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++) // code for adding remaining elements of arr2
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    return arr3;
}

// Function to perform intersection of two arrays when arrays are not sorted
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    arr3->length = 0;

    // Check for common elements between arr1 and arr2
    for (i = 0; i < arr1->length; i++)
    {
        for (j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j])
            {
                // Check if the element is already in arr3
                int found = 0;
                for (int l = 0; l < arr3->length; l++)
                {
                    if (arr3->A[l] == arr1->A[i])
                    {
                        found = 1;
                        break;
                    }
                }
                // If the element is not in arr3, add it
                if (!found)
                {
                    arr3->A[k++] = arr1->A[i];
                    arr3->length++;
                }
                break;
            }
        }
    }

    return arr3;
}

// Function to perform intersection of two sorted arrays
struct Array* Intersection1(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    arr3->length = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if(arr2->A[j] == arr1->A[i]) 
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;

    return arr3;
}

// Function to perform difference of two unsorted arrays (n^2)
struct Array* DifferenceUnsorted(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    arr3->length = 0;

    // Add elements of arr1 to arr3 if they are not present in arr2
    for (i = 0; i < arr1->length; i++)
    {
        int found = 0;
        for (j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            arr3->A[k++] = arr1->A[i];
            arr3->length++;
        }
    }

    return arr3;
}

// Function to perform difference of two sorted arrays (n)
struct Array* DifferenceSorted(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = 10;
    arr3->length = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)  // only copy the remaining element of arr1
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;

    return arr3;
}

// function for set membership 
int IsMember(struct Array arr, int element) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == element) {
            return 1; // Element found
        }
    }
    return 0; // Element not found
}


// function for copying 

// main function
int main()
{
    struct Array arr={{2,3,5,10,15},10,5};
    int element=10;

    // struct Array arr1 = {{2, 6, 9, 10, 13}, 10, 5}; (only for set and merse)
    // struct Array arr2 = {{2, 8, 10, 13, 15}, 10, 5};
    // struct Array *arr3;
 
    
    
    // Display(arr);


    // printf("%d",IsMember(arr, element));
    // // Free the allocated memory  //(only for set)
    // free(arr3);

    return 0;
}






// // Menu Driven Program for an array
// int main() {

//     struct Array arr = {{2, 3, 5, 10, 15}, 10, 5};
//     int choice, x, index;

//     do {
//         printf("\nMenu\n");
//         printf("1. Display\n");
//         printf("2. Append\n");
//         printf("3. Insert\n");
//         printf("4. Delete\n");
//         printf("5. Delete at index\n");
//         printf("6. Linear Search\n");
//         printf("7. Binary Search\n");
//         printf("8. Get\n");
//         printf("9. Set\n");
//         printf("10. Max\n");
//         printf("11. Min\n");
//         printf("12. Sum\n");
//         printf("13. Average\n");
//         printf("14. Reverse\n");
//         printf("15. Left Shift\n");
//         printf("16. Left Rotate\n");
//         printf("17. Insert in Sorted Array\n");
//         printf("18. Check if Sorted\n");
//         printf("19. Rearrange\n");
//         printf("20. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 Display(arr);
//                 break;
//             case 2:
//                 printf("Enter element to append: ");
//                 scanf("%d", &x);
//                 Append(&arr, x);
//                 break;
//             case 3:
//                 printf("Enter index and element to insert: ");
//                 scanf("%d %d", &index, &x);
//                 Insert(&arr, index, x);
//                 break;
//             case 4:
//                 x = Delete(&arr);
//                 if (x != 0)
//                     printf("Deleted element is %d\n", x);
//                 else
//                     printf("Array is empty\n");
//                 break;
//             case 5:
//                 printf("Enter index to delete: ");
//                 scanf("%d", &index);
//                 x = AnyDelete(&arr, index);
//                 if (x != 0)
//                     printf("Deleted element is %d\n", x);
//                 else
//                     printf("Invalid index\n");
//                 break;
//             case 6:
//                 printf("Enter element to search: ");
//                 scanf("%d", &x);
//                 index = LinearSearch(&arr, x);
//                 if (index != -1)
//                     printf("Element found at index %d\n", index);
//                 else
//                     printf("Element not found\n");
//                 break;
//             case 7:
//                 printf("Enter element to search: ");
//                 scanf("%d", &x);
//                 index = BinarySearch(arr, x);
//                 if (index != -1)
//                     printf("Element found at index %d\n", index);
//                 else
//                     printf("Element not found\n");
//                 break;
//             case 8:
//                 printf("Enter index to get element: ");
//                 scanf("%d", &index);
//                 x = Get(arr, index);
//                 if (x != -1)
//                     printf("Element at index %d is %d\n", index, x);
//                 else
//                     printf("Invalid index\n");
//                 break;
//             case 9:
//                 printf("Enter index and element to set: ");
//                 scanf("%d ", &index, &x);
//                 Set(&arr, index, x);
//                 break;
//             case 10:
//                 printf("Max element is %d\n", Max(arr));
//                 break;
//             case 11:
//                 printf("Min element is %d\n", Min(arr));
//                 break;
//             case 12:
//                 printf("Sum of elements is %d\n", Sum(arr));
//                 break;
//             case 13:
//                 printf("Average of elements is %.2f\n", Avg(arr));
//                 break;
//             case 14:
//                 Reverse(&arr);
//                 printf("Array reversed\n");
//                 break;
//             case 15:
//                 LeftShift(&arr);
//                 printf("Array left shifted\n");
//                 break;
//             case 16:
//                 LeftRotate(&arr);
//                 printf("Array left rotated\n");
//                 break;
//             case 17:
//                 printf("Enter element to insert in sorted array: ");
//                 scanf("%d", &x);
//                 insertSort(&arr, x);
//                 break;
//             case 18:
//                 if (isSorted(arr))
//                     printf("Array is sorted\n");
//                 else
//                     printf("Array is not sorted\n");
//                 break;
//             case 19:
//                 Rearrange(&arr);
//                 printf("Array rearranged\n");
//                 break;
//             case 20:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }
//     } while (choice != 20);

//     return 0;
// }


// // Menu Driven Program for an array
// int main() {
//     struct Array arr1 = {{2, 3, 5, 10, 15}, 10, 5};
//     struct Array arr2 = {{3, 6, 7, 10, 12}, 10, 5};
//     struct Array *arr3;
//     int choice;

//     do {
//         printf("\nMenu\n");
//         printf("1. Display Array 1\n");
//         printf("2. Display Array 2\n");
//         printf("3. Union\n");
//         printf("4. Intersection\n");
//         printf("5. Difference\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 Display(arr1);
//                 break;
//             case 2:
//                 Display(arr2);
//                 break;
//             case 3:
//                 arr3 = Union(&arr1, &arr2);
//                 printf("Union of Array 1 and Array 2:\n");
//                 Display(*arr3);
//                 free(arr3);
//                 break;
//             case 4:
//                 arr3 = Intersection(&arr1, &arr2);
//                 printf("Intersection of Array 1 and Array 2:\n");
//                 Display(*arr3);
//                 free(arr3);
//                 break;
//             case 5:
//                 arr3 = DifferenceUnsorted(&arr1, &arr2);
//                 printf("Difference of Array 1 and Array 2:\n");
//                 Display(*arr3);
//                 free(arr3);
//                 break;
//             case 6:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }
//     } while (choice != 6);

//     return 0;
// }