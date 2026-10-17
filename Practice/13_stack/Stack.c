// #include <stdio.h>
// #include <stdlib.h>

// struct stack
// {
//     int size;
//     int top;
//     int *S;
// };

// // Create stack
// int create(struct stack *st)
// {
//     printf("Enter size of stack: ");
//     if (scanf("%d", &st->size) != 1 || st->size <= 0)
//     {
//         printf("Invalid stack size\n");
//         return 0;
//     }

//     st->top = -1;
//     st->S = malloc(st->size * sizeof(int));

//     if (st->S == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return 0;
//     }

//     return 1;
// }

// // Display stack
// void Display(struct stack st)
// {
//     for (int i = st.top; i >= 0; i--)
//         printf("%d ", st.S[i]);

//     printf("\n");
// }

// // Push element
// void push(struct stack *st, int x)
// {
//     if (st->top == st->size - 1)
//         printf("Stack overflow\n");
//     else
//         st->S[++st->top] = x;
// }

// // Pop element
// int pop(struct stack *st)
// {
//     if (st->top == -1)
//     {
//         printf("Stack underflow\n");
//         return -1;
//     }

//     return st->S[st->top--];
// }

// // Peek at a 1-based position from the top
// int peek(struct stack st, int index)
// {
//     if (index < 1 || index > st.top + 1)
//     {
//         printf("Invalid index\n");
//         return -1;
//     }

//     return st.S[st.top - index + 1];
// }

// // Check if empty
// int isEmpty(struct stack st)
// {
//     return st.top == -1;
// }

// // Check if full
// int isFull(struct stack st)
// {
//     return st.top == st.size - 1;
// }

// // Get top element
// int stackTop(struct stack st)
// {
//     if (!isEmpty(st))
//         return st.S[st.top];

//     return -1;
// }

// int main()
// {
//     struct stack st;

//     if (!create(&st))
//         return 1;

//     push(&st, 10);
//     push(&st, 20);
//     push(&st, 30);
//     push(&st, 40);

//     printf("Stack elements: ");
//     Display(st);

//     printf("Peeked element: %d\n", peek(st, 2));
//     printf("Top element: %d\n", stackTop(st));
//     printf("Popped element: %d\n", pop(&st));

//     printf("Is stack empty? %s\n",
//            isEmpty(st) ? "Yes" : "No");

//     printf("Is stack full? %s\n",
//            isFull(st) ? "Yes" : "No");

//     free(st.S);
//     return 0;
// }







// Parenthesis matching using stack (array implementation)

// #include <stdio.h>
// #include <stdlib.h>

// // Stack structure
// struct Stack
// {
//     int size;
//     int top;
//     char *S;
// };

// // Create stack
// int create(struct Stack *st, int size)
// {
//     if (size <= 0)
//         return 0;

//     st->size = size;
//     st->top = -1;
//     st->S = malloc(size * sizeof(char));

//     return st->S != NULL;
// }

// // Push character onto stack
// int push(struct Stack *st, char x)
// {
//     if (st->top == st->size - 1)
//         return 0;

//     st->S[++st->top] = x;
//     return 1;
// }

// // Pop character from stack
// char pop(struct Stack *st)
// {
//     if (st->top == -1)
//         return '\0';

//     return st->S[st->top--];
// }

// // Check if stack is empty
// int isEmpty(struct Stack *st)
// {
//     return st->top == -1;
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

// // Check matching pair
// int isMatching(char open, char close)
// {
//     return (open == '(' && close == ')') ||
//            (open == '{' && close == '}') ||
//            (open == '[' && close == ']');
// }

// // Check whether expression is balanced
// int isBalanced(const char *exp)
// {
//     struct Stack st;

//     if (!create(&st, 1000))
//     {
//         printf("Stack memory allocation failed\n");
//         return -1;
//     }

//     for (int i = 0; exp[i] != '\0'; i++)
//     {
//         if (isOpeningParenthesis(exp[i]))
//         {
//             if (!push(&st, exp[i]))
//             {
//                 free(st.S);
//                 return -1;
//             }
//         }
//         else if (isClosingParenthesis(exp[i]))
//         {
//             if (isEmpty(&st))
//             {
//                 free(st.S);
//                 return 0;
//             }

//             char open = pop(&st);

//             if (!isMatching(open, exp[i]))
//             {
//                 free(st.S);
//                 return 0;
//             }
//         }
//     }

//     int balanced = isEmpty(&st);

//     free(st.S);
//     return balanced;
// }

// // Main function
// int main()
// {
//     const char *exp1 = "{(a+b)*(c-d)}";
//     const char *exp2 = "{[(a+b)]}";
//     const char *exp3 = "{(a+b]*c}";
//     const char *exp4 = "((a+b)";

//     const char *expressions[] = {exp1, exp2, exp3, exp4};
//     int n = sizeof(expressions) / sizeof(expressions[0]);

//     for (int i = 0; i < n; i++)
//     {
//         int result = isBalanced(expressions[i]);

//         if (result == -1)
//             printf("%s: Stack error\n", expressions[i]);
//         else
//             printf("%s: %s\n", expressions[i],
//                    result ? "Balanced" : "Not Balanced");
//     }

//     return 0;
// }



// infix to postfix conversion and evaluation using stack (array implementation)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure
struct Stack
{
    int size;
    int top;
    char *S;
};

// Create stack
int create(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = malloc(size * sizeof(char));

    return st->S != NULL;
}

// Push character
int push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
        return 0;

    st->S[++st->top] = x;
    return 1;
}

// Pop character
char pop(struct Stack *st)
{
    if (st->top == -1)
        return '\0';

    return st->S[st->top--];
}

// Check if stack is empty
int isEmpty(struct Stack *st)
{
    return st->top == -1;
}

// Check if character is an operand
int isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z') ||
           (x >= '0' && x <= '9');
}

// Operator precedence
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    if (x == '^')
        return 3;

    return 0;
}

// Convert infix to postfix
char *InToPost(const char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);

    struct Stack st;

    if (!create(&st, len + 1))
        return NULL;

    char *postfix = malloc((len + 1) * sizeof(char));

    if (postfix == NULL)
    {
        free(st.S);
        return NULL;
    }

    while (infix[i] != '\0')
    {
        char x = infix[i];

        // Ignore spaces
        if (x == ' ' || x == '\t')
        {
            i++;
        }
        // Operand goes directly to output
        else if (isOperand(x))
        {
            postfix[j++] = x;
            i++;
        }
        // Opening parenthesis
        else if (x == '(')
        {
            if (!push(&st, x))
                goto error;

            i++;
        }
        // Closing parenthesis
        else if (x == ')')
        {
            while (!isEmpty(&st) && st.S[st.top] != '(')
                postfix[j++] = pop(&st);

            if (isEmpty(&st))
                goto error;

            pop(&st);  // Remove '('
            i++;
        }
        // Operators
        else if (pre(x) > 0)
        {
            while (!isEmpty(&st) &&
                   st.S[st.top] != '(' &&
                   (pre(st.S[st.top]) > pre(x) ||
                    (pre(st.S[st.top]) == pre(x) && x != '^')))
            {
                postfix[j++] = pop(&st);
            }

            if (!push(&st, x))
                goto error;

            i++;
        }
        else
        {
            goto error;
        }
    }

    // Pop remaining operators
    while (!isEmpty(&st))
    {
        if (st.S[st.top] == '(')
            goto error;

        postfix[j++] = pop(&st);
    }

    postfix[j] = '\0';

    free(st.S);
    return postfix;

error:
    free(st.S);
    free(postfix);
    return NULL;
}

// Main function
int main()
{
    const char *infix = "a+b*c-d/e";

    char *postfix = InToPost(infix);

    if (postfix == NULL)
    {
        printf("Invalid expression or memory allocation failure\n");
        return 1;
    }

    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    free(postfix);

    return 0;
}


// Evaluate postfix expression


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure
struct Stack
{
    int size;
    int top;
    int *S;
};

// Create stack
int create(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = malloc(size * sizeof(int));

    return st->S != NULL;
}

// Push element onto stack
int push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        return 0;

    st->S[++st->top] = x;
    return 1;
}

// Pop element from stack
int pop(struct Stack *st, int *value)
{
    if (st->top == -1)
        return 0;

    *value = st->S[st->top--];
    return 1;
}

// Check if stack is empty
int isEmpty(struct Stack *st)
{
    return st->top == -1;
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
    int len = strlen(postfix);
    struct Stack st;

    if (!create(&st, len + 1))
        return 0;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // Ignore spaces
        if (isspace((unsigned char)ch))
            continue;

        // Operand: push numeric value
        if (isdigit((unsigned char)ch))
        {
            if (!push(&st, ch - '0'))
            {
                free(st.S);
                return 0;
            }
        }
        // Operator: pop two operands
        else if (isOperator(ch))
        {
            int x1, x2, r;

            if (!pop(&st, &x2) || !pop(&st, &x1))
            {
                free(st.S);
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
                        free(st.S);
                        return 0;
                    }
                    r = x1 / x2;
                    break;

                default:
                    free(st.S);
                    return 0;
            }

            if (!push(&st, r))
            {
                free(st.S);
                return 0;
            }
        }
        else
        {
            free(st.S);
            return 0;
        }
    }

    // Exactly one value must remain
    if (st.top != 0)
    {
        free(st.S);
        return 0;
    }

    *result = st.S[st.top];

    free(st.S);
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
        printf("Invalid expression or division by zero\n");

    return 0;
}
