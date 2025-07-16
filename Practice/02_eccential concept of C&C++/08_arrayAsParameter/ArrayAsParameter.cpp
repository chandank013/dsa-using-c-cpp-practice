#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


// we cannot use for each loop on pointer
/*void fun2(int A[])
{
    for(int a:A)
    {
        printf("%d", a)
    }
}*/

void fun(int A[], int n) // we can replace A[]==*A;
{
    int i;
    A[0]=11;
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
}

// return an array;
int * fun1(int n)
{
    int *p;
    p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        p[i]=i+1;
    }
    return(p);
}

int main()
{
    int A[5]={2,4,5,6,7};

    // printing the array
    int n=5,i;
    for(i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
    printf("\n");

    // printing the array by passing array as function
    fun(A,5);
    printf("\n");


    int *ptr,sz=5;
    ptr=fun1(sz);
    for(int i=0;i<sz;i++)
    {
        printf("%d",ptr[i]);
    }


    return 0;
}

