#include<iostream>

using namespace std;

int main()
{
    // Array declaration and initialization
    int A[5];
    int B[5]={1,2,3,4,5};
    int C[10]={2,4,6};
    int D[5]={0};
    int E[]={1,2,3,4,5,6};


    // Printing the elements of array A
    for(int i=0;i<5;i++)
        cout<<&A[i]<<endl;
    return 0;
}