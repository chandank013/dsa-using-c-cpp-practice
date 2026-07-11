#include<iostream>
using namespace std;

// Node class representing each element in the linked list
class Node
{
    public:
    int data;  // Data part of the node
    Node *next;  // Pointer to the next node
};

// LinkedList class representing the linked list
class LinkedList
{
    private:
    Node *first;  // Pointer to the first node in the list

    public:
    LinkedList();  // Default constructor
    LinkedList(int A[], int n);  // Parameterized constructor to create a list from an array
    ~LinkedList();  // Destructor to free the allocated memory
    
    void Display();  // Function to display the elements of the list
    void Insert(int index, int x);  // Function to insert an element at a given index
    int Delete(int index);  // Function to delete an element at a given index
    int Length();  // Function to calculate the length of the list
};

// Default constructor
LinkedList::LinkedList()
{
    first = NULL;
}

// Parameterized constructor to create a list from an array
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Destructor to free the allocated memory
LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

// Function to display the elements of the list
void LinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to calculate the length of the list
int LinkedList::Length()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Function to insert an element at a given index
void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;
    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    l.Display();  // Display the linked list

    l.Insert(3, 10);  // Insert 10 at index 3
    l.Display();  // Display the linked list after insertion

    return 0;
}