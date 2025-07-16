#include<iostream>

using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int* Q;

public:
    Queue() {
        size = 10; // default size
        front = rear = -1;
        Q = new int[size];
    }
    
    Queue(int size) {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];
    }

    ~Queue() {
        delete[] Q;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
        } else {
            rear++;
            Q[rear] = x;
        }
    }

    int dequeue() {
        int x = -1;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            front++;
            x = Q[front];
        }
        return x;
    }

    void display() {
        for (int i = front + 1; i <= rear; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}