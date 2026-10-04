#include<iostream>
#include<climits>

using namespace std;

// Node class representing each element in the linked list
class Node
{
    public:
    int data;  // Data part of the node
    Node *next;  // Pointer to the next node
};

class circularLinkedList
{
    private:
    Node *head;  // Pointer to the first node in the list

    public:
    circularLinkedList();  // Default constructor
    circularLinkedList(int A[], int n);  // Parameterized constructor to create a list from an array
    ~circularLinkedList();  // Destructor to free the allocated memory
    Node* getFirst() { return head; }  // Function to get the first node of the list

    void Display();  // Function to display the elements of the list
    void rDisplay(Node *p);  // Recursive function to display the elements of the list
};

// Default constructor
circularLinkedList::circularLinkedList()
{
    head = NULL;  // Initialize the head pointer to NULL
}

// Parameterized constructor to create a circular linked list from an array
circularLinkedList::circularLinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    head = new Node;  // Create the first node
    head->data = A[0];  // Assign data to the first node
    head->next = head;  // Point the next of the first node to itself (circular)
    last = head;  // Initialize last pointer to the first node

    for (i = 1; i < n; i++)
    {
        t = new Node;  // Create a new node
        t->data = A[i];  // Assign data to the new node
        t->next = last->next;  // Point the next of the new node to the first node
        last->next = t;  // Link the last node to the new node
        last = t;  // Move the last pointer to the new node
    }
}

// Destructor to free the allocated memory
circularLinkedList::~circularLinkedList()
{
    if (head == NULL) return;  // If the list is empty, return

    Node *p = head;
    Node *temp;

    do
    {
        temp = p->next;  // Store the next node
        delete p;  // Delete the current node
        p = temp;  // Move to the next node
    } while (p != head);  // Continue until we loop back to the first node

    head = NULL;  // Set the head pointer to NULL
}

// Function to display the elements of the circular linked list
void circularLinkedList::Display()
{
    if (head == NULL) return;  // If the list is empty, return

    Node *p = head;
    do
    {
        cout << p->data;  // Print the data of the current node
        p = p->next;  // Move to the next node
        if (p != head)  // If we haven't looped back to the first node
            cout << " -> ";  // Print an arrow to indicate the link
    } while (p != head);  // Continue until we loop back to the first node

    cout << endl;  // Print a newline at the end
}

// Recursive function to display the elements of the circular linked list
void circularLinkedList::rDisplay(Node *p)
{
    static int flag = 0;  // Static variable to track if we have looped back to the first node

    if (p != head || flag == 0)  // If we haven't looped back or it's the first call
    {
        flag = 1;  // Set the flag to indicate we have started displaying
        cout << p->data << " ";  // Print the data of the current node
        rDisplay(p->next);  // Recursively call rDisplay for the next node
    }
    flag = 0;  // Reset the flag after finishing the display
}



int main()
{
    int A[] = {1, 2, 3, 4, 5};
    circularLinkedList cl(A, 5);

    cl.Display();  // Display the circular linked list
    cout << endl;

    // Display the circular linked list using recursion
    cout << "Recursive Display: ";
    cl.rDisplay(cl.getFirst());
    cout << endl;

    return 0;
}