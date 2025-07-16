#include<stdio.h>
#include<stdlib.h>

// struct stack
// {
//     int size; // size is used to store the size of stack
//     int top; // top is used to point the top element of stack
//     int *S; // S is used to store the elements of stack
// };

// void create(struct stack *st)
// {
//     printf("Enter size of stack: ");
//     scanf("%d",&st->size);
//     st->top=-1;
//     st->S=(int *)malloc(st->size*sizeof(int));
// }

// void Display(struct stack st)
// {
//     int i;
//     for(i=st.top;i>=0;i--)
//         printf("%d ",st.S[i]);
//     printf("\n");
// }

// // push element in stack
// void push(struct stack *st,int x)
// {
//     if(st->top==st->size-1)
//         printf("Stack overflow\n");
//     else
//     {
//         st->top++;
//         st->S[st->top]=x;
//     }
// }

// // pop element from stack
// int pop(struct stack *st)
// {
//     int x=-1;
//     if(st->top==-1)
//         printf("Stack underflow\n");
//     else
//     {
//         x=st->S[st->top--];
//     }
//     return x;
// }

// // peek element from stack
// int peek(struct stack st,int index)
// {
//     int x=-1;
//     if(st.top-index+1<0)
//         printf("Invalid index\n");
//     x=st.S[st.top-index+1];
//     return x;
// }

// // check if stack is empty
// int isEmpty(struct stack st)
// {
//     if(st.top==-1)
//         return 1;
//     return 0;
// }

// // check if stack is full
// int isFull(struct stack st)
// {
//     return st.top==st.size-1;
// }

// // stack top element
// int stackTop(struct stack st)
// {
//     if(!isEmpty(st))
//         return st.S[st.top];
//     return -1;
// }

// int main()
// {
//     struct stack st;
//     create(&st);
//     push(&st,10);
//     push(&st,20);
//     push(&st,30);
//     push(&st,40);
   
//     printf("Peeked element is %d\n",peek(st,2));
    
//     Display(st);

//     return 0;
// }



//Stack using linked list

struct Node // Node structure
{
    int data;
    struct Node *next;
}*top=NULL;

// Display stack
void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

// push element in stack
void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));  // if memory is allocated then it is not full else it is full 
    if(t==NULL)  
        printf("Stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

// pop element from stack
int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

// peek element from stack
int peek(int pos)
{
    struct Node *p=top;
    for(int i=0;p!=NULL && i<pos-1;i++)
        p=p->next;
    if(p!=NULL)
        return p->data;
    else
        return -1;
}

// stack top element
int stackTop()
{
    if(top!=NULL)
        return top->data;
    return -1;
}

// check if stack is empty
int isEmpty()
{
    return top==NULL;
}

// check if stack is full
int isFull()
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    int r=t?0:1;
    free(t);
    return r;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    Display();
    printf("Popped element is %d\n",pop());
    printf("Peeked element is %d\n",peek(2));
    printf("Stack top element is %d\n",stackTop());
    printf("Is stack empty: %d\n",isEmpty());
    printf("Is stack full: %d\n",isFull());
    return 0;
}

// // Output
// // 50 40 30 20 10
// // Popped element is 50
// // Peeked element is 40
// // Stack top element is 40
// // Is stack empty: 0
// // Is stack full: 0








// // Paranthesis matching using stack
// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     char data;
//     struct Node *next;
// }*top=NULL;

// // Display stack
// void Display()
// {
//     struct Node *p;
//     p=top;
//     while(p!=NULL)
//     {
//         printf("%c ",p->data);
//         p=p->next;
//     }
//     printf("\n");
// }

// // push element in stack

// void push(char x)
// {
//     struct Node *t;
//     t=(struct Node *)malloc(sizeof(struct Node));
//     if(t==NULL)
//         printf("Stack is full\n");
//     else
//     {
//         t->data=x;
//         t->next=top;
//         top=t;
//     }
// }

// // pop element from stack
// char pop()
// {
//     struct Node *t;
//     char x=-1;
//     if(top==NULL)
//         printf("Stack is Empty\n");
//     else
//     {
//         t=top;
//         top=top->next;
//         x=t->data;
//         free(t);
//     }
//     return x;
// }

// // check if stack is empty
// int isEmpty()
// {
//     return top==NULL;
// }

// // check if character is opening paranthesis
// int isOpeningParanthesis(char x)
// {
//     if(x=='(' || x=='{' || x=='[')
//         return 1;
//     return 0;
// }

// // check if character is closing paranthesis
// int isClosingParanthesis(char x)
// {
//     if(x==')' || x=='}' || x==']')
//         return 1;
//     return 0;
// }

// // check if character is matching paranthesis
// int isMatching(char x,char y)
// {
//     if(x=='(' && y==')')
//         return 1;
//     if(x=='{' && y=='}')
//         return 1;
//     if(x=='[' && y==']')
//         return 1;
//     return 0;
// }

// // check if paranthesis are balanced
// int isBalanced(char *exp)
// {
//     for(int i=0;exp[i]!='\0';i++)
//     {
//         if(isOpeningParanthesis(exp[i]))
//             push(exp[i]);
//         else if(isClosingParanthesis(exp[i]))
//         {
//             if(isEmpty())
//                 return 0;
//             if(!isMatching(top->data,exp[i]))
//                 return 0;
//             pop();
//         }
//     }
//     return isEmpty()?1:0;
// }

// // isBalanced for paranthesis matching having paranthesis , square brackets and curly brackets
// int isBalanced(char *exp)
// {
//     for(int i=0;exp[i]!='\0';i++)
//     {
//         if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
//             push(exp[i]);
//         else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
//         {
//             if(isEmpty())
//                 return 0;
//             if(exp[i]==')')
//             {
//                 if(top->data!='(')
//                     return 0;
//             }
//             else if(exp[i]=='}')
//             {
//                 if(top->data!='{')
//                     return 0;
//             }
//             else if(exp[i]==']')
//             {
//                 if(top->data!='[')
//                     return 0;
//             }
//             pop();
//         }
//     }
//     return isEmpty()?1:0;
// }

// // another code of isBalanced
// int isBalanced(char *exp)
// {
//     for (int i = 0; exp[i] != '\0'; i++)
//     {
//         if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
//             push(exp[i]);
//         else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
//         {
//             if (isEmpty())
//                 return 0;
//             char topChar = top->data;
//             if ((exp[i] == ')' && topChar != '(') ||
//                 (exp[i] == '}' && topChar != '{') ||
//                 (exp[i] == ']' && topChar != '['))
//                 return 0;
//             pop();
//         }
//     }
//     return isEmpty() ? 1 : 0;
// }


// // isBalanced code using ascii code for paranthesis '(' is 40 and ')' is 41,'{' is 123 and '}' is 125,'[' is 91 and ']' is 93
// int isBalanced(char *exp)
// {
//     for(int i=0;exp[i]!='\0';i++)
//     {
//         if(exp[i]==40 || exp[i]==123 || exp[i]==91)
//             push(exp[i]);
//         else if(exp[i]==41 || exp[i]==125 || exp[i]==93)
//         {
//             if(isEmpty())
//                 return 0;
//             if(exp[i]==41)
//             {
//                 if(top->data!=40)
//                     return 0;
//             }
//             else if(exp[i]==125)
//             {
//                 if(top->data!=123)
//                     return 0;
//             }
//             else if(exp[i]==93)
//             {
//                 if(top->data!=91)
//                     return 0;
//             }
//             pop();
//         }
//     }
//     return isEmpty()?1:0;
// }


// // int main()
// int main()
// {
//     char *exp="{(a+b)*(c-d)}";
//     printf("%d\n",isBalanced(exp));
//     return 0;
// }


// // code for converting infix expression to postfix expression
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct Node
// {
//     char data;
//     struct Node *next;
// } *top = NULL;

// // Display stack
// void Display()
// {
//     struct Node *p;
//     p = top;
//     while (p != NULL)
//     {
//         printf("%c ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }

// // push element in stack
// void push(char x)
// {
//     struct Node *t;
//     t = (struct Node *)malloc(sizeof(struct Node));
//     if (t == NULL)
//         printf("Stack is full\n");
//     else
//     {
//         t->data = x;
//         t->next = top;
//         top = t;
//     }
// }

// // pop element from stack

// char pop()
// {
//     struct Node *t;
//     char x = -1;
//     if (top == NULL)
//         printf("Stack is Empty\n");
//     else
//     {
//         t = top;
//         top = top->next;
//         x = t->data;
//         free(t);
//     }
//     return x;
// }

// // check if stack is empty

// int isEmpty()
// {
//     return top == NULL;
// }

// // check if character is operand

// int isOperand(char x)
// {
//     if (x == '+' || x == '-' || x == '*' || x == '/')
//         return 0;
//     return 1;
// }

// // precedence of operator

// int pre(char x)
// {
//     if (x == '+' || x == '-')
//         return 1;
//     if (x == '*' || x == '/')
//         return 2;
//     return 0;
// }

// // convert infix expression to postfix expression

// char *InToPost(char *infix)
// {
//     int i = 0, j = 0;
//     char *postfix;
//     int len = strlen(infix);
//     postfix = (char *)malloc((len + 2) * sizeof(char));
//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//             postfix[j++] = infix[i++];
//         else
//         {
//             if (pre(infix[i]) > pre(top->data))
//                 push(infix[i++]);
//             else
//             {
//                 postfix[j++] = pop();
//             }
//         }
//     }
//     while (!isEmpty())
//         postfix[j++] = pop();
//     postfix[j] = '\0';
//     return postfix;
// }

// int main()
// {
//     char *infix = "a+b*c-d/e";
//     push('#');
//     char *postfix = InToPost(infix);
//     printf("%s\n", postfix);
//     return 0;
// }



// // evaluation of postfix expression
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// } *top = NULL;

// // Display stack
// void Display()
// {
//     struct Node *p;
//     p = top;
//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }

// // push element in stack
// void push(int x)
// {
//     struct Node *t;
//     t = (struct Node *)malloc(sizeof(struct Node));
//     if (t == NULL)
//         printf("Stack is full\n");
//     else
//     {
//         t->data = x;
//         t->next = top;
//         top = t;
//     }
// }

// // pop element from stack

// int pop()
// {
//     struct Node *t;
//     int x = -1;
//     if (top == NULL)
//         printf("Stack is Empty\n");
//     else
//     {
//         t = top;
//         top = top->next;
//         x = t->data;
//         free(t);
//     }
//     return x;
// }

// // check if stack is empty

// int isEmpty()
// {
//     return top == NULL;
// }

// // check if character is operand

// int isOperand(char x)
// {
//     if (x == '+' || x == '-' || x == '*' || x == '/')
//         return 0;
//     return 1;
// }

// // precedence of operator

// int pre(char x)
// {
//     if (x == '+' || x == '-')
//         return 1;
//     if (x == '*' || x == '/')
//         return 2;
//     return 0;
// }

// // convert infix expression to postfix expression

// char *InToPost(char *infix)
// {
//     int i = 0, j = 0;
//     char *postfix;
//     int len = strlen(infix);
//     postfix = (char *)malloc((len + 2) * sizeof(char));
//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//             postfix[j++] = infix[i++];
//         else
//         {
//             if (pre(infix[i]) > pre(top->data))
//                 push(infix[i++]);
//             else
//             {
//                 postfix[j++] = pop();
//             }
//         }
//     }
//     while (!isEmpty())
//         postfix[j++] = pop();
//     postfix[j] = '\0';
//     return postfix;
// }

// // evaluate postfix expression

// int Eval(char *postfix)
// {
//     int i = 0;
//     int x1, x2, r = 0;
//     for (i = 0; postfix[i] != '\0'; i++)
//     {
//         if (isOperand(postfix[i]))
//             push(postfix[i] - '0');
//         else
//         {
//             x2 = pop();
//             x1 = pop();
//             switch (postfix[i])
//             {
//             case '+':
//                 r = x1 + x2;
//                 break;
//             case '-':
//                 r = x1 - x2;
//                 break;
//             case '*':
//                 r = x1 * x2;
//                 break;
//             case '/':
//                 r = x1 / x2;
//                 break;
//             }
//             push(r);
//         }
//     }
//     return top->data;
// }

int main()
{
   
    return 0;
}

