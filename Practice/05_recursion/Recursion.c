// // perform operation while calling
// void fun(int n)
// {
//     if(n>0)
//     {
//         printf("%d ",n);
//         fun(n-1);
//     }
// }
// int main(){
//     int x=3;

//     fun(x);
//     return 0;
// }


// // perform operation while returning
// void fun(int n)
// {
//     if(n>0)
//     {
//         fun(n-1);
//         printf("%d ",n);
//     }
// }
// int main(){
//     int x=3;

//     fun(x);
//     return 0;
// }




// // recursion  having static variable and global variable
// int fun(int n)
// {
//     static int x=0;    //static variable
//     if(n>0)
//     {
//         x++;
//         return fun(n-1) + x;
//     }
//     return 0;
// }

// int main(){
//     int r;
//     r = fun(5);
//     printf("%d\n ",r);
//     return 0;
// } 


// int x=0;    //global variable
// int fun(int n)
// {

//     if(n>0)
//     {
//         x++;
//         return fun(n-1) + x;
//     }
//     return 0;
// }

// int main(){
//     int r;
//     r = fun(5);
//     printf("%d\n ",r);

//     r = fun(5);
//     printf("%d\n ",r);
//     return 0;
// }



// // recursion having multiple calls
// #include <stdio.h>
// #include <stdlib.h>

// void fun(int n)
// {
//     if (n>0)
//     {
//          printf("%d ",n);
//          fun(n-1);
//          fun(n-1);
//     }

// }
// int main()
// {
//     fun(3);
//     return 0;
// }

// indirect recursion
#include <stdio.h>
#include <stdlib.h>

void funB(int n);

void funA(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        funB(n-1);
    }
}

void funB(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        funA(n/2);
    }
}

int main()
{
    funA(20);
    return 0;
}


// nested recursion
#include <stdio.h>
#include <stdlib.h>


int fun(int n)
{
    if(n>100)
        return n-10;
    return fun(fun(n+11));
}



int main()
{
    int r;
    r = fun(95);
    printf("%d ",r);
    return 0;
}
