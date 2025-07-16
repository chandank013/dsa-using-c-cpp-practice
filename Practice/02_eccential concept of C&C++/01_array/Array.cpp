#include <iostream>
#include<stdio.h>

using namespace std;



int main()
{
    int A[5];  // decrearisation of an array
    A[0]=3;
    A[1]=7;
    A[2]=5;
    A[3]=9;
    A[4]=8;

    cout<<sizeof(A)<<endl;    
    cout<<A[1]<<endl;    

    // from c languange
    printf("%d\n",A[2]);


    // decrearisation & initialisation of an array
    int B[]={6,7,4,8,5,12,54};

    cout<<sizeof(B)<<endl; 
    cout<<B[1]<<endl;    

    printf("%d\n",B[2]);

    // for loop
    for(int i=0;i<7;i++)
    {
        cout<<B[i]<<endl;
    }

    /*// for-each loop
    for(int x:B)
    {
        cout<<x;
    }*/


    // array forming using input from user
    int n;
    cout<<"Enter the size:";
    cin>>n;
    int C[n];  // we should not be iniatialise due to it's drowback

    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<C[i]<<endl;
    }

    return 0;
}