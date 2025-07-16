// What are Function.
// Parameter passing
    // 1.pass by value
    // 2.pass by address
    // 1.pass by References

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int add(int a,int b)  // formal parameter
{
    int c;
    c=a+b;
    return c;
}

int main()
{
    int x,y,z;
    x=5;
    y=34;
    z=add(x,y);  // actual parameter
    printf("Sum of num is:%d\n",z);

    cout<<"Sum is:"<<z;

    return 0;
}