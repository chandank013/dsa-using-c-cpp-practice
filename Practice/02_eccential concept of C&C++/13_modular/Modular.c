/* ** modular programming 
=> in which all the user intruction part of code written inside the main section and process are defined as the function that should be callable any part of code to proform action.
*/

int area(int l, int b)
{
    int p;
    p=l*b;
    return p;
}
int peri(int l, int b)
{
    int p;
    p=2*(l+b);
    return p;
}


#include <stdio.h>

int main()
{
    int length=0,breadth=0;

    printf("Enter the length:");
    scanf("%d",&length);
    printf("Enter the breadth:");
    scanf("%d",&breadth);


    printf("area is:%d\n",area(length,breadth));
    printf("area is:%d\n",peri(length,breadth));

    return 0;
}