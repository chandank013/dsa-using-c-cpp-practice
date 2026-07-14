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
    Node* getFirst() { return first; }  // Function to get the first node of the list
    

    void Display();  // Function to display the elements of the list
    void RDisplay(Node *p);  // Recursive display of linked list
    void Insert(int index, int x);  // Function to insert an element at a given index
    int Delete(int index);  // Function to delete an element at a given index
    int Length();  // Function to calculate the length of the list
    int Sum();  // Function to calculate the sum of the elements in the list
    int Max();  // Function to find the maximum element in the list
    int Min();  // Function to find the minimum element in the list
    Node* Search(int key);  // Function to search for an element in the list
    bool isSorted();  // Function to check if the list is sorted    
    bool hasDuplicates();  // Function to check if the list has duplicate elements
    void removeDuplicates();  // Function to remove duplicates from a sorted list
    void removeDuplicatesUnsorted();  // Function to remove duplicates from an unsorted list

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
        cout << p->data;
        p = p->next;
        if (p)
            cout << " -> ";
    }
    cout << endl;
}

// Recursive display of linked list
void LinkedList::RDisplay(Node *p)
{
    if (p != NULL)
    {
        cout << p->data;
        if (p->next != NULL)
            cout << " -> ";
        RDisplay(p->next);
    }
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

int LinkedList::Sum()
{
    Node *p = first;
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::Max()
{
    Node *p = first;
    int max = p->data;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int LinkedList::Min()
{
    Node *p = first;
    int min = p->data;
    while (p)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

// Searching element in linked list
Node* LinkedList::Search(int key)
{
    Node *p = first;
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// check if linked list is sorted or not
bool LinkedList::isSorted()
{
    Node *p = first;
    int x = INT_MIN;  // Initialize x to the minimum integer value
    while (p)
    {
        if (p->data < x)  // If the current node's data is less than x, the list is not sorted
            return false;
        x = p->data;  // Update x to the current node's data
        p = p->next;  // Move to the next node
    }
    return true;  // The list is sorted
}

// check if duplicate elements are present in linked list or not
bool LinkedList::hasDuplicates()
{
    Node *p = first;
    while (p)
    {
        Node *q = p->next;
        while (q)
        {
            if (p->data == q->data)
                return true;
            q = q->next;
        }
        p = p->next;
    }
    return false;
}

// remove duplicates from sorted linked list
void LinkedList::removeDuplicates()
{
    Node *p = first;
    Node *q = first->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// remove duplicates from unsorted linked list
void LinkedList::removeDuplicatesUnsorted()
{
    Node *p = first;
    while (p)
    {
        Node *q = p;
        while (q->next)
        {
            if (p->data == q->next->data)
            {
                Node *temp = q->next;
                q->next = q->next->next;
                delete temp;
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    l.Display();  // Display the linked list
    cout << endl;

    l.Insert(3, 10);  // Insert 10 at index 3
    l.Display();  // Display the linked list after insertion
    cout << endl;

    l.RDisplay(l.getFirst());
    cout << endl;

    // Display the length of the linked list
    cout << "Length of the linked list: " << l.Length() << endl;

    // Sum of the elements in the linked list
    cout << "Sum of the elements in the linked list: " << l.Sum() << endl;

    // Maximum element in the linked list
    cout << "Maximum element in the linked list: " << l.Max() << endl;
    // Minimum element in the linked list
    cout << "Minimum element in the linked list: " << l.Min() << endl;

    // Search for an element in the linked list
    Node *searchResult = l.Search(3);
    if (searchResult)
        cout << "Element found in the linked list." << endl;
    else
        cout << "Element not found in the linked list." << endl;

    // Check if the linked list is sorted
    if (l.isSorted())
        cout << "The linked list is sorted." << endl;
    else
        cout << "The linked list is not sorted." << endl;

    // Check for duplicates in the linked list
    if (l.hasDuplicates())
        cout << "The linked list has duplicate elements." << endl;
    else
        cout << "The linked list does not have duplicate elements." << endl;

    // Remove duplicates from the linked list (if any)
    l.removeDuplicates();
    cout << "Linked list after removing duplicates: ";
    l.Display();  // Display the linked list after removing duplicates

    // Remove duplicates from an unsorted linked list (if any)
    l.removeDuplicatesUnsorted();
    cout << "Linked list after removing duplicates from unsorted list: ";
    l.Display();

    return 0;
}