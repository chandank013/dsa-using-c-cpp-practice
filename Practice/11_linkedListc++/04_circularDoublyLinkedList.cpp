#include<iostream>
#include<climits>

using namespace std;

// node class representing a single node in the circular doubly linked list
class Node
{
    public:
    int data;  // Data stored in the node
    Node *next;  // Pointer to the next node
    Node *prev;  // Pointer to the previous node
};

class circularDoublyLinkedList
{
    private:
    Node *head;  // Pointer to the head of the list

    public:
    circularDoublyLinkedList(); // Default constructor
    circularDoublyLinkedList(int A[], int n); // Parameterized constructor to create a list from an array
    ~circularDoublyLinkedList(); // Destructor to free the allocated memory
    Node* getFirst() { return head; }  // Function to get the first node of the list
    void Display();  // Function to display the elements of the list
    void rDisplay(Node *p);  // Recursive function to display the elements of the list
    void insert(int index, int x);  // Function to insert an element at a given index
    void Delete(int index);  // Function to delete an element at a given index
    void reverse();  // Function to reverse the circular doubly linked list
};

// Default constructor to initialize the circular doubly linked list
circularDoublyLinkedList::circularDoublyLinkedList()
{
    head = NULL;  // Initialize the head pointer to NULL
}


// Parameterized constructor to create a circular doubly linked list from an array
circularDoublyLinkedList::circularDoublyLinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    head = new Node;  // Create the first node
    head->data = A[0];  // Assign data to the first node
    head->next = head;  // Next of the first node points to itself (circular)
    head->prev = head;  // Previous of the first node points to itself (circular)
    last = head;  // Initialize last pointer to the first node

    for (i = 1; i < n; i++)
    {
        t = new Node;  // Create a new node
        t->data = A[i];  // Assign data to the new node
        t->next = head;  // Next of the new node points to head (circular)
        t->prev = last;  // Previous of the new node is the last node
        last->next = t;  // Link the last node to the new node
        head->prev = t;  // Link head's previous to the new node
        last = t;  // Move the last pointer to the new node
    }
}

// Destructor to free the allocated memory of the circular doubly linked list
circularDoublyLinkedList::~circularDoublyLinkedList()
{
    if (!head) return;  // If the list is empty, return

    Node *p = head;
    do
    {
        Node *temp = p;  // Store the current node in a temporary variable
        p = p->next;  // Move to the next node
        delete temp;  // Delete the current node
    } while (p != head);  // Continue until we loop back to the head

    head = NULL;  // Set head to NULL after deletion
}

// Function to display the elements of the circular doubly linked list
void circularDoublyLinkedList::Display()
{
    if (!head) return;  // If the list is empty, return

    Node *p = head;
    do
    {
        cout << p->data << " ";  // Print the data of the current node
        p = p->next;  // Move to the next node
    } while (p != head);  // Continue until we loop back to the head
    cout << endl;  // Print a newline after displaying all elements
}

void circularDoublyLinkedList::rDisplay(Node *p)
{
    if (!p) return;  // If the current node is NULL, return

    cout << p->data << " ";  // Print the data of the current node
    rDisplay(p->next);  // Recursively call rDisplay for the next node
}

// Function to insert an element at a given index in the circular doubly linked list
void circularDoublyLinkedList::insert(int index, int x)
{
    if (index < 0) return;  // Check for valid index

    Node *t = new Node;  // Create a new node
    t->data = x;  // Assign data to the new node

    if (index == 0)  // Insertion at the beginning
    {
        if (!head)  // If the list is empty
        {
            head = t;  // Set head to the new node
            head->next = head;  // Next points to itself (circular)
            head->prev = head;  // Previous points to itself (circular)
        }
        else  // If the list is not empty
        {
            t->next = head;  // Link the new node to the current head
            t->prev = head->prev;  // Link the new node's previous to the last node
            head->prev->next = t;  // Link the last node's next to the new node
            head->prev = t;  // Link the current head's previous to the new node
            head = t;  // Update the head pointer to the new node
        }
    }
    else  // Insertion at any other position
    {
        Node *p = head;
        for (int i = 0; i < index - 1 && p->next != head; i++)  // Traverse to the node before the desired index
            p = p->next;

        if (p->next == head && index > i + 1) return;  // If index is out of bounds

        t->next = p->next;  // Link the new node to the next node
        t->prev = p;  // Link the new node's previous to p
        p->next->prev = t;  // Link the next node's previous to the new node
        p->next = t;  // Link p's next to the new node
    }
}

// Function to delete an element at a given index in the circular doubly linked list
void circularDoublyLinkedList::Delete(int index)
{
    if (index < 0 || !head) return;  // Check for valid index and non-empty list

    Node *p = head;
    if (index == 0)  // Deletion at the beginning
    {
        if (head->next == head)  // If there's only one node
        {
            delete head;  // Delete the only node
            head = NULL;  // Set head to NULL
        }
        else  // If there are multiple nodes
        {
            head->prev->next = head->next;  // Link the last node's next to the second node
            head->next->prev = head->prev;  // Link the second node's previous to the last node
            Node *temp = head;  // Store the current head in a temporary variable
            head = head->next;  // Move head to the next node
            delete temp;  // Delete the old head
        }
    }
    else  // Deletion at any other position
    {
        for (int i = 0; i < index && p->next != head; i++)  // Traverse to the node at the desired index
            p = p->next;

        if (p == head) return;  // If p is back to head, index is out of bounds

        p->prev->next = p->next;  // Link the previous node's next to the current node's next
        p->next->prev = p->prev;  // Link the next node's previous to the current node's previous
        delete p;  // Delete the current node
    }
}

// Function to reverse the circular doubly linked list
void circularDoublyLinkedList::reverse()
{
    if (!head) return;  // If the list is empty, return

    Node *p = head;
    Node *temp = NULL;

    do
    {
        temp = p->prev;  // Store the previous node
        p->prev = p->next;  // Swap the previous and next pointers
        p->next = temp;  // Link the current node's next to the previous node
        p = p->prev;  // Move to the next node (which is now in prev)
    } while (p != head);  // Continue until we loop back to the head

    head = head->prev;  // Update head to the new first node after reversal
}



int main()
{
    int A[] = {1, 2, 3, 4, 5};  // Array to initialize the circular doubly linked list
    circularDoublyLinkedList cdll(A, 5);  // Create a circular doubly linked list from the array

    cout << "Circular Doubly Linked List: ";
    cdll.Display();  // Display the elements of the list

    cdll.insert(2, 10);  // Insert 10 at index 2
    cout << "After inserting 10 at index 2: ";
    cdll.Display();  // Display the elements of the list

    cdll.Delete(3);  // Delete the element at index 3
    cout << "After deleting element at index 3: ";
    cdll.Display();  // Display the elements of the list

    cdll.reverse();  // Reverse the circular doubly linked list
    cout << "After reversing the list: ";
    cdll.Display();  // Display the elements of the list

    return 0;  // Return success
}
