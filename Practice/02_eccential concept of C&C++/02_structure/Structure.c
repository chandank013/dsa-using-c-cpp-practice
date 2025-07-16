#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

struct Card
{
    int face;
    int shape;
    int color;
};



int main()
{
    // struct Rectangle r={5,6}; // declearisation & initialisation togather

    struct Rectangle r;
    r.length=12;
    r.breadth=32;

    printf("%d\n ", sizeof(r) );
    printf("Area of rectangle is %d\n", r.length*r.breadth);

    
    struct Card deck[52]={{1,0,0},{2,0,0},{1,1,0},{2,1,0}};

    printf("%d\n ", sizeof(deck));
    printf("%d\n",deck[0].face);
    printf("%d\n",deck[0].shape);



    return 0;
}