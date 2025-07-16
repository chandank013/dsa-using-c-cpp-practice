#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the structure for a stack node
typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

// Define the structure for the stack
typedef struct {
    StackNode* top;
} stack;

// Function to initialize the stack
void initStack(stack* stk) {
    stk->top = NULL;
}

// Function to push a tree node onto the stack
void push(stack* stk, Node* treeNode) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = stk->top;
    stk->top = newStackNode;
}

// Function to pop a tree node from the stack
Node* pop(stack* stk) {
    if (stk->top == NULL) {
        return NULL;
    }
    StackNode* temp = stk->top;
    Node* treeNode = temp->treeNode;
    stk->top = stk->top->next;
    free(temp);
    return treeNode;
}

// Function to get the top tree node from the stack without popping
Node* top(stack* stk) {
    if (stk->top == NULL) {
        return NULL;
    }
    return stk->top->treeNode;
}

// Function to create a BST from preorder traversal
Node* CreatePre(int pre[], int n) {
    stack stk;
    initStack(&stk);
    Node *t, *p;
    int i = 0;

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = pre[i++];
    root->lchild = NULL;
    root->rchild = NULL;
    p = root;

    while (i < n) {
        if (pre[i] < p->data) {
            t = (Node*)malloc(sizeof(Node));
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            push(&stk, p);
            p = t;
        } else {
            if (pre[i] > p->data && (stk.top == NULL || pre[i] < top(&stk)->data)) {
                t = (Node*)malloc(sizeof(Node));
                t->data = pre[i++];
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                p = t;
            } else {
                p = pop(&stk);
            }
        }
    }
    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->lchild);
        printf("%d ", root->data);
        inorderTraversal(root->rchild);
    }
}

// Main function to test the BST construction
int main() {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    Node* root = CreatePre(preorder, size);

    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}