#include<stdio.h>
#include<stdlib.h>

// Linear Queue;

struct Queue
{
    int size;
    int front;
    int Rear;
    int *Q;
};

void enqueue(struct Queue *q, int x)
{
    if(q->Rear == q->size-1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->Rear++;
        q->Q[q->Rear] = x;
    }
}

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->Rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->Rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i;
    for(i = q.front + 1; i <= q.Rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    createQueue(&q,5);

    // printf("Enter the size:");
    // scanf("%d",&q.size);
    // q.Q = (int *)malloc(q.size * sizeof(int));
    // q.front = q.Rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);

    return 0;
}



// Circular Queue

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void createCircularQueue(struct CircularQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueueCircular(struct CircularQueue *q, int x)
{
    if((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeueCircular(struct CircularQueue *q)
{
    int x = -1;
    if(q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void displayCircular(struct CircularQueue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while(i != (q.rear + 1) % q.size);
    printf("\n");
}

int main()
{
    struct CircularQueue q;
    createCircularQueue(&q, 5);

    enqueueCircular(&q, 10);
    enqueueCircular(&q, 20);
    enqueueCircular(&q, 30);
    enqueueCircular(&q, 40);

    displayCircular(q);

    printf("Dequeued: %d\n", dequeueCircular(&q));
    displayCircular(q);

    enqueueCircular(&q, 50);
    displayCircular(q);

    return 0;
}



// i/o restricted Dequeue
// o/p restricted Dequeue

// Double Ended Queue (Deque)

struct Deque
{
    int size;
    int front;
    int rear;
    int *Q;
};

void createDeque(struct Deque *dq, int size)
{
    dq->size = size;
    dq->front = dq->rear = -1;
    dq->Q = (int *)malloc(dq->size * sizeof(int));
}

void enqueueFront(struct Deque *dq, int x)
{
    if(dq->front == -1)
    {
        printf("Deque is Full at front\n");
    }
    else
    {
        dq->Q[dq->front] = x;
        dq->front--;
    }
}

void enqueueRear(struct Deque *dq, int x)
{
    if(dq->rear == dq->size - 1)
    {
        printf("Deque is Full at rear\n");
    }
    else
    {
        dq->rear++;
        dq->Q[dq->rear] = x;
    }
}

int dequeueFront(struct Deque *dq)
{
    int x = -1;
    if(dq->front == dq->rear)
    {
        printf("Deque is Empty\n");
    }
    else
    {
        dq->front++;
        x = dq->Q[dq->front];
    }
    return x;
}

int dequeueRear(struct Deque *dq)
{
    int x = -1;
    if(dq->rear == -1)
    {
        printf("Deque is Empty\n");
    }
    else
    {
        x = dq->Q[dq->rear];
        dq->rear--;
    }
    return x;
}

void displayDeque(struct Deque dq)
{
    int i;
    for(i = dq.front + 1; i <= dq.rear; i++)
    {
        printf("%d ", dq.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Deque dq;
    createDeque(&dq, 5);

    enqueueRear(&dq, 10);
    enqueueRear(&dq, 20);
    enqueueFront(&dq, 5);
    enqueueRear(&dq, 30);

    displayDeque(dq);

    printf("Dequeued from front: %d\n", dequeueFront(&dq));
    displayDeque(dq);

    printf("Dequeued from rear: %d\n", dequeueRear(&dq));
    displayDeque(dq);

    return 0;
}