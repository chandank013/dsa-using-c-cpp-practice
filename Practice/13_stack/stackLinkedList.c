// #include <stdio.h>
// #include <stdlib.h>

// // Node structure
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// // Top pointer
// struct Node *top = NULL;

// // Display stack
// void Display()
// {
//     struct Node *p = top;

//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }

//     printf("\n");
// }

// // Push element onto stack
// void push(int x)
// {
//     struct Node *t = malloc(sizeof(struct Node));

//     if (t == NULL)
//     {
//         printf("Stack is full (memory unavailable)\n");
//         return;
//     }

//     t->data = x;
//     t->next = top;
//     top = t;
// }

// // Pop element from stack
// int pop()
// {
//     if (top == NULL)
//     {
//         printf("Stack is empty\n");
//         return -1;
//     }

//     struct Node *t = top;
//     int x = t->data;

//     top = top->next;
//     free(t);

//     return x;
// }

// // Peek at a 1-based position from the top
// int peek(int pos)
// {
//     if (pos < 1)
//     {
//         printf("Invalid position\n");
//         return -1;
//     }

//     struct Node *p = top;

//     for (int i = 1; p != NULL && i < pos; i++)
//     {
//         p = p->next;
//     }

//     if (p == NULL)
//     {
//         printf("Invalid position\n");
//         return -1;
//     }

//     return p->data;
// }

// // Get top element
// int stackTop()
// {
//     if (top != NULL)
//         return top->data;

//     return -1;
// }

// // Check if stack is empty
// int isEmpty()
// {
//     return top == NULL;
// }

// // Check whether memory is currently available
// int isFull()
// {
//     struct Node *t = malloc(sizeof(struct Node));

//     if (t == NULL)
//         return 1;

//     free(t);
//     return 0;
// }

// // Free all remaining nodes
// void clearStack()
// {
//     struct Node *p;

//     while (top != NULL)
//     {
//         p = top;
//         top = top->next;
//         free(p);
//     }
// }

// // Main function
// int main()
// {
//     push(10);
//     push(20);
//     push(30);
//     push(40);
//     push(50);

//     printf("Stack elements: ");
//     Display();

//     printf("Popped element: %d\n", pop());

//     printf("Stack after popping: ");
//     Display();

//     printf("Peeked element at position 2: %d\n", peek(2));

//     printf("Top element: %d\n", stackTop());

//     printf("Is stack empty? %s\n",
//            isEmpty() ? "Yes" : "No");

//     printf("Is stack full? %s\n",
//            isFull() ? "Yes" : "No");

//     printf("Element at position 6: %d\n", peek(6));

//     // Pop all remaining elements
//     while (!isEmpty())
//     {
//         printf("Popped element: %d\n", pop());
//     }

//     printf("Is stack empty after popping all elements? %s\n",
//            isEmpty() ? "Yes" : "No");

//     // Release any remaining allocated memory
//     clearStack();

//     return 0;
// }


// // Paranthesis matching using stack (linked list implementation)


// #include <stdio.h>
// #include <stdlib.h>

// // Node structure
// struct Node
// {
//     char data;
//     struct Node *next;
// };

// // Top pointer
// struct Node *top = NULL;

// // Push character onto stack
// int push(char x)
// {
//     struct Node *t = malloc(sizeof(struct Node));

//     if (t == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return 0;
//     }

//     t->data = x;
//     t->next = top;
//     top = t;

//     return 1;
// }

// // Pop character from stack
// char pop()
// {
//     if (top == NULL)
//         return '\0';

//     struct Node *t = top;
//     char x = t->data;

//     top = top->next;
//     free(t);

//     return x;
// }

// // Check if stack is empty
// int isEmpty()
// {
//     return top == NULL;
// }

// // Check opening parentheses
// int isOpeningParenthesis(char x)
// {
//     return x == '(' || x == '{' || x == '[';
// }

// // Check closing parentheses
// int isClosingParenthesis(char x)
// {
//     return x == ')' || x == '}' || x == ']';
// }

// // Check whether opening and closing parentheses match
// int isMatching(char open, char close)
// {
//     return (open == '(' && close == ')') ||
//            (open == '{' && close == '}') ||
//            (open == '[' && close == ']');
// }

// // Check whether parentheses are balanced
// int isBalanced(const char *exp)
// {
//     // Start with an empty stack for every expression
//     while (top != NULL)
//         pop();

//     for (int i = 0; exp[i] != '\0'; i++)
//     {
//         if (isOpeningParenthesis(exp[i]))
//         {
//             if (!push(exp[i]))
//             {
//                 while (!isEmpty())
//                     pop();

//                 return -1;  // Memory allocation failure
//             }
//         }
//         else if (isClosingParenthesis(exp[i]))
//         {
//             if (isEmpty())
//                 return 0;

//             char open = pop();

//             if (!isMatching(open, exp[i]))
//             {
//                 while (!isEmpty())
//                     pop();

//                 return 0;
//             }
//         }
//     }

//     int balanced = isEmpty();

//     // Release any remaining nodes
//     while (!isEmpty())
//         pop();

//     return balanced;
// }

// // Main function
// int main()
// {
//     const char *exp1 = "{(a+b)*(c-d)}";
//     const char *exp2 = "{[(a+b)]}";
//     const char *exp3 = "{(a+b]*c}";
//     const char *exp4 = "((a+b)";

//     int result;

//     result = isBalanced(exp1);
//     if (result == -1)
//         printf("Memory allocation failed\n");
//     else
//         printf("%s: %s\n", exp1,
//                result ? "Balanced" : "Not Balanced");

//     result = isBalanced(exp2);
//     if (result == -1)
//         printf("Memory allocation failed\n");
//     else
//         printf("%s: %s\n", exp2,
//                result ? "Balanced" : "Not Balanced");

//     result = isBalanced(exp3);
//     if (result == -1)
//         printf("Memory allocation failed\n");
//     else
//         printf("%s: %s\n", exp3,
//                result ? "Balanced" : "Not Balanced");

//     result = isBalanced(exp4);
//     if (result == -1)
//         printf("Memory allocation failed\n");
//     else
//         printf("%s: %s\n", exp4,
//                result ? "Balanced" : "Not Balanced");

//     return 0;
// }



// // infix to postfix conversion and evaluation using stack (linked list implementation)


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Node structure
// struct Node
// {
//     char data;
//     struct Node *next;
// };

// struct Node *top = NULL;

// // Push character onto stack
// int push(char x)
// {
//     struct Node *t = malloc(sizeof(struct Node));

//     if (t == NULL)
//         return 0;

//     t->data = x;
//     t->next = top;
//     top = t;

//     return 1;
// }

// // Pop character from stack
// char pop()
// {
//     if (top == NULL)
//         return '\0';

//     struct Node *t = top;
//     char x = t->data;

//     top = top->next;
//     free(t);

//     return x;
// }

// // Check if stack is empty
// int isEmpty()
// {
//     return top == NULL;
// }

// // Check if character is an operand
// int isOperand(char x)
// {
//     return (x >= 'a' && x <= 'z') ||
//            (x >= 'A' && x <= 'Z') ||
//            (x >= '0' && x <= '9');
// }

// // Operator precedence
// int pre(char x)
// {
//     if (x == '+' || x == '-')
//         return 1;

//     if (x == '*' || x == '/')
//         return 2;

//     if (x == '^')
//         return 3;

//     return 0;
// }

// // Clear stack
// void clearStack()
// {
//     while (!isEmpty())
//         pop();
// }

// // Convert infix to postfix
// char *InToPost(const char *infix)
// {
//     int i = 0, j = 0;
//     int len = strlen(infix);

//     char *postfix = malloc((len + 1) * sizeof(char));

//     if (postfix == NULL)
//         return NULL;

//     clearStack();

//     while (infix[i] != '\0')
//     {
//         char x = infix[i];

//         // Ignore spaces
//         if (x == ' ' || x == '\t')
//         {
//             i++;
//         }
//         // Operand goes directly to output
//         else if (isOperand(x))
//         {
//             postfix[j++] = x;
//             i++;
//         }
//         // Opening parenthesis
//         else if (x == '(')
//         {
//             if (!push(x))
//                 goto error;

//             i++;
//         }
//         // Closing parenthesis
//         else if (x == ')')
//         {
//             while (!isEmpty() && top->data != '(')
//                 postfix[j++] = pop();

//             if (isEmpty())
//                 goto error;

//             pop();  // Remove '('
//             i++;
//         }
//         // Operators
//         else if (pre(x) > 0)
//         {
//             while (!isEmpty() &&
//                    top->data != '(' &&
//                    (pre(top->data) > pre(x) ||
//                     (pre(top->data) == pre(x) && x != '^')))
//             {
//                 postfix[j++] = pop();
//             }

//             if (!push(x))
//                 goto error;

//             i++;
//         }
//         else
//         {
//             // Unsupported character
//             goto error;
//         }
//     }

//     // Pop remaining operators
//     while (!isEmpty())
//     {
//         if (top->data == '(')
//             goto error;

//         postfix[j++] = pop();
//     }

//     postfix[j] = '\0';
//     return postfix;

// error:
//     clearStack();
//     free(postfix);
//     return NULL;
// }

// // Main function
// int main()
// {
//     const char *infix = "a+b*c-d/e";

//     char *postfix = InToPost(infix);

//     if (postfix == NULL)
//     {
//         printf("Invalid expression or memory allocation failure\n");
//         return 1;
//     }

//     printf("Infix:   %s\n", infix);
//     printf("Postfix: %s\n", postfix);

//     free(postfix);
//     clearStack();

//     return 0;
// }


// Evaluate postfix expression


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push element onto stack
int push(int x)
{
    struct Node *t = malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    t->data = x;
    t->next = top;
    top = t;

    return 1;
}

// Pop element from stack
int pop(int *value)
{
    if (top == NULL)
        return 0;

    struct Node *t = top;
    *value = t->data;

    top = top->next;
    free(t);

    return 1;
}

// Check if stack is empty
int isEmpty()
{
    return top == NULL;
}

// Clear stack memory
void clearStack()
{
    int x;

    while (pop(&x))
    {
        // Remove remaining nodes
    }
}

// Check if character is an operator
int isOperator(char x)
{
    return x == '+' || x == '-' ||
           x == '*' || x == '/';
}

// Evaluate postfix expression
// Supports single-digit operands
int Eval(const char *postfix, int *result)
{
    clearStack();

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // Ignore spaces
        if (isspace((unsigned char)ch))
            continue;

        // Operand: push its numeric value
        if (isdigit((unsigned char)ch))
        {
            if (!push(ch - '0'))
            {
                clearStack();
                return 0;
            }
        }
        // Operator: pop two operands
        else if (isOperator(ch))
        {
            int x1, x2, r;

            if (!pop(&x2) || !pop(&x1))
            {
                clearStack();
                return 0;
            }

            switch (ch)
            {
                case '+':
                    r = x1 + x2;
                    break;

                case '-':
                    r = x1 - x2;
                    break;

                case '*':
                    r = x1 * x2;
                    break;

                case '/':
                    if (x2 == 0)
                    {
                        clearStack();
                        return 0;
                    }
                    r = x1 / x2;
                    break;

                default:
                    clearStack();
                    return 0;
            }

            if (!push(r))
            {
                clearStack();
                return 0;
            }
        }
        else
        {
            clearStack();
            return 0;
        }
    }

    // A valid expression must leave exactly one result
    if (!pop(result) || !isEmpty())
    {
        clearStack();
        return 0;
    }

    return 1;
}

// Main function
int main()
{
    const char *postfix = "23*54*+9-";
    int result;

    printf("Postfix expression: %s\n", postfix);

    if (Eval(postfix, &result))
        printf("Result: %d\n", result);
    else
        printf("Invalid postfix expression or division by zero\n");

    clearStack();

    return 0;
}

