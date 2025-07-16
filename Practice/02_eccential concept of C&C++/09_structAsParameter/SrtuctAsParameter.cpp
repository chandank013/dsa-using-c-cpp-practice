#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};


// call by value
int area(struct Rectangle r1)
{
    r1.length=20;
    return r1.length*r1.breadth;
}


// call by referance
int area1(struct Rectangle &r1)
{
    r1.length++;
    return r1.length*r1.breadth;
}


// call by address
int changeLength(struct Rectangle *p, int l)
{
    p->length=l;
    printf("length %d \nbreadth %d \n",p->length,p->breadth);
}


struct Test
{
    int A[5];
    int n;
};

void fun(struct Test t1)  // array can only call by address but it can pass by value if it present in a stucture
{
    t1.A[0]=23;
    t1.A[1]=27;
}


//  create a variable of type structure in heap inside a function and returns its address
struct Rectangle *fun1()
{
    struct Rectangle *p;
    // p= (struct Rectangle *)malloc(sizeof(struct Rectangle));  // in c Lang
    p=new Rectangle;   // In c++ lang

    p->length=23;
    p->breadth=25;

    return p;
    
}

int main()
{
    struct Rectangle r={5,10};

    printf("length %d \nbreadth %d \n",r.length,r.breadth);
    printf("%d\n",area(r));

    printf("%d\n",area1(r));
    printf("length %d \nbreadth %d \n",r.length,r.breadth);

    changeLength(&r,20);
    printf("length %d \nbreadth %d \n",r.length,r.breadth);
    printf("%d\n",area1(r));

    struct Test t={{2,3,5,6,8},5};
    fun(t);


    struct Rectangle *ptr=fun1();  // create a structure in heap
    printf("length %d \n breadth%d \n", ptr->length,ptr->breadth);

    
    return 0;
}