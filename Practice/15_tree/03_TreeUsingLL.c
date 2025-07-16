#include<stdio.h>
#include<stdlib.h>

// Define the structure for a binary tree node using a linked list and recursion

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory not allocated\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertLeft(struct node *root, int data){
    root->left = createNode(data);
}

void insertRight(struct node *root, int data){
    root->right = createNode(data);
}

// inorder traversal using recursion
void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// inorder traversal without recursion
void inorderWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// preorder traversal using recursion
void preorder(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// preorder traversal without recursion
void preorderWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            printf("%d ", current->data);
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        current = current->right;
    }
}



// postorder traversal using recursion
void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// postorder traversal without recursion
void postorderWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    struct node *current = root;
    struct node *prev = NULL;
    do{
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        while(current == NULL && top != -1){
            current = stack[top];
            if(current->right == NULL || current->right == prev){
                printf("%d ", current->data);
                top--;
                prev = current;
                current = NULL;
            }else{
                current = current->right;
            }
        }
    }while(top != -1);
}

// Lebalorder traversal using recursion
void levelorder(struct node *root){
    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
    while(front != rear){
        struct node *current = queue[++front];
        printf("%d ", current->data);
        if(current->left != NULL){
            queue[++rear] = current->left;
        }
        if(current->right != NULL){
            queue[++rear] = current->right;
        }
    }
}

// Lebalorder traversal without recursion
void levelorderWithoutRecursion(struct node *root){
    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
    while(front != rear){
        struct node *current = queue[++front];
        printf("%d ", current->data);
        if(current->left != NULL){
            queue[++rear] = current->left;
        }
        if(current->right != NULL){
            queue[++rear] = current->right;
        }
    }
}

// function to count the number of nodes in the tree using recursion
int count(struct node *root){
    if(root == NULL){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

// function to count the number of nodes in the tree without recursion
int countWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int count = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        count++;
        current = current->right;
    }
    return count;
}

// function to calculate the height of the tree using recursion
int height(struct node *root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// function to calculate the height of the tree without recursion
int heightWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int height = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        height++;
        current = current->right;
    }
    return height;
}

// function to count only leaf nodes using recursion
int countLeaf(struct node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

// function to count only leaf nodes without recursion
int countLeafWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int count = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if(current->left == NULL && current->right == NULL){
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 1-degree nodes using recursion
int countOneDegree(struct node *root){
    if(root == NULL){
        return 0;
    }
    if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
        return countOneDegree(root->left) + countOneDegree(root->right) + 1;
    }
    return countOneDegree(root->left) + countOneDegree(root->right);
}

// function to count 1-degree nodes without recursion

int countOneDegreeWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int count = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if((current->left != NULL && current->right == NULL) || (current->left == NULL && current->right != NULL)){
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 2-degree nodes using recursion
int countTwoDegree(struct node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left != NULL && root->right != NULL){
        return countTwoDegree(root->left) + countTwoDegree(root->right) + 1;
    }
    return countTwoDegree(root->left) + countTwoDegree(root->right);
}

// function to count 2-degree nodes without recursion
int countTwoDegreeWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int count = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if(current->left != NULL && current->right != NULL){
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 1-degree and 2-degree nodes using recursion
int countOneTwoDegree(struct node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left != NULL && root->right != NULL){
        return countOneTwoDegree(root->left) + countOneTwoDegree(root->right) + 1;
    }else if(root->left != NULL || root->right != NULL){
        return countOneTwoDegree(root->left) + countOneTwoDegree(root->right) + 1;
    }else{
        return countOneTwoDegree(root->left) + countOneTwoDegree(root->right);
    }
}

// function to count 1-degree and 2-degree nodes without recursion
int countOneTwoDegreeWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int count = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if(current->left != NULL && current->right != NULL){
            count++;
        }else if(current->left != NULL || current->right != NULL){
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 0-degree nodes using recursion
int countZeroDegree(struct node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return countZeroDegree(root->left) + countZeroDegree(root->right) + 1;
    }
    return countZeroDegree(root->left) + countZeroDegree(root->right);
}
// function to count 0-degree nodes without recursion
int countZeroDegreeWithoutRecursion(struct node *root){
    struct node *stack[100];
    int top = -1;
    int count = 0;
    struct node *current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if(current->left == NULL && current->right == NULL){
            count++;
        }
        current = current->right;
    }
    return count;
}

//

int main(){
    struct node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Inorder traversal without recursion: ");
    inorderWithoutRecursion(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Preorder traversal without recursion: ");
    preorderWithoutRecursion(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Postorder traversal without recursion: ");
    postorderWithoutRecursion(root);
    printf("\n");

    return 0;
}


