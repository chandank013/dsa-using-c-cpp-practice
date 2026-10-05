#include <iostream>
#include <climits>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;  // Pointer to the previous node (for doubly linked list)
};

class doubleLinkedList
{
    private:
    Node *first;  // Pointer to the first node of the list

    public:
    doubleLinkedList(); // Default constructor
    doubleLinkedList(int A[], int n); // Parameterized constructor to create a list from an array
    ~doubleLinkedList(); // Destructor to free the allocated memory
    Node* getFirst() { return first; }  // Function to get the first node of the list
    void Display();  // Function to display the elements of the list
    void rDisplay(Node *p);  // Recursive function to display the elements of the list
    void insert(int index, int x);  // Function to insert an element at a given index
    void Delete(int index);  // Function to delete an element at a given index
    void reverse();  // Function to reverse the doubly linked list
};

doubleLinkedList::doubleLinkedList()
{
    first = NULL;  // Initialize the first pointer to NULL
}

doubleLinkedList::doubleLinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;  // Create the first node
    first->data = A[0];  // Assign data to the first node
    first->next = NULL;  // Next of the first node is NULL
    first->prev = NULL;  // Previous of the first node is NULL
    last = first;  // Initialize last pointer to the first node

    for (i = 1; i < n; i++)
    {
        t = new Node;  // Create a new node
        t->data = A[i];  // Assign data to the new node
        t->next = NULL;  // Next of the new node is NULL
        t->prev = last;  // Previous of the new node is the last node
        last->next = t;  // Link the last node to the new node
        last = t;  // Move the last pointer to the new node
    }
}

doubleLinkedList::~doubleLinkedList()
{
    Node *p = first;
    while (first)  // Traverse the list and delete each node
    {
        first = first->next;  // Move first to the next node
        delete p;  // Delete the current node
        p = first;  // Move p to the new first
    }
}

void doubleLinkedList::Display()
{
    Node *p = first;
    while (p)  // Traverse the list and print each node's data
    {
        cout << p->data << " ";  // Print the data of the current node
        p = p->next;  // Move to the next node
    }
    cout << endl;  // Print a newline after displaying all elements
}

void doubleLinkedList::rDisplay(Node *p)
{
    if (p)  // If the current node is not NULL
    {
        cout << p->data << " ";  // Print the data of the current node
        rDisplay(p->next);  // Recursively call rDisplay for the next node
    }
}

// Function to insert an element at a given index in the doubly linked list
void doubleLinkedList::insert(int index, int x)
{
    if (index < 0) return;  // Check for valid index

    Node *t = new Node;  // Create a new node
    t->data = x;  // Assign data to the new node

    if (index == 0)  // Insertion at the beginning
    {
        t->next = first;  // Link the new node to the current head
        t->prev = NULL;  // Previous of the new node is NULL
        if (first) first->prev = t;  // If the list is not empty, link the current head's previous to the new node
        first = t;  // Update the first pointer to the new node
    }
    else  // Insertion at any other position
    {
        Node *p = first;
        for (int i = 0; i < index - 1 && p; i++)  // Traverse to the node before the desired index
            p = p->next;
        if (!p) return;  // If p is NULL, index is out of bounds

        t->next = p->next;  // Link the new node to the next node
        t->prev = p;  // Link the new node's previous to p
        if (p->next) p->next->prev = t;  // If there is a next node, link its previous to the new node
        p->next = t;  // Link p's next to the new node
    }
}

// Function to delete an element at a given index in the doubly linked list
void doubleLinkedList::Delete(int index)
{
    if (index < 0 || !first) return;  // Check for valid index and non-empty list

    Node *p = first;
    if (index == 0)  // Deletion at the beginning
    {
        first = first->next;  // Move first to the next node
        if (first) first->prev = NULL;  // If the list is not empty, set the new first's previous to NULL
        delete p;  // Delete the old first
    }
    else  // Deletion at any other position
    {
        for (int i = 0; i < index && p; i++)  // Traverse to the node at the desired index
            p = p->next;
        if (!p) return;  // If p is NULL, index is out of bounds

        if (p->prev) p->prev->next = p->next;  // Link the previous node's next to the current node's next
        if (p->next) p->next->prev = p->prev;  // Link the next node's previous to the current node's previous
        delete p;  // Delete the current node
    }
}

// Function to reverse the doubly linked list
void doubleLinkedList::reverse()
{
    Node *p = first;
    Node *temp = NULL;

    while (p)  // Traverse the list
    {
        temp = p->prev;  // Store the previous node
        p->prev = p->next;  // Swap the previous and next pointers
        p->next = temp;  // Link the current node's next to the previous node
        p = p->prev;  // Move to the next node (which is now in prev)
    }

    if (temp) first = temp->prev;  // Update first to the new first node
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    doubleLinkedList dll(A, 5);  // Create a doubly linked list from the array

    // Display the original list
    cout << "Original list: ";
    dll.Display();  // Display the doubly linked list
    cout << endl;

    // recursively display the list
    cout << "Recursive display: ";
    dll.rDisplay(dll.getFirst());  // Recursively display the doubly linked list
    cout << endl;

    // Insert an element at index 2
    cout << "Inserting 10 at index 2:";
    dll.insert(2, 10);  // Insert 10 at index 2
    dll.Display();  // Display the list after insertion
    cout << endl;

    // Delete an element at index 3
    cout << "Deleting element at index 3:";
    dll.Delete(3);  // Delete the element at index 3
    dll.Display();  // Display the list after deletion
    cout << endl;

    // Reverse the doubly linked list
    cout << "Reversing the list:";
    dll.reverse();  // Reverse the doubly linked list
    dll.Display();  // Display the reversed list
    cout << endl;

    return 0;
}
