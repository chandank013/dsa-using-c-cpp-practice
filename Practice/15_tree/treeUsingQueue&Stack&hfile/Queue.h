#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// Define the structure for the queue
struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

#include "Queue.h"

// Create a queue with a given size
void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
    if (!q->Q) {
        printf("Memory allocation failed for queue.\n");
        exit(1);
    }
}

// Add an element to the queue
void enqueue(struct Queue *q, struct Node *x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full.\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Remove an element from the queue
struct Node *dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->front == q->rear) {
        printf("Queue is empty.\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// Check if the queue is empty
int isEmpty(struct Queue q) {
    return q.front == q.rear;
}

#endif // QUEUE_H