#include<stdio.h>
#include<stdlib.h>

// max heap implementation
void insert(int H[],int n)
{
    int i=n,temp;
    temp=H[i];
    while(i>1 && temp>H[i/2])
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
}

void createHeap(int A[],int n)
{
    int i;
    for(i=2;i<=n;i++)
    {
        insert(A,i);
    }
}

void display(int A[],int n)
{
    int i;
    for(i=1;i<=n;i++)
        printf("%d ",A[i]);
    printf("\n");
}

int Delete(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];

    A[n]=val;

    i=1;j=i*2;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;

        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
     
}

int main()
{
    int A[]={0,10,20,30,25,5,40,35};

    createHeap(A,7);
    printf("Heap is:\n");
    display(A,7);
   

    return 0;
}


// min heap implementation
void insert(int H[],int n)
{
    int i=n,temp;
    temp=H[i];
    while(i>1 && temp<H[i/2])
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
}

void createHeap(int A[],int n)
{
    int i;
    for(i=2;i<=n;i++)
    {
        insert(A,i);
    }
}

void display(int A[],int n)

{
    int i;
    for(i=1;i<=n;i++)
        printf("%d ",A[i]);
    printf("\n");
}

int Delete(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];

    A[n]=val;

    i=1;j=i*2;
    while(j<n-1)
    {
        if(A[j+1]<A[j])
            j=j+1;

        if(A[i]>A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
     
}

int main()
{
    int A[]={0,10,20,30,25,5,40,35};

    createHeap(A,7);
    printf("Heap is:\n");
    display(A,7);
   

    return 0;
}


// it can also implemented in priority queue



