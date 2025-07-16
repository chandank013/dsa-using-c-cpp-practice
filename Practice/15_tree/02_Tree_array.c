#include<stdio.h>
#include<stdlib.h>

// variable to store maximum number of nodes
int complete_node = 15;

// array to store the tree
char tree[] = {'\0','D','A','F','E','B','R','T','G','Q','\0','\0','V','\0','J','L'};


int get_right_child(int index) 
{
    // Calculate the index of the right child
    int right_child_index = (2 * index) + 1;

    // Check if the calculated index is within the bounds of the tree array
    // and if the element at that index is not the null character
    if (right_child_index < complete_node && tree[right_child_index] != '\0')
        return right_child_index;

    // If the right child does not exist, return -1
    return -1;
}

int get_left_child(int index)
{
    // Calculate the index of the left child
    int left_child_index = 2 * index;

    // Check if the calculated index is within the bounds of the tree array
    // and if the element at that index is not the null character
    if (left_child_index <= complete_node && tree[left_child_index] != '\0')
        return left_child_index;

    // If the left child does not exist, return -1
    return -1;
}

void preorder_traversal(int index)
{
    if (index > complete_node || tree[index] == '\0')
        return;

    // Print the current node
    printf("%c ", tree[index]);

    // Traverse the left subtree
    preorder_traversal(get_left_child(index));

    // Traverse the right subtree
    preorder_traversal(get_right_child(index));
}

void inorder_traversal(int index)
{
    if (index > complete_node || tree[index] == '\0')
        return;

    // Traverse the left subtree
    inorder_traversal(get_left_child(index));

    // Print the current node
    printf("%c ", tree[index]);

    // Traverse the right subtree
    inorder_traversal(get_right_child(index));
}

void postorder_traversal(int index)
{
    if (index > complete_node || tree[index] == '\0')
        return;

    // Traverse the left subtree
    postorder_traversal(get_left_child(index));

    // Traverse the right subtree
    postorder_traversal(get_right_child(index));

    // Print the current node
    printf("%c ", tree[index]);
}


int main()
{
    int root_index = 1;

    printf("Preorder traversal: ");
    preorder_traversal(root_index);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root_index);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root_index);
    printf("\n");

    return 0;
}







// Binry tree using structure array

typedef struct node
{
    struct node*left;
    struct node*right;
    char data;
}node;

node* insert(char c[],int n)
{
    node*tree=NULL;
    if (n < 20 && c[n] != '\0') {
        tree = (node*)malloc(sizeof(node));
        tree->data = c[n];
        tree->left = insert(c, 2 * n + 1);
        tree->right = insert(c, 2 * n + 2);
    }
    return tree;
}


void inorder_with_rec(node* tree)
{
    if (tree != NULL) {
        inorder(tree->left);
        printf("%c ", tree->data);
        inorder(tree->right);
    }
}



void preorder_with_rec(node* tree)
{
    if (tree != NULL) {
        printf("%c ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder_with_rec(node* tree)
{
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%c ", tree->data);
    }
}

// Leabel order traversal
void levelorder(node* tree)
{
    node*queue[100];
    int front = -1, rear = -1;
    queue[++rear] = tree;
    while (front != rear) {
        node*current = queue[++front];
        printf("%c ", current->data);
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
}

// function to count the number of nodes in the tree using recursion
int count(node* root)
{
    if (root == NULL) {
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

// function to count the number of nodes in the tree without recursion
int countWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int count = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
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
int height(node* root)
{
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
// function to calculate the height of the tree without recursion
int heightWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int height = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        height++;
        current = current->right;
    }
    return height;
}

// function to count the number of leaf nodes in the tree using recursion
int countLeaf(node* root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

// function to count the number of leaf nodes in the tree without recursion
int countLeafWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int count = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if (current->left == NULL && current->right == NULL) {
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 2-degree nodes in the tree using recursion
int countTwoDegree(node* root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL && root->right != NULL) {
        return countTwoDegree(root->left) + countTwoDegree(root->right) + 1;
    }
    return countTwoDegree(root->left) + countTwoDegree(root->right);
}
// function to count 2-degree nodes in the tree without recursion
int countTwoDegreeWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int count = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if (current->left != NULL && current->right != NULL) {
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 1-degree nodes in the tree using recursion
int countOneDegree(node* root)
{
    if (root == NULL) {
        return 0;
    }
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
        return countOneDegree(root->left) + countOneDegree(root->right) + 1;
    }
    return countOneDegree(root->left) + countOneDegree(root->right);
}
// function to count 1-degree nodes in the tree without recursion
int countOneDegreeWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int count = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if ((current->left != NULL && current->right == NULL) || (current->left == NULL && current->right != NULL)) {
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 1-degree and 2-degree nodes in the tree using recursion
int countOneTwoDegree(node* root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL && root->right != NULL) {
        return countOneTwoDegree(root->left) + countOneTwoDegree(root->right) + 1;
    }
    return countOneTwoDegree(root->left) + countOneTwoDegree(root->right);
}

// function to count 1-degree and 2-degree nodes in the tree without recursion
int countOneTwoDegreeWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int count = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if (current->left != NULL && current->right != NULL) {
            count++;
        }
        current = current->right;
    }
    return count;
}

// function to count 0-degree nodes in the tree using recursion
int countZeroDegree(node* root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return countZeroDegree(root->left) + countZeroDegree(root->right) + 1;
    }
    return countZeroDegree(root->left) + countZeroDegree(root->right);
}
// function to count 0-degree nodes in the tree without recursion
int countZeroDegreeWithoutRecursion(node* root)
{
    node*stack[100];
    int top = -1;
    int count = 0;
    node*current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if (current->left == NULL && current->right == NULL) {
            count++;
        }
        current = current->right;
    }
    return count;
}

void main()
{
    node*tree=NULL;
    char c[]={'A','B','C','D','E','F','G','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    tree = insert(c,0);

    inorder_with_rec(tree);
}


