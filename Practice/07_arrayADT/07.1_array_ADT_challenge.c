// single missing element in sorted array
// multiple missing element in sorted array
// missing element in unsorted array

#include<stdio.h>
#include<stdlib.h>

struct  Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are \n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);

}

// function to find missing value of natural number
int MissingNatural(struct Array arr)
{
    int total = (arr.length + 1) * (arr.length + 2) / 2;
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return total - sum;
}

// function to find missing value of sorted array of contineous number not started from 1
int Missing(struct Array arr)
{
    int i, x;
    int diff=arr.A[0]-0;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i!=diff)
        {
            printf("Missing elements is %d\n",i+diff);
            break;
        }

    }
}

// function to find more than 1 missing element in an array or continueously more than one elelemt is missing togather order is (n);
int MissingMore(struct Array arr)
{
    int i, x;
    int diff=arr.A[0]-0;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i!=diff)
        {
           while(diff<arr.A[i]-i)
           {
            printf("Missing elements is %d\n",i+diff);
            diff++;
           }
        }

    }
}

// Another method to find missing value faster than perivious method using hash method or bit set;
void MissingMethod2(struct Array arr)
{
    int i, l, h;
    l = arr.A[0];
    h = arr.A[0];
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < l)
            l = arr.A[i];
        if (arr.A[i] > h)
            h = arr.A[i];
    }

    int *H = (int *)calloc(h + 1, sizeof(int));

    for (i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    printf("Missing elements are: ");
    for (i = l; i <= h; i++)
    {
        if (H[i] == 0)
            printf("%d ", i);
    }
    printf("\n");

    free(H);
}

// finding dublicate in an array
void find_Dublicate(struct Array arr)
{
    int i,lastdublicate=0;
    for (i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] == arr.A[i+1] && arr.A[i]!=lastdublicate)
        {
            printf("%d ",arr.A[i]);
            lastdublicate=arr.A[i];
        }
    }
    printf("\n");
}

//counting dublicate in sorted array
void Dublicate_Count(struct Array arr)
{
    int i,j;
    for (i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            j=i+1;
            while(arr.A[j]==arr.A[i])j++;
            printf("%d  is appearing %d times",arr.A[i],j-i);
            i=j-1;
        }
    }
}

// finding dublicate in an array using hashing method
void find_Duplicate_Hashing(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }

    int *H = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    printf("Duplicate elements are: ");
    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1)
            printf("%d ", i);
    }
    printf("\n");

    free(H);
}

// finding dublicates in an unsorted array
void Dublicate_unsorted(struct Array arr)
{
    int i,j;
    for(i=0;i<arr.length-1;i++)
    {
        int count=1;
        if(arr.A[i]!=-1)
        {
            for(j=i+1;j<arr.length;j++)
            {
                if(arr.A[i]==arr.A[j])
                {
                    count++;
                    arr.A[j]=-1;
                }
            }
        } if(count>1)
            printf("%d is appearing %d times\n",arr.A[i],count);
    }
}

// finding dublicates in an unsorted array using hashing
// finding duplicates in an unsorted array using hashing
void find_Duplicate_Hashing_Unsorted(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }

    int *H = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    printf("Duplicate elements are: ");
    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1)
            printf("%d is appearing %d times\n", i, H[i]);
    }

    free(H);
}

//finding a pair of elements with sum K method 1
void find_Pair_With_Sum1(struct Array arr)
{
    int i,j,k=13;
    for(i=0;i<arr.length;i++)

    {
        for(j=i+1;j<arr.length;j++)
        {
            if(arr.A[i]+arr.A[j]==k)
            {
                printf("%d + %d = %d:\n",arr.A[i],arr.A[j],k);
            }
        }
    }
}

//finding a pair of elements with sum K method 2
void find_Pair_With_Sum(struct Array arr, int K)
{
    int *H = (int *)calloc(arr.size, sizeof(int));
    if (H == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < arr.length; i++)
    {
        if (H[K - arr.A[i]] != 0)
        {
            printf("Pair with sum %d is (%d, %d)\n", K, arr.A[i], K - arr.A[i]);
        }
        H[arr.A[i]]++;
    }

    free(H);
}

// finding a pair of elements with sum K in sorted array
void find_Pair_With_Sum_Sorted(struct Array arr, int K)
{
    int i = 0;
    int j = arr.length - 1;

    while (i < j)
    {
        int sum = arr.A[i] + arr.A[j];
        if (sum == K)
        {
            printf("Pair with sum %d is (%d, %d)\n", K, arr.A[i], arr.A[j]);
            i++;
            j--;
        }
        else if (sum < K)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

void find_Max_Min(struct Array arr, int *max, int *min)
{
    *max = arr.A[0];
    *min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > *max)
        {
            *max = arr.A[i];
        }
        else if (arr.A[i] < *min)
        {
            *min = arr.A[i];
        }
    }
}

int main()

{
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14}, 10, 10};

    find_Pair_With_Sum(arr,15);
    

    // Display(arr);

   
    return 0;
    
}