// Bubble sort
#include <stdio.h>
#include <stdlib.h>

// function to swap two numbers
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort function
void Bubble(int A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}

//For array adaptive mean if array is already sorted 
void Bubble1(int A[], int n)

{
    int i,j,flag=0;

    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if (A[j]>A[j+1])
                swap (&A[j],&A[j+1]);
                flag = 1;
        }
        if(flag==0)
            break;
    }
}

// insertion sort function of an array
void Insertion(int A[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j]; // shift the element to right 
            j--;
        }
        A[j + 1] = x; // insert the element at correct position
    }
}

// selection sort function of an array
void Selection(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

// Quick sort or selection exchange sort or partition exchange sort function of an array
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j) 
            swap(&A[i], &A[j]);
    } while (i < j); 
    swap(&A[l], &A[j]);
    return j;
}
// Quick sort function of an array using recursion
void Quick(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        Quick(A, l, j);
        Quick(A, j + 1, h);
    }
}

// Merge sort of two arrays in third array $$ work for two arrays
void MergeSort1(int A[], int B[], int C[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    for (; i < m; i++)
        C[k++] = A[i];
    for (; j < n; j++)
        C[k++] = B[j];
}

// Merge sort function of an array $$ work for single array
void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

// Merge sort function of an array in iterative way
void IMergeSort(int A[], int n)
{
    int p, i, l, mid, h;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        // Merge(A, 0, p/2-1 , n); // if n is not multiple of 2
        Merge(A, 0, p/2 , n); // if n is multiple of 2
}


// Merge sort function of an array using recursion
void RMergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

// function to find the maximum element in an array for counting sort
int findMax(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

// counting sort function of an array 
void CountingSort(int A[], int n)
{
    int i, j, max, *C;
    max = findMax(A, n);
    C = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}

// function for bin/bucket sort and free() is used to free the memory
void BinSort(int A[], int n)
{
    int i, j;
    int max = findMax(A, n);
    int *B[n];
    for (i = 0; i < n; i++)
    {
        B[i] = (int *)malloc(sizeof(int) * (max + 1));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < max + 1; j++)
        {
            B[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        B[i][A[i]]++;
    }
    i = j = 0;
    while (i < n)
    {
        if (B[i][j] > 0)
        {
            A[i++] = j;
            B[i][j]--;
        }
        else
            j++;
    }
    for (i = 0; i < n; i++)
    {
        free(B[i]);
    }
}


// function for radix only
void Radix(int A[], int n, int div)
{
    int i, j, k, B[n], C[10];
    for (i = 0; i < 10; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[(A[i] / div) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        B[--C[(A[i] / div) % 10]] = A[i];
    }
    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
}

// function for radix sort
void RadixSort(int A[], int n)
{
    int i, max, digits = 0, div = 1;
    max = findMax(A, n);
    while (max > 0)
    {
        digits++;
        max = max / 10;
    }
    for (i = 0; i < digits; i++)
    {
        Radix(A, n, div);
        div = div * 10;
    }
}


// shell sort function of an array using for very large size of array
void ShellSort(int A[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}


// main function
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10, i;
    
    ShellSort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}

// // code for insertion sort in linked list
// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// } *first = NULL;

// void create(int A[], int n)
// {
//     int i;
//     struct Node *t, *last;
//     first = (struct Node *)malloc(sizeof(struct Node));
//     first->data = A[0];
//     first->next = NULL;
//     last = first;

//     for (i = 1; i < n; i++)
//     {
//         t = (struct Node *)malloc(sizeof(struct Node));
//         t->data = A[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

// void Display(struct Node *p)
// {
//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }

// // function to count the number of nodes in a linked list
// int count(struct Node *p)
// {
//     int l = 0;
//     while (p)
//     {
//         l++;
//         p = p->next;
//     }
//     return l;
// }



// int main()
// {
//     int A[] = {10, 20, 30, 40, 50};
//     create(A, 5);

//     Insert(first, 0, 355);

//     Display(first);

//     return 0;
// }
