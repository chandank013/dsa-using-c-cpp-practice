// Title: Iterative Traversal of a Binary Tree using Stack
// Description: Iterative Traversal of a Binary Tree using Stack

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct node {
    struct node* left;
    struct node* right;
    char data;
} node;

// Define the structure for a stack
typedef struct stack {
    int top;
    int size;
    node** array;
} stack;

// Function to create a stack
void createStack(stack* st, int size) {
    st->top = -1;
    st->size = size;
    st->array = (node**)malloc(size * sizeof(node*));
}

// Function to check if the stack is empty
int isEmpty(stack* st) {
    return st->top == -1;
}

// Function to push an element onto the stack
void push(stack* st, node* tree) {
    if (st->top == st->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    st->array[++st->top] = tree;
}

// Function to pop an element from the stack
node* pop(stack* st) {
    if (isEmpty(st)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return st->array[st->top--];
}

// Function to insert nodes into the binary tree
node* insert(char c[], int n) {
    node* tree = NULL;
    if (n < 20 && c[n] != '\0') {
        tree = (node*)malloc(sizeof(node));
        tree->data = c[n];
        tree->left = insert(c, 2 * n + 1);
        tree->right = insert(c, 2 * n + 2);
    }
    return tree;
}

// Iterative inorder traversal
void inorder(node* tree) {
    stack st;
    createStack(&st, 100);

    while (tree != NULL || !isEmpty(&st)) {
        while (tree != NULL) {
            push(&st, tree);
            tree = tree->left;
        }
        tree = pop(&st);
        printf("%c ", tree->data);
        tree = tree->right;
    }
}

// Iterative preorder traversal
void preorder(node* tree) {
    if (tree == NULL) return;

    stack st;
    createStack(&st, 100);
    push(&st, tree);

    while (!isEmpty(&st)) {
        tree = pop(&st);
        printf("%c ", tree->data);

        // Push right child first so that left child is processed first
        if (tree->right) {
            push(&st, tree->right);
        }
        if (tree->left) {
            push(&st, tree->left);
        }
    }
}

// Iterative postorder traversal
void postorder(node* tree) {
    if (tree == NULL) return;

    stack st1, st2;
    createStack(&st1, 100);
    createStack(&st2, 100);

    push(&st1, tree);

    while (!isEmpty(&st1)) {
        tree = pop(&st1);
        push(&st2, tree);

        if (tree->left) {
            push(&st1, tree->left);
        }
        if (tree->right) {
            push(&st1, tree->right);
        }
    }

    // Print nodes from the second stack
    while (!isEmpty(&st2)) {
        tree = pop(&st2);
        printf("%c ", tree->data);
    }
}


// Main function
int main() {
    node* tree = NULL;
    char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    tree = insert(c, 0);

    printf("Inorder Traversal: ");
    inorder(tree);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(tree);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(tree);
    printf("\n");

    return 0;
}


// Title: Iterative Traversal of a Binary Tree using Stack and Queue
// Description: Iterative Traversal of a Binary Tree using Stack and Queue

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

// Define the structure for a stack
struct Stack {
    int top;
    int size;
    struct Node** array;
};

// Define the structure for a queue
struct Queue {
    int front, rear, size;
    struct Node** array;
};

// Function to create a stack
void createStack(struct Stack* st, int size) {
    st->top = -1;
    st->size = size;
    st->array = (struct Node**)malloc(size * sizeof(struct Node*));
}

// Function to check if the stack is empty
int isEmptyStack(struct Stack st) {
    return st.top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* st, struct Node* node) {
    if (st->top == st->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    st->array[++st->top] = node;
}

// Function to pop an element from the stack
struct Node* pop(struct Stack* st) {
    if (isEmptyStack(*st)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return st->array[st->top--];
}

// Function to create a queue
void createQueue(struct Queue* q, int size) {
    q->front = q->rear = -1;
    q->size = size;
    q->array = (struct Node**)malloc(size * sizeof(struct Node*));
}

// Function to check if the queue is empty
int isEmptyQueue(struct Queue q) {
    return q.front == q.rear;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->array[++q->rear] = node;
}

// Function to dequeue an element from the queue
struct Node* dequeue(struct Queue* q) {
    if (isEmptyQueue(*q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->array[++q->front];
}

// Global root node
struct Node* root = NULL;

// Function to create a binary tree
void Treecreate() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node*)malloc(sizeof(struct Node));
    if (!root) {
        printf("Memory allocation failed for root node.\n");
        return;
    }
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmptyQueue(q)) {
        p = dequeue(&q);

        // Input and create the left child
        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            if (!t) {
                printf("Memory allocation failed for left child.\n");
                return;
            }
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        // Input and create the right child
        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            if (!t) {
                printf("Memory allocation failed for right child.\n");
                return;
            }
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// Function for iterative preorder traversal
void IPreorder(struct Node* p) {
    struct Stack stk;
    createStack(&stk, 100);

    while (p || !isEmptyStack(stk)) {
        if (p) {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

// Function for recursive preorder traversal
void Preorder(struct Node* p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// Function for iterative inorder traversal
void IInorder(struct Node* p) {
    struct Stack stk;
    createStack(&stk, 100);

    while (p || !isEmptyStack(stk)) {
        if (p) {
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

// Function for recursive inorder traversal
void Inorder(struct Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Function for iterative postorder traversal
void IPostorder(struct Node* p) {
    struct Stack stk;
    createStack(&stk, 100);
    long int temp;

    while (p || !isEmptyStack(stk)) {
        if (p) {
            push(&stk, p);
            p = p->lchild;
        } else {
            temp = (long int)pop(&stk);
            if (temp > 0) {
                push(&stk, (struct Node*)-temp);
                p = ((struct Node*)temp)->rchild;
            } else {
                printf("%d ", ((struct Node*)-temp)->data);
                p = NULL;
            }
        }
    }
}

// Function for recursive postorder traversal
void Postorder(struct Node* p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Function for level order traversal
void LebalOrder(struct Node* root) {
    struct Queue q;
    createQueue(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmptyQueue(q)) {
        root = dequeue(&q);
        if (root->lchild) {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild) {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int main() {
    Treecreate();

    printf("Iterative Preorder Traversal: ");
    IPreorder(root);
    printf("\n");

    printf("Recursive Preorder Traversal: ");
    Preorder(root);
    printf("\n");

    printf("Iterative Inorder Traversal: ");
    IInorder(root);
    printf("\n");

    printf("Recursive Inorder Traversal: ");
    Inorder(root);
    printf("\n");

    printf("Iterative Postorder Traversal: ");
    IPostorder(root);
    printf("\n");

    printf("Recursive Postorder Traversal: ");
    Postorder(root);
    printf("\n");

    printf("Level Order Traversal: ");
    LebalOrder(root);
    printf("\n");

    return 0;
}