// point to cover
// 1. Why pointers   -pointer is address varible that is used for accessing the data indirectly , accessing heap, and resources also for parameter passing
// 2. Declarition
// 3. Initialisation
// 4. Dereferencing
// 5. Dynamic Allocation

#include <stdio.h>




int main()
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    printf("%d\n", sizeof(p1));
    printf("%d\n", sizeof(p2));
    printf("%d\n", sizeof(p3));
    printf("%d\n", sizeof(p4));
    printf("%d\n", sizeof(p5));
    printf("\n");


    int a=10;

    int *p;
    p=&a;

    printf("%d\n", a);
    printf("%d\n", p);
    printf("%d\n", *p);


    // creation of array using pointer
    int A[5]={2,4,5,6,7};
    p=A;

    for(int i = 0;i<5;i++)
    {
        printf("%d",p[i]);
    }
    printf("\n");


    // in c++
    /*p=new int[5];  
    p[0]=10,p[1]=15,p[2]=16,p[3]=18,p[4]=11;

    for(int i = 0;i<5;i++)
    {
        printf("%d",p[i]);
    }
    delete [ ]p;   // realising of memory*/

    
    // directly access memory in heap using (malloc)
    p=(int *)malloc(5*sizeof(int));
    p[0]=10,p[1]=15,p[2]=16,p[3]=18,p[4]=11;

    for(int i = 0;i<5;i++)
    {
        printf("%d",p[i]);
    }

    free(p);  // realising of memory

    return 0;
}