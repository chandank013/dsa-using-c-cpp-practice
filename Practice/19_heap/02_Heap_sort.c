#include<stdio.h>
#include<stdlib.h>

void insert(int H[],int n)
{
    int i=n,temp;
    temp=H[i];
    while(i>1 && temp>H[i/2])  // for min heap changed temp>H[i/2] to temp<H[i/2]
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
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
    int H[]={0,10,20,30,25,5,40,35};

    int i;
    for(i=2;i<=7;i++)
        insert(H,i);

    for(i=7;i>1;i--) 
    { 
        Delete(H,i); 
    }

    for(i=1;i<=7;i++)
        printf("%d ",H[i]);
    printf("\n");

    return 0;
}
