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
    void insert(int index, int x);  // Function to insert an element at a given index
    void Delete(int index);  // Function to delete an element at a given index
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

// Function to insert an element at a given index in the circular linked list
void circularLinkedList::insert(int index, int x)
{
    if (index < 0 || index > 5) return;  // Check for valid index

    Node *t = new Node;  // Create a new node
    t->data = x;  // Assign data to the new node

    if (index == 0)  // Insertion at the beginning
    {
        if (head == NULL)  // If the list is empty
        {
            head = t;  // Make the new node the head
            head->next = head;  // Point it to itself (circular)
        }
        else
        {
            Node *p = head;
            while (p->next != head)  // Traverse to the last node
                p = p->next;
            p->next = t;  // Link the last node to the new node
            t->next = head;  // Link the new node to the first node
            head = t;  // Update the head pointer to the new node
        }
    }
    else  // Insertion at any other position
    {
        Node *p = head;
        for (int i = 0; i < index - 1; i++)  // Traverse to the node before the desired index
            p = p->next;
        t->next = p->next;  // Link the new node to the next node
        p->next = t;  // Link the previous node to the new node
    }
}

// Function to delete an element at a given index in the circular linked list
void circularLinkedList::Delete(int index)
{
    if (index < 0 || index >= 5 || head == NULL) return;  // Check for valid index and non-empty list

    Node *p = head;
    if (index == 0)  // Deletion at the beginning
    {
        while (p->next != head)  // Traverse to the last node
            p = p->next;
        if (head == p)  // If there's only one node
        {
            delete head;  // Delete the head node
            head = NULL;  // Set head to NULL
        }
        else
        {
            Node *temp = head;  // Store the current head
            p->next = head->next;  // Link the last node to the second node
            head = head->next;  // Update the head pointer to the second node
            delete temp;  // Delete the old head node
        }
    }
    else  // Deletion at any other position
    {
        for (int i = 0; i < index - 1; i++)  // Traverse to the node before the desired index
            p = p->next;
        Node *temp = p->next;  // Store the node to be deleted
        p->next = temp->next;  // Link the previous node to the next node
        delete temp;  // Delete the target node
    }
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

    // Insert an element at index 0
    cout << "Inserting 10 at index 0:" << endl;
    cl.insert(0, 10);
    cl.Display();  // Display the circular linked list after insertion
    cout << endl;

    // Delete an element at index 2
    cout << "Deleting element at index 2:" << endl;
    cl.Delete(2);
    cl.Display();  // Display the circular linked list after deletion
    cout << endl;

    return 0;
}