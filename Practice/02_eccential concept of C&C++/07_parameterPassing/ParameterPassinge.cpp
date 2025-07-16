
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// pass by  value (actual parameter is not modified )
void Swap(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

// call by  value (actual parameter is modified )
void Swap1(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

// call by  references (actual parameter is modified C++)
void Swap2(int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int main()
{
    int x, y;
    x=25;
    y=52;

    Swap(x,y);
    printf("%d %d\n", x,y);

    Swap1(&x,&y);
    printf("%d %d\n", x,y);

    Swap2(x,y);  // don't use frequently in comolex logic.
    printf("%d %d\n", x,y);
    


    return 0;
}