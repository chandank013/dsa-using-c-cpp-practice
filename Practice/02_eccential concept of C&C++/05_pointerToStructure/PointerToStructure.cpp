#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r={5,12};
    printf("%d",r.length);
    printf("%d",r.breadth);
    printf("\n");
    
    struct Rectangle *p=&r;

    printf("%d",(*p).length);
    printf("%d",p->length);


    // directly accessing of memory in heap using malloc.
    struct Rectangle *p;
    // c lang
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));

    printf("%d",p->length);
    printf("%d",p->breadth);


    // c++ lang
    p=new Rectangle;

    printf("%d",p->length);
    printf("%d",p->breadth);

    return 0;
}