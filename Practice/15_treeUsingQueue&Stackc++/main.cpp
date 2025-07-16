#include <stdio.h>  
#include<iostream>
#include "QueueCpp.h"

class Tree
{
public:
    Node* root;
    Tree(){root = NULL;}
    void createTree(); 
    void preorder(Node* p);
    void postorder(Node* p);
    void inorder(Node* p);
    void levelorder(Node* p);
    int height(Node* p);
};

void Tree::createTree()
{
    Node* p;
    Node* t;
    int x;
    Queue q(100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->left = root->right = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.enqueue(t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node* p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void Tree::inorder(Node* p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void Tree::postorder(Node* p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

void Tree::levelorder(Node* p)
{
    Queue q(100);
    printf("%d ", root->data);
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        if(p->left)
        {
            printf("%d ", p->left->data);
            q.enqueue(p->left);
        }
        if(p->right)
        {
            printf("%d ", p->right->data);
            q.enqueue(p->right);
        }
    }
}

int Tree::height(Node* p)
{
    int x = 0, y = 0;
    if(p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    if(x > y)
        return x + 1;
    else
        return y + 1;
}


int main()
{
    Tree t;
    t.createTree();
    printf("Preorder: ");
    t.preorder(t.root);
    printf("\n");

    printf("Inorder: ");
    t.inorder(t.root);
    printf("\n");

    printf("Postorder: ");
    t.postorder(t.root);
    printf("\n");
    return 0;
}

