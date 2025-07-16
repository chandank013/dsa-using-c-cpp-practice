#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

// Function to create a binary tree
void Treecreate() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    if (!root) {
        printf("Memory allocation failed for root node.\n");
        return;
    }
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);

        // Input and create the left child
        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
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
            t = (struct Node *)malloc(sizeof(struct Node));
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

// function for preorder without recursion
void IPreorder(struct Node *p) {
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

// Function for preorder traversal of the tree
void Preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// Function for inorder without recursion
void IInorder(struct Node *p) {
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

// Function for inorder traversal of the tree
void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Function for postorder without recursion
void IPostorder(struct Node *p) {
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
                push(&stk, (struct Node *)-temp);
                p = ((struct Node *)temp)->rchild;
            } else {
                printf("%d ", ((struct Node *)-temp)->data);
                p = NULL;
            }
        }
    }
}

// Function for postorder traversal of the tree
void Postorder(struct Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Lebaloorder traversal without recursion
void LebalOrder(struct Node *root) {
    struct Queue q;
    create(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(q)) {
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

int count(struct Node *root) {
    if (root) {
        return count(root->lchild) + count(root->rchild) + 1;
    }
    return 0;
}

int height(struct Node *root) {
    int x, y;
    if (root == NULL) {
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    return (x > y ? x : y) + 1;
}

// function to count only leaf nodes
int countLeaf(struct Node *p) {
    int x, y;
    if (p == NULL) {
        return 0;
    }
    if (p->lchild == NULL && p->rchild == NULL) {
        return 1;
    } else {
        x = countLeaf(p->lchild);
        y = countLeaf(p->rchild);
        return x + y;
    }
}

// function for count only 2 degree nodes
int countTwoDegree(struct Node *p) {
    int x, y;
    if (p == NULL) {
        return 0;
    }
    if (p->lchild && p->rchild) {
        return countTwoDegree(p->lchild) + countTwoDegree(p->rchild) + 1;
    } else {
        x = countTwoDegree(p->lchild);
        y = countTwoDegree(p->rchild);
        return x + y;
    }
}

// function for count only 1 degree nodes
int countOneDegree(struct Node *p) {
    int x, y;
    if (p == NULL) {
        return 0;
    }
    if ((p->lchild && p->rchild == NULL) || (p->lchild == NULL && p->rchild)) {
        return countOneDegree(p->lchild) + countOneDegree(p->rchild) + 1;
    } else {
        x = countOneDegree(p->lchild);
        y = countOneDegree(p->rchild);
        return x + y;
    }
}

// function to count 2 degree nodes as well as 1 degree nodes
int countOneTwoDegree(struct Node *p) {
    int x, y;
    if (p == NULL) {
        return 0;
    }
    if (p->lchild && p->rchild) {
        return countOneTwoDegree(p->lchild) + countOneTwoDegree(p->rchild) + 1;
    } else if (p->lchild || p->rchild) {
        return countOneTwoDegree(p->lchild) + countOneTwoDegree(p->rchild) + 1;
    } else {
        x = countOneTwoDegree(p->lchild);
        y = countOneTwoDegree(p->rchild);
        return x + y;
    }
}

// function to count 0 degree nodes
int countZeroDegree(struct Node *p) {
    int x, y;
    if (p == NULL) {
        return 0;
    }
    if (p->lchild == NULL && p->rchild == NULL) {
        return countZeroDegree(p->lchild) + countZeroDegree(p->rchild) + 1;
    } else {
        x = countZeroDegree(p->lchild);
        y = countZeroDegree(p->rchild);
        return x + y;
    }
}


int main() {
    Treecreate();

    // printf("Iterative Preorder Traversal: ");
    // IPreorder(root);
    // printf("\n");

    // printf("Preorder Traversal: ");
    // Preorder(root);
    // printf("\n");

    // printf("Iterative Inorder Traversal: ");
    // IInorder(root);
    // printf("\n");

    // printf("Inorder Traversal: ");
    // Inorder(root);
    // printf("\n");

    // printf("Iterative Postorder Traversal: ");
    // IPostorder(root);
    // printf("\n");

    // printf("Postorder Traversal: ");
    // Postorder(root);
    // printf("\n");

    // printf("Lebalorder Traversal: ");
    // LebalOrder(root);
    // printf("\n");

    // printf("Count of nodes: %d\n", count(root));
    

    // printf("Height of tree: %d\n", height(root));

    printf("Count of leaf nodes: %d\n", countLeaf(root));

    return 0;
}