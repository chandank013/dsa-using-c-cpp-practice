#include <stdio.h>
#include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// }*first=NULL;

// void create (int A[],int n)
// {
//     int i;
//     struct Node *t,*last;
//     first=(struct Node *)malloc(sizeof(struct Node));
//     first->data=A[0];
//     first->next=NULL;
//     last=first;

//     for(i=1;i<n;i++)
//     {
//         t=(struct Node *)malloc(sizeof(struct Node));
//         t->data=A[i];
//         t->next=NULL;
//         last->next=t;
//         last=t;
//     }
    
// }

// // Display linked list
// void Display(struct Node *p)
// {
//     while(p!=NULL)
//     {
//         printf("%d ",p->data);
//         p=p->next;

//         if (p!=NULL)  // This condition is used to print -> at the end of linked list
//             printf("-> ");
//     }
//     printf("\n");
// }

// // Display linked list using recursion
// void RDisplay(struct Node *p)
// {
//     if(p!=NULL)
//     {
//         // RDisplay(p->next); // print linked list in reverse order
//         printf("%d ",p->data);
//         RDisplay(p->next);
//     }
// }

// // Count number of nodes in linked list
// int count(struct Node *p)
// {
//     int l=0;
//     while(p!=NULL)
//     {
//         l++;
//         p=p->next;
//     }
//     return l;
// }

// // Count number of nodes in linked list using recursion
// int Rcount(struct Node *p)
// {
//     if(p==NULL)
//         return 0;
//     else
//         return Rcount(p->next) + 1;
// }

// // Sum of all elements in linked list
// int add(struct Node *p)
// {
//     int sum=0;
//     while(p!=NULL)
//     {
//         sum+=p->data;
//         p=p->next;
//     }
//     return sum;
// }

// // Sum of all elements in linked list using recursion
// int Radd(struct Node *p)
// {
//     if(p==NULL)
//         return 0;
//     else
//         return Radd(p->next) + p->data;
// }

// // Maximum element in linked list
// int max(struct Node *p)
// {
//     int max=-32768;
//     while(p!=NULL)
//     {
//         if(p->data>max)
//             max=p->data;
//         p=p->next;
//     }
//     return max;
// }

// // Maximum element in linked list using recursion
// int Rmax  (struct Node *p)
// {
//     int x = 0;
//     if (p==0)
//         return -32768;
//     else
//         x = Rmax(p->next);
//         return x>p->data?x:p->data;
    
// }

// // Linear search in linked list
// struct Node * L1search(struct Node *p,int key)
// {
//     while(p!=NULL)
//     {
//         if(p->data==key)
//             return p;
//         p=p->next;
//     }
//     return 0;
// }

// // Linear search in linked list using recursion
// struct Node * Rsearch(struct Node *p,int key)
// {
//     if(p==NULL)
//         return 0;
//     if(key==p->data)
//         return p;
//     return Rsearch(p->next,key);
// }

// // Linear search in linked list using move to head method
// struct Node * MoveNode(struct Node *p,int key)
// {
//     struct Node *q=NULL;

//     while(p!=NULL)
//     {
//         if(p->data==key)
//         {
//             q->next=p->next;
//             p->next=first;
//             first=p;
//             return p;
//         }
//         q=p;
//         p=p->next;
//     }
// }

// //01 creation linkedlist or Insert element at beginning or any of linked list
// void Insert1(struct Node *p,int index,int x)
// {
//     struct Node *t;
//     int i;

//     if(index<0 || index > count(p))
//         return;
//     t=(struct Node *)malloc(sizeof(struct Node));
//     t->data=x;

//     if(index==0)  // Inserting at beginning
//     {
//         t->next=first;
//         first=t;
//     }
//     else  // Inserting at any other position
//     {
//         for(i=0;i<index-1;i++)
//             p=p->next;
//         t->next=p->next;
//         p->next=t;
//     }
// }

// //02 creating linkedlist by inserting element at any position or Insert element at anyposition of linked list
// void Insert2(int pos,int x)
// {
//     struct Node *t,*p;
//     int i;
//     if(pos<=0)
//     {
//         t=(struct Node *)malloc(sizeof(struct Node));
//         t->data=x;
//         t->next=first;
//         first=t;
//     }

//     else if(pos>0)
//     {
//         p=first;
//         for(i=0;i<pos-1 && p;i++)
//             p=p->next;
//         if(p)
//         {
//             t=(struct Node *)malloc(sizeof(struct Node));
//             t->data=x;
//             t->next=p->next;
//             p->next=t;
//         }
//     }
// }

// // create linked list by inserting or Insert element at end of linked list
// void Insertend(struct Node *p,int x)
// {
//     struct Node *t,*last;
//     t=(struct Node *)malloc(sizeof(struct Node));
//     t->data=x;
//     t->next=NULL;
//     if(first==NULL)
//         first=last=t;
//     else
//     {
//         last->next=t;
//         last=t;
//     }
// }

// // inserted element at sorted position in linked list or it create sorted linked list if there is no sorted linked list
// void Insertsort(struct Node *p,int x)
// {
//     struct Node *t,*q=NULL;
//     t=(struct Node *)malloc(sizeof(struct Node));
//     t->data=x;
//     t->next=NULL;
//     if(first==NULL)
//         first=t;
//     else
//     {
//         while(p && p->data<x)
//         {
//             q=p;
//             p=p->next;
//         }
//         if(p==first)
//         {
//             t->next=first;
//             first=t;
//         }
//         else
//         {
//             t->next=q->next;
//             q->next=t;
//         }
//     }
// }

// // Delete first or any node of linked list
// int Delete_Beg_Any(struct Node *p,int index)
// {
//     struct Node *q=NULL;
//     int x=-1,i;

//     if(index < 1 || index > count(p)) // Checking if index is valid or not
//         return -1;
//     if(index==1) // Deleting first node
//     {
//         q=first;
//         x=first->data;
//         first=first->next;
//         free(q);
//         return x;
//     }
//     else
//     {
//         for(i=0;i<index-1;i++) // Deleting any other node
//         {
//             q=p;
//             p=p->next;
//         }
//         q->next=p->next;
//         x=p->data;
//         free(p);
//         return x; 
//     }
// }

// // Delete node without counting number of nodes
// void Delete(struct Node *p,int index)
// {
//     struct Node *q=NULL;
//     int i,x=-1;

//     if(index < 1) // Checking if index is valid or not
//         return  ;
//     if(index==1) // Deleting first node
//     {
//         q=first;
//         x=first->data;
//         first=first->next;
//         free(q);
//         printf("Deleted element is %d\n",x);
//         return ;
//     }
//     else
//     {
//         for(i=0;i<index-1&& index;i++) // Deleting any other node
//         {
//             q=p;
//             p=p->next;
//         }
//         if (p)
//         {
//             q->next=p->next;
//             x=p->data;
//             free(p);
//             printf("Deleted element is %d\n",x);
//             return ;
//         }
//     }
// }

// // Delete node from end of linked list
// int Deleteend(struct Node *p)
// {
//     struct Node *q=NULL;
//     int x=-1;

//     if(first==NULL) // Checking if linked list is empty or not
//         return -1;
//     if(first->next==NULL) // Deleting only node of linked list
//     {
//         x=first->data;
//         free(first);
//         first=NULL;
//         return x;
//     }
//     else
//     {
//         while(p->next!=NULL)
//         {
//             q=p;
//             p=p->next;
//         }
//         q->next=NULL;
//         x=p->data;
//         free(p);
//         return x;
//     }
// }

// // Check if linked list is sorted or not
// int isSorted(struct Node *p)
// {
//     int x=-65536;
//     while(p!=NULL)
//     {
//         if(p->data<x)
//             return 0;
//         x=p->data;
//         p=p->next;
//     }
//     return 1;
// }


// // code to remove duplicate elements from sorted linked list
// void RemoveDuplicate(struct Node *p)
// {
//     struct Node *q=p->next;
//     while(q!=NULL)
//     {
//         if(p->data!=q->data)
//         {
//             p=q;
//             q=q->next;
//         }
//         else
//         {
//             p->next=q->next;
//             free(q);
//             q=p->next;
//         }
//     }
// }



// // reversing using copy data in an array
// void Reverse1(struct Node *p)
// {
//     int *A,i=0;
//     struct Node *q=p;
//     A=(int *)malloc(sizeof(int)*count(p));

//     while(q!=NULL)
//     {
//         A[i]=q->data;
//         q=q->next;
//         i++;
//     }
//     q=p;
//     i--;
//     while(q!=NULL)
//     {
//         q->data=A[i];
//         q=q->next;
//         i--;
//     }
// }


// // code to reverse linked list using sliding pointers modification OF LINKS
// void Reverse(struct Node *p)
// {
//     struct Node *q=NULL,*r=NULL;
//     while(p!=NULL)
//     {
//         r=q;
//         q=p;
//         p=p->next;
//         q->next=r;
//     }
//     first=q;
// }

// // code to reverse linked list using recursion
// void RReverse(struct Node *q,struct Node *p)
// {
//     if(p)
//     {
//         RReverse(p,p->next);
//         p->next=q;
//     }
//     else
//         first=q;
// }

// // code to concatenate two linked list
// void Concatenate(struct Node *p,struct Node *q)
// {
//     while(p->next!=NULL)
//         p=p->next;
//     p->next=q;
// }

// // code to merge two linked list
// void Merge(struct Node *p,struct Node *q)
// {
//     struct Node *last;
//     if(p->data<q->data) 
//     {
//         first=last=p;
//         p=p->next;
//         first->next=NULL;
//     }
//     else
//     {
//         first=last=q;
//         q=q->next;
//         first->next=NULL;
//     }
//     while(p!=NULL && q!=NULL) // This condition is used to merge elements of linked list
//     {
//         if(p->data<q->data)
//         {
//             last->next=p;
//             last=p;
//             p=p->next;
//             last->next=NULL;
//         }
//         else
//         {
//             last->next=q;
//             last=q;
//             q=q->next;
//             last->next=NULL;
//         }
//     }
//     if(p!=NULL)  // This condition is used to merge remaining elements of linked list
//     {
//         last->next=p; 
//     }
//     if(q!=NULL)
//     {
//         last->next=q;
//     }
// }

// // code to merge two linked list using recursion
// void RMerge(struct Node *p,struct Node *q)
// {
//     struct Node *r=NULL;
//     if(p->data<q->data)
//     {
//         first=r=p;
//         p=p->next;
//         first->next=NULL;
//     }
//     else
//     {
//         first=r=q;
//         q=q->next;
//         first->next=NULL;
//     }
//     while(p!=NULL && q!=NULL)
//     {
//         if(p->data<q->data)
//         {
//             r->next=p;
//             r=p;
//             p=p->next;
//             r->next=NULL;
//         }
//         else
//         {
//             r->next=q;
//             r=q;
//             q=q->next;
//             r->next=NULL;
//         }
//     }
//     if(p!=NULL)
//     {
//         r->next=p;
//     }
//     if(q!=NULL)
//     {
//         r->next=q;
//     }
// }

// // code to check if linked list is loop or not
// void Loop(struct Node *p)
// {
//     struct Node *q=p;
//     while(p!=NULL)
//     {
//         p=p->next;
//         if(p!=NULL)
//         {
//             p=p->next;
//             q=q->next;
//         }
//         if(p==q)
//         {
//             printf("Loop is present\n");
//             break;
//         }
//     }
//     if(p==NULL)
//         printf("Loop is not present\n");
// }

// // code to find middle element of linked list
// void MiddleElement(struct Node *p)
// {
//     struct Node *q=p;
//     while(p!=NULL)
//     {
//         p=p->next;
//         if(p!=NULL)
//         {
//             p=p->next;
//             q=q->next;
//         }
//         if(p==NULL)
//             break;
//     }
//     printf("Middle element is %d\n",q->data);
// }

// // code to find nth element from end of linked list
// void NthElement(struct Node *p,int index)
// {
//     int i;
//     for(i=0;i<index-1;i++)
//         p=p->next;
//     while(p->next!=NULL)
//     {
//         p=p->next;
//         p=p->next;
//     }
//     printf("%d element from end is %d\n",index,p->data);
// }


// // display of circular linked list
// void DisplayCircular(struct Node *p)
// {
//     do
//     {
//         printf("%d ",p->data);
//         p=p->next;
//         // printf("-> "); // This condition is used to print -> at the end of linked list
//         if(p!=first)
//             printf("-> "); // This condition is used to print -> at the end of linked list
//     }while(p!=first);
//     printf("\n");
// }

// // code for recursive display of circular linked list
// void RDisplayCircular(struct Node *p)
// {
//     static int flag=0;
//     if(p!=first || flag==0)
//     {
//         flag=1;
//         printf("%d ",p->data);
//         if(p->next!=first)  // This condition is used to print -> at the end of linked list
//             printf("-> ");
//         RDisplayCircular(p->next);
        
//     }
//     flag=0;
// }

// // code to insert element in circular linked list
// void InsertCircular(struct Node *p,int index,int x)
// {
//     struct Node *t;
//     int i;

//     if(index<0 || index > count(p))
//         return;
//     t=(struct Node *)malloc(sizeof(struct Node));
//     t->data=x;

//     if(index==0)  // Inserting at beginning
//     {
//         if(first==NULL)
//         {
//             first=t;
//             first->next=first;
//         }
//         else  
//         {
//             while(p->next!=first) 
//                 p=p->next;
//             p->next=t;
//             t->next=first;
//             first=t;
//         }
//     }
//     else  // Inserting at any other position
//     {
//         for(i=0;i<index-1;i++)
//             p=p->next;
//         t->next=p->next;
//         p->next=t;
//     }
// }

// // // code to insert element without count in circular linked list
// //  void InsertCircular1(struct Node *p,int index,int x)
// // {
// //     struct Node *t;
// //     int i;

// //     if(index<0)
// //         return;
// //     t=(struct Node *)malloc(sizeof(struct Node));
// //     t->data=x;

// //     if(index==0)  // Inserting at beginning
// //     {
// //         if(first==NULL)
// //         {
// //             first=t;
// //             first->next=first;
// //         }
// //         else  
// //         {
// //             while(p->next!=first) 
// //                 p=p->next;
// //             p->next=t;
// //             t->next=first;
// //             first=t;
// //         }
// //     }
// //     else  // Inserting at any other position
// //     {
// //         for(i=0;i<index-1;i++)
// //             p=p->next;
// //         t->next=p->next;
// //         p->next=t;
// //     }
// // }

// // code to delete element from circular linked list
// int DeleteCircular(struct Node *p,int index)
// {
//     struct Node *q=NULL;
//     int i,x;

//     if(index < 1) // Checking if index is valid or not
//         return -1;
//     if(index==1) // Deleting first node
//     {
//         while(p->next!=first)
//             p=p->next;
//         x=first->data;
//         if(first==p)
//         {
//             free(first);
//             first=NULL;
//         }
//         else
//         {
//             p->next=first->next;
//             free(first);
//             first=p->next;
//         }
//     }
//     else
//     {
//         for(i=0;i<index-2;i++) // Deleting any other node
//             p=p->next;
//         q=p->next;
//         p->next=q->next;
//         x=q->data;
//         free(q);
//     }
//     return x;
// }







// Duble linked list
// node to create singly linked list
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

// code to create doubly linked list
void createDoubly(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL; 
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

// code to display doubly linked list
void DisplayDoubly(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
        if(p!=NULL)  // This condition is used to print -> at the end of linked list
            printf("<-> ");
    }
    printf("\n");
}

// code to count number of nodes in doubly linked list
int length(struct Node *p)
{
    int len=0;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

// code to insert element in doubly linked list
void InsertDoubly(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index<0 || index > length(p))
    return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)  // Inserting at beginning
    {
        t->prev=NULL;
        t->next=first;
        if(first)
            first->prev=t;
        first=t;
    }
    else  // Inserting at any other position
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}

// // code to insert element at end of doubly linked list
void InsertendDoubly(struct Node *p,int x)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    while(p->next!=NULL)
        p=p->next;
    t->prev=p;
    p->next=t;
}

// code to delete element from doubly linked list
int DeleteDoubly(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index < 1 || index > length(p)) // Checking if index is valid or not
        return -1;
    if(index==1) // Deleting first node
    {
        first=first->next;
        if(first)
            first->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(i=0;i<index-1;i++) // Deleting any other node
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

// code to reverse doubly linked list
void ReverseDoubly(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}

// code to reverse doubly linked list using recursion
void RReverseDoubly(struct Node *p)
{
    struct Node *temp;
    if(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
        RReverseDoubly(p);
    }
}

// code to concatenate two doubly linked list
void ConcatenateDoubly(struct Node *p,struct Node *q)
{
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    q->prev=p;
}

// code to merge two doubly linked list
void MergeDoubly(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        first=last=p;
        p=p->next;
        first->next=first->prev=first;
    }
    else
    {
        first=last=q;
        q=q->next;
        first->next=first->prev=first;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            p->prev=last;
            last=p;
            p=p->next;
            last->next=first;
            first->prev=last;
        }
        else
        {
            last->next=q;
            q->prev=last;
            last=q;
            q=q->next;
            last->next=first;
            first->prev=last;
        }
    }
    if(p!=NULL)
    {
        last->next=p;
        p->prev=last;
        last=p;
        last->next=first;
        first->prev=last;
    }
    if(q!=NULL)
    {
        last->next=q;
        q->prev=last;
        last=q;
        last->next=first;
        first->prev=last;
    }
}

// code to merge two doubly linked list using recursion
void MergeDoubly(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        first=last=p;
        p=p->next;
        first->next=first->prev=first;
    }
    else
    {
        first=last=q;
        q=q->next;
        first->next=first->prev=first;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            p->prev=last;
            last=p;
            p=p->next;
            last->next=first;
            first->prev=last;
        }
        else
        {
            last->next=q;
            q->prev=last;
            last=q;
            q=q->next;
            last->next=first;
            first->prev=last;
        }
    }
    if(p!=NULL)
    {
        last->next=p;
        p->prev=last;
        last=p;
        last->next=first;
        first->prev=last;
    }
    if(q!=NULL)
    {
        last->next=q;
        q->prev=last;
        last=q;
        last->next=first;
        first->prev=last;
    }
}

// code to check if doubly linked list is loop or not
void LoopDoubly(struct Node *p)
{
    struct Node *q=p;
    while(p!=NULL)
    {
        p=p->next;
        if(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        if(p==q)
        {
            printf("Loop is present\n");
            break;
        }
    }
    if(p==NULL)
        printf("Loop is not present\n");
}

// code to find middle element of doubly linked list
void MiddleElementDoubly(struct Node *p)
{
    struct Node *q=p;
    while(p!=NULL)
    {
        p=p->next;
        if(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        if(p==NULL)
            break;
    }
    printf("Middle element is %d\n",q->data);
}

// code to find nth element from end of doubly linked list
void NthElementDoubly(struct Node *p,int index)
{
    int i;
    for(i=0;i<index-1;i++)
        p=p->next;
    while(p->next!=NULL)
    {
        p=p->next;
        p=p->next;
    }
    printf("%d element from end is %d\n",index,p->data);
}







// code to display of circular doubly linked list
void DisplayCircularDoubly(struct Node *p)
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
        if(p!=first)
            printf("<-> "); // This condition is used to print -> at the end of linked list
    }while(p!=first);
    printf("\n");
}

// code for recursive display of circular doubly linked list
void RDisplayCircularDoubly(struct Node *p)
{
    static int flag=0;
    if(p!=first || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        if(p->next!=first)  // This condition is used to print -> at the end of linked list
            printf("<-> ");
        RDisplayCircularDoubly(p->next);
        
    }
    flag=0;
}

// code for length of circular doubly linked list  // not working properly
int LengthCircularDoubly(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=first);
    return len;
}


// code to insert element in circular doubly linked list   // not working properly
void InsertCircularDoubly(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index<0 || index > LengthCircularDoubly(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)  // Inserting at beginning
    {
        if(first==NULL)
        {
            first=t;
            first->next=first;
            first->prev=first;
        }
        else  
        {
            while(p->next!=first) 
                p=p->next;
            p->next=t;
            t->prev=p;
            t->next=first;
            first->prev=t;
            first=t;
        }
    }
    else  // Inserting at any other position
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
    }
}


// code to insert element without count in circular doubly linked list
void InsertCircularDoubly1(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index<0)
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)  // Inserting at beginning
    {
        if(first==NULL)
        {
            first=t;
            first->next=first;
            first->prev=first;
        }
        else  
        {
            while(p->next!=first) 
                p=p->next;
            p->next=t;
            t->prev=p;
            t->next=first;
            first->prev=t;
            first=t;
        }
    }
    else  // Inserting at any other position
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
    }
}


// code to delete element from circular doubly linked list
int DeleteCircularDoubly(struct Node *p,int index)
{
    struct Node *q=NULL;
    int i,x;

    if(index < 1) // Checking if index is valid or not
        return -1;
    if(index==1) // Deleting first node
    {
        while(p->next!=first)
            p=p->next;
        x=first->data;
        if(first->next==first)
        {
            free(first);
            first=NULL;
        }
        else
        {
            p->next=first->next;
            first->next->prev=p;
            free(first);
            first=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++) // Deleting any other node
            p=p->next;
        q=p->next;
        p->next=q->next;
        q->next->prev=p;
        x=q->data;
        free(q);
    }
    return x;
}


// inserted element at sorted position in circular doubly linked list or it create sorted circular doubly linked list if there is no sorted circular doubly linked list
void InsertsortCircularDoubly(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=t->prev=NULL;
    if(first==NULL)
    {
        first=t;
        first->next=first;
        first->prev=first;
    }
    else
    {
        while(p->next!=first && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p->data<x)
        {
            p->next=t;
            t->prev=p;
            t->next=first;
            first->prev=t;
        }
        else
        {
            t->next=p;
            t->prev=q;
            q->next=t;
            p->prev=t;
        }
    }
}


// // code to remove duplicate elements from sorted circular doubly linked list
void RemoveDuplicateCircularDoubly(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=first)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            q->next->prev=p;
            free(q);
            q=p->next;
        }
    }
}

// code to reverse circular doubly linked list
void ReverseCircularDoubly(struct Node *p)
{
    struct Node *temp;
    while(p!=first)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
    }
    p->next=p->prev;
    p->prev=NULL;
    first=p;
}


// code to reverse circular doubly linked list using recursion
void RReverseCircularDoubly(struct Node *p)
{    
    struct Node *temp;
    if(p!=first)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        RReverseCircularDoubly(p);
    }
    else
    {
        p->next=p->prev;
        p->prev=NULL;
        first=p;
    }
}


// code to concatenate two circular doubly linked list
void ConcatenateCircularDoubly(struct Node *p,struct Node *q)
{
    struct Node *temp;
    temp=p->next;
    p->next=q->next;
    q->next=temp;
    p->next->prev=p;
    q->next->prev=q;
}

// // code to merge two circular doubly linked list
void MergeCircularDoubly(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        first=last=p;
        p=p->next;
        first->next=first->prev=first;
    }
    else
    {
        first=last=q;
        q=q->next;
        first->next=first->prev=first;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            p->prev=last;
            last=p;
            p=p->next;
            last->next=first;
            first->prev=last;
        }
        else
        {
            last->next=q;
            q->prev=last;
            last=q;
            q=q->next;
            last->next=first;
            first->prev=last;
        }
    }
    if(p!=NULL)
    {
        last->next=p;
        p->prev=last;
        last=p;
        last->next=first;
        first->prev=last;
    }
    if(q!=NULL)
    {
        last->next=q;
        q->prev=last;
        last=q;
        last->next=first;
        first->prev=last;
    }
}

// code to merge two circular doubly linked list using recursion
void MergeCircularDoubly(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        first=last=p;
        p=p->next;
        first->next=first->prev=first;
    }
    else
    {
        first=last=q;
        q=q->next;
        first->next=first->prev=first;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            p->prev=last;
            last=p;
            p=p->next;
            last->next=first;
            first->prev=last;
        }
        else
        {
            last->next=q;
            q->prev=last;
            last=q;
            q=q->next;
            last->next=first;
            first->prev=last;
        }
    }
    if(p!=NULL)
    {
        last->next=p;
        p->prev=last;
        last=p;
        last->next=first;
        first->prev=last;
    }
    if(q!=NULL)
    {
        last->next=q;
        q->prev=last;
        last=q;
        last->next=first;
        first->prev=last;
    }
}

// code to check if circular doubly linked list is loop or not
void LoopCircularDoubly(struct Node *p)
{
    struct Node *q=p;
    while(p!=NULL)
    {
        p=p->next;
        if(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        if(p==q)
        {
            printf("Loop is present\n");
            break;
        }
    }
    if(p==NULL)
        printf("Loop is not present\n");
}

// code to find middle element of circular doubly linked list
void MiddleElementCircularDoubly(struct Node *p)
{
    struct Node *q=p;
    while(p!=NULL)
    {
        p=p->next;
        if(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        if(p==first)
            break;
    }
    printf("Middle element is %d\n",q->data);
}

// code to find nth element from end of circular doubly linked list
void NthElementCircularDoubly(struct Node *p,int index)
{
    struct Node *q=p;
    int i;
    for(i=0;i<index-1;i++)
        p=p->next;
    while(p->next!=first)
    {
        p=p->next;
        q=q->next;
    }
    printf("%d element from end is %d\n",index,q->data);
}

// student challenge: code to find middle element of linked list
void MiddleElement(struct Node *p)
{
    struct Node *q=p;
    while(p!=NULL)
    {
        p=p->next;
        if(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
    }
    printf("Middle element is %d\n",q->data);
}

// student challenge: code to find intersection point of two linked list
void IntersectionPoint(struct Node *p,struct Node *q)
{
    int l1=length(p);
    int l2=length(q);
    int d=abs(l1-l2);
    if(l1>l2)
    {
        for(int i=0;i<d;i++)
            p=p->next;
    }
    else
    {
        for(int i=0;i<d;i++)
            q=q->next;
    }
    while(p!=q)
    {
        p=p->next;
        q=q->next;
    }
    printf("Intersection point is %d\n",p->data);
}


int main()
{
    int A[]={10,15,24,35,64};
    create(A,5);

    
  
   
    
    // temp=MoveNode(first,7);
    // if(temp)
    //     printf("key is found %d\n",temp->data);
    // else
    //     printf("key is not found\n");
    return 0;
}