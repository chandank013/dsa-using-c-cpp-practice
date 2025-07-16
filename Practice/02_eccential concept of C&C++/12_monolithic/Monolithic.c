/* ** monolithic programming
=> all code written inside the main sectionm*/


#include <stdio.h>

int main()
{
    int length=0,breadth=0;

    printf("Enter the length:");
    scanf("%d",&length);
    printf("Enter the breadth:");
    scanf("%d",&breadth);

    int area=length*breadth;
    int peri=2*(length+breadth);

    printf("area is:%d\n",area);
    printf("area is:%d\n",peri);

    return 0;
}