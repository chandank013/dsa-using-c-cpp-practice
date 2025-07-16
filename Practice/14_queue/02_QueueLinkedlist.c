// // first method

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is Full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node* t;
    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node* p = front;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}



// Method second

// // Node structure
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Queue structure
// struct Queue {
//     struct Node *front, *rear;
// };

// // Function to create a new node
// struct Node* newNode(int data) {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }

// // Function to create a new queue
// struct Queue* createQueue() {
//     struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
//     q->front = q->rear = NULL;
//     return q;
// }

// // Function to add an element to the queue
// void enqueue(struct Queue* q, int data) {
//     struct Node* temp = newNode(data);

//     // If queue is empty, then new node is front and rear both
//     if (q->rear == NULL) {
//         q->front = q->rear = temp;
//         return;
//     }

//     // Add the new node at the end of queue and change rear
//     q->rear->next = temp;
//     q->rear = temp;
// }

// // Function to remove an element from the queue
// void dequeue(struct Queue* q) {
//     // If queue is empty, return NULL
//     if (q->front == NULL)
//         return;

//     // Store previous front and move front one node ahead
//     struct Node* temp = q->front;
//     q->front = q->front->next;

//     // If front becomes NULL, then change rear also as NULL
//     if (q->front == NULL)
//         q->rear = NULL;

//     free(temp);
// }

// // Function to display the queue
// void displayQueue(struct Queue* q) {
//     struct Node* temp = q->front;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// // Main function to test the queue
// int main() {
//     struct Queue* q = createQueue();
//     enqueue(q, 10);
//     enqueue(q, 20);
//     enqueue(q, 30);
//     enqueue(q, 40);

//     printf("Queue: ");
//     displayQueue(q);

//     dequeue(q);
//     printf("Queue after dequeue: ");
//     displayQueue(q);

//     return 0;
// }

// 1st method
// Circular Queue using Linked List

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Queue is Full\n");
        return;
    }
    temp->data = data;
    if (front == NULL) {
        front = rear = temp;
        rear->next = front;
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}


int dequeue() {
    int value = -1;
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        value = front->data;
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    return value;
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}

// 2nd method


// // Node structure
// struct Node {
//     int data;
//     struct Node* next;s
// };

// // Circular Queue structure
// struct CircularQueue {
//     struct Node* front;
//     struct Node* rear;
// };

// // Function to create a new node
// struct Node* newNode(int data) {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }

// // Function to create an empty Circular Queue
// struct CircularQueue* createQueue() {
//     struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
//     q->front = q->rear = NULL;
//     return q;
// }


// // Function to add an element to the queue with overflow condition
// void enqueue(struct CircularQueue* q, int data) {
//     struct Node* temp = newNode(data);
//     if (temp == NULL) {
//         printf("Queue Overflow\n");
//         return;
//     }
//     if (q->rear == NULL) {
//         q->front = q->rear = temp;
//         q->rear->next = q->front; // Circular link
//     } else {
//         q->rear->next = temp;
//         q->rear = temp;
//         q->rear->next = q->front; // Circular link
//     }
//     printf("Inserted %d\n", data);
// }


// // Function to remove an element from the queue
// int dequeue(struct CircularQueue* q) {
//     if (q->front == NULL) {
//         printf("Queue Underflow\n");
//         return -1;
//     }

//     int data;
//     if (q->front == q->rear) {
//         data = q->front->data;
//         free(q->front);
//         q->front = q->rear = NULL;
//     } else {
//         struct Node* temp = q->front;
//         data = temp->data;
//         q->front = q->front->next;
//         q->rear->next = q->front; // Circular link
//         free(temp);
//     }
//     printf("Deleted %d\n", data);
//     return data;
// }

// // Function to traverse the queue
// void traverse(struct CircularQueue* q) {
//     if (q->front == NULL) {
//         printf("Queue is empty\n");
//         return;
//     }

//     struct Node* temp = q->front;
//     printf("Queue elements: ");
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != q->front);
//     printf("\n");
// }

// int main() {
//     struct CircularQueue* q = createQueue();

//     enqueue(q, 10);
//     enqueue(q, 20);
//     enqueue(q, 30);
//     enqueue(q, 40);
//     enqueue(q, 00);

//     traverse(q);

//     dequeue(q);
//     dequeue(q);

//     traverse(q);

//     return 0;
// }




//Double ended Queue

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    return temp;
}

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Function to add an element at the front of the deque
void insertFront(struct Deque* dq, int data) {
    struct Node* temp = newNode(data);
    if (dq->front == NULL) {
        dq->front = dq->rear = temp;
    } else {
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }
}

// Function to add an element at the rear of the deque
void insertRear(struct Deque* dq, int data) {
    struct Node* temp = newNode(data);
    if (dq->rear == NULL) {
        dq->front = dq->rear = temp;
    } else {
        temp->prev = dq->rear;
        dq->rear->next = temp;
        dq->rear = temp;
    }
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
}

// Function to display the deque
void displayDeque(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the deque
int main() {
    struct Deque* dq = createDeque();
    insertRear(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    insertFront(dq, 2);

    printf("Deque: ");
    displayDeque(dq);

    deleteFront(dq);
    printf("Deque after deleting front: ");
    displayDeque(dq);

    deleteRear(dq);
    printf("Deque after deleting rear: ");
    displayDeque(dq);

    return 0;
}

