#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5] = {2,4,6,8,10};
    int *p;     //for pointer
    int i;

    p = (int *)malloc(5*sizeof(int));     //function to allocate array in heap memory
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for(i=0;i<5;i++)
        printf("%d ",A[i]);


    printf("\n");
    for(i=0;i<5;i++)
        printf("%d ",p[i]);

    free(p);  // Free the dynamically allocated memory
    return 0;
}
