#include<stdio.h>
#include<stdlib.h>
 

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
}*root = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}   


// teacher : write a function to insert a node in a binary search tree
void insert(int key) {
    struct Node *t=root;
    struct Node *r,*p;
    if(root==NULL) {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL) {
        r=t;
        if(key<t->data) {
            t=t->lchild;
        } else if(key>t->data) {
            t=t->rchild;
        } else {
            return; // Duplicate key, do not insert
        }
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data) {
        r->lchild=p;
    } else {
        r->rchild=p;
    }

}

struct Node *RInsert(struct Node *p,int key) {
    struct Node *t=NULL;
    if(p==NULL) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data) {
        p->lchild=RInsert(p->lchild,key);
    } else if(key>p->data) {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}

void inorder(struct Node* p) {
    if(p) {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void preorder(struct Node* p) {
    if(p) {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node* p) {
    if(p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}


void RSearch(struct Node* p,int key) {
    if(p==NULL) {
        printf("Key not found\n");
        return;
    }
    if(key==p->data) {
        printf("Key found\n");
        return;
    } else if(key<p->data) {
        search(p->lchild,key);
    } else {
        search(p->rchild,key);
    }
}

struct Node* search1(struct Node* p,int key) {
    struct Node *t=root;
    while(t!=NULL) {
        if(key==t->data) {
            return t;
        } else if(key<t->data) {
            t=t->lchild;
        } else {
            t=t->rchild;
        }
        return NULL;
    }
}



void find_min(struct Node* p) {
    if(p==NULL) {
        printf("Tree is empty\n");
        return;
    }
    while(p->lchild!=NULL) {
        p=p->lchild;
    }
    printf("Minimum value is %d\n",p->data);
}

void find_max(struct Node* p) {
    if(p==NULL) {
        printf("Tree is empty\n");
        return;
    }
    while(p->rchild!=NULL) {
        p=p->rchild;
    }
    printf("Maximum value is %d\n",p->data);
}


int Height(struct Node* p) {
    int x,y;
    if(p==NULL) {
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y ? x+1 : y+1;
}

struct Node *Ipre(struct Node *p) {
    while(p && p->rchild!=NULL) {
        p=p->rchild;
    }
    return p;
}

struct Node *Insucc(struct Node *p) {
    while(p && p->lchild!=NULL) {
        p=p->lchild;
    }
    return p;
}

struct Node *Delete1(struct Node *p, int key) {
    struct Node *q;
    if (p == NULL) {
        return NULL;
    }
    if (key < p->data) {
        p->lchild = Delete1(p->lchild, key); // Corrected from Delete2 to Delete1
    } else if (key > p->data) {
        p->rchild = Delete1(p->rchild, key); // Corrected from Delete2 to Delete1
    } else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = Ipre(p->lchild);
            p->data = q->data;
            p->lchild = Delete1(p->lchild, q->data); // Corrected from Delete2 to Delete1
        } else if (Height(p->lchild) < Height(p->rchild)) {
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete1(p->rchild, q->data); // Corrected from Delete2 to Delete1
        } else {
            q = p;
            if (p->lchild == NULL) {
                p = p->rchild;
            } else if (p->rchild == NULL) {
                p = p->lchild;
            }
            free(q);
        }
    }
    return p;
}

void level_order(struct Node* p) {
    if(p==NULL) {
        return;
    }
    struct Node* queue[100];
    int front=0,rear=0;
    queue[rear++]=p;
    while(front<rear) {
        p=queue[front++];
        printf("%d ",p->data);
        if(p->lchild!=NULL) {
            queue[rear++]=p->lchild;
        }
        if(p->rchild!=NULL) {
            queue[rear++]=p->rchild;
        }
    }
}

void destroy(struct Node* p) {
    if(p==NULL) {
        return;
    }
    destroy(p->lchild);
    destroy(p->rchild);
    free(p);
}


// main function
int main() {
    struct Node *temp;


    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

    Delete1(root, 20);

    inorder(root);
    printf("\n");

    temp = search1(root, 10);
    if(temp) {
        printf("Key found\n");
    } else {
        printf("Key not found\n");
    }

    
    return 0;
}



