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

    int Length();  // Function to calculate the length of the list
    int Count(Node *p);  // Function to nmber ofnode of the list
    int Count1(Node *p);  // Function to nmber ofnode of the list
    int Sum();  // Function to calculate the sum of the elements in the list
    int Sum1(Node *p);  // Function to calculate the sum of the elements in the list
    int Sum2(Node *p);  // Function to calculate the sum of the elements in the list using recursion
    int Sum3(Node *p);  // Function to calculate the sum of the elements in the list using recursion
    int Max();  // Function to find the maximum element in the list
    int Min();  // Function to find the minimum element in the list
    Node* Search(int key);  // Function to search for an element in the list
    Node* RSearch(Node *p, int key);  // Function to search for an element in the list using recursion
    Node* ImprovedSearch(int key);  // Function to improved search for an element in the list

    void Insert(int index, int x);  // Function to insert an element at a given index
    bool isSorted();  // Function to check if the list is sorted    
    int Delete(int index);  // Function to delete an element at a given index
    bool hasDuplicates();  // Function to check if the list has duplicate elements
    void removeDuplicates();  // Function to remove duplicates from a sorted list
    void removeDuplicatesUnsorted();  // Function to remove duplicates from an unsorted list
    void Reverse();  // Function to reverse the linked list
    void reverseUsingSlidingPointers();  // Function to reverse the linked list using sliding pointers
    void reverseUsingRecursion(Node *q, Node *p);  // Function to reverse the linked list using recursion
    void concatenate(LinkedList &l2);  // Function to concatenate two linked lists
    void merge(LinkedList &l2);  // Function to merge two sorted linked lists
    void checkLoop();  // Function to check if there is a loop in the linked list


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

// Function to count the node using recursion
int LinkedList::Count(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return Count(p->next) + 1;
    }

}

// Function to count the node using recursion
int LinkedList::Count1(Node *p)
{
    int x=0;
    if(p!=NULL)
        {
            x=Count1(p->next);
            return x+1;
        }
    else
        {
            return x;
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

int LinkedList::Sum1(Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::Sum2(Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return Sum2(p->next) + p->data;
    }
}

int LinkedList::Sum3(Node *p)
{
    int sum=0;
    if(p)
    {
        sum=Sum3(p->next);
        return sum + p->data;
    }
    else {
        return 0;
    }
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

// recursive searching element in linked list
Node* LinkedList::RSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

// improved searching element in linked list (Transposition method)
Node* LinkedList::ImprovedSearch(int key)
{
    Node *p = first;
    Node *prev = NULL;
    while (p)
    {
        if (key == p->data)
        {
            // Move the found node to the front of the list
            if (prev != NULL)
            {
                prev->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        prev = p;
        p = p->next;
    }
    return NULL;  // Element not found
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

// reversing the linked list
void LinkedList::Reverse()
{
    Node *p=first;
    int *A=new int[Length()];
    int i=0;

    while(p!=NULL)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p!=NULL)
    {
        p->data=A[i];
        p=p->next;
        i--;
    }
    delete[] A;
}

// reverse the linked list using sliding pointers
void LinkedList::reverseUsingSlidingPointers()
{
    Node *p = first;
    Node *q = NULL;
    Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// reverse the linked list using recursion
void LinkedList::reverseUsingRecursion(Node *q, Node *p)
{
    if (p != NULL)
    {
        reverseUsingRecursion(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

// Function to concatenate two linked lists
void LinkedList::concatenate(LinkedList &l2)
{
    Node *p = first;
    while (p->next != NULL)
        p = p->next;
    p->next = l2.first;
    l2.first = NULL;  // Set the second list's first pointer to NULL
}

// Function to merge two sorted linked lists
void LinkedList::merge(LinkedList &l2)
{
    Node *p = first;
    Node *q = l2.first;
    Node *last = NULL;

    if (p->data < q->data)
    {
        first = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        first = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p) last->next = p;  // If there are remaining nodes in the first list
    if (q) last->next = q;  // If there are remaining nodes in the second list

    l2.first = NULL;  // Set the second list's first pointer to NULL
}

// Function to check if there is a loop in the linked list
void LinkedList::checkLoop()
{
    Node *p = first;
    Node *q = first;

    do
    {
        p = p->next;  // Move p by one step
        q = q->next;  // Move q by one step
        if (q != NULL)
            q = q->next;  // Move q by an additional step if it's not NULL
    } while (p && q && p != q);  // Continue until p and q meet or reach the end

    if (p == q)  // If p and q meet, there is a loop
        cout << "Loop found in the linked list." << endl;
    else
        cout << "No loop found in the linked list." << endl;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    l.Display();  // Display the linked list
    cout << endl;

    // l.RDisplay(l.getFirst());
    // cout << endl;

    // // Display the length of the linked list
    // cout << "Length of the linked list: " << l.Length() << endl;

    // // count the node of the linked list
    // cout << "Number of the node in linked list: " << l.Count(l.getFirst()) << endl;

    // // Count the node of the linked list
    // cout << "Number of the node in linked list: " << l.Count1(l.getFirst()) << endl;

    // // Sum of the elements in the linked list
    // cout << "Sum of the elements in the linked list: " << l.Sum() << endl;

    // // Sum of the elements in the linked list by passing parameter
    // cout << "Sum of the elements in the linked list: " << l.Sum1(l.getFirst()) << endl;

    // // Sum of the elements in the linked list using recursion
    // cout << "Sum of the elements in the linked list: " << l.Sum2(l.getFirst()) << endl;

    // // Sum of the elements in the linked list using recursion
    // cout << "Sum of the elements in the linked list: " << l.Sum3(l.getFirst()) << endl;

    // // Maximum element in the linked list
    // cout << "Maximum element in the linked list: " << l.Max() << endl;
    // // Minimum element in the linked list
    // cout << "Minimum element in the linked list: " << l.Min() << endl;

    // // Search for an element in the linked list
    // Node *searchResult = l.Search(3);
    // if (searchResult)
    //     cout << "Element found in the linked list." << endl;
    // else
    //     cout << "Element not found in the linked list." << endl;
    
    // // Search for an element in the linked list using recursion
    // Node *rSearchResult = l.RSearch(l.getFirst(), 4);
    // if (rSearchResult)
    //     cout << "Element found in the linked list using recursion." << endl;
    // else
    //     cout << "Element not found in the linked list using recursion." << endl;

    // // Search for an element in the linked list using improved search
    // Node *improvedSearchResult = l.ImprovedSearch(5);
    // if (improvedSearchResult)
    //     cout << "Element found in the linked list using improved search." << endl;
    // else
    //     cout << "Element not found in the linked list using improved search." << endl;

    // // inserting an element in linkedlist
    // l.Insert(3, 10);  // Insert 10 at index 3
    // l.Display();  // Display the linked list after insertion
    // cout << endl;

    // // Check if the linked list is sorted
    // if (l.isSorted())
    //     cout << "The linked list is sorted." << endl;
    // else
    //     cout << "The linked list is not sorted." << endl;

    // // Check for duplicates in the linked list
    // if (l.hasDuplicates())
    //     cout << "The linked list has duplicate elements." << endl;
    // else
    //     cout << "The linked list does not have duplicate elements." << endl;
    // cout << endl;

    // // Remove duplicates from the linked list (if any)
    // l.removeDuplicates();
    // cout << "Linked list after removing duplicates: ";
    // l.Display();  // Display the linked list after removing duplicates
    // cout << endl;

    // // Remove duplicates from an unsorted linked list (if any)
    // l.removeDuplicatesUnsorted();
    // cout << "Linked list after removing duplicates from unsorted list: ";
    // l.Display();
    // cout << endl;

    // // Reverse the linked list
    // l.Reverse();
    // cout << "Linked list after reversing: ";
    // l.Display();  // Display the linked list after reversing
    // cout << endl;

    // // Reverse the linked list using sliding pointers
    // l.reverseUsingSlidingPointers();
    // cout << "Linked list after reversing using sliding pointers: ";
    // l.Display();  // Display the linked list after reversing using sliding pointers
    // cout << endl;

    // // Reverse the linked list using recursion
    // l.reverseUsingRecursion(nullptr, l.getFirst());
    // cout << "Linked list after reversing using recursion: ";
    // l.Display();  // Display the linked list after reversing using recursion
    // cout << endl;

    // // Concatenate two linked lists
    // int B[] = {6, 7, 8};
    // LinkedList l2(B, 3);
    // l.concatenate(l2);
    // cout << "Linked list after concatenation: ";
    // l.Display();  // Display the linked list after concatenation
    // cout << endl;

    // // Merge two sorted linked lists
    // int C[] = {1, 3, 5};
    // LinkedList l3(C, 3);
    // l.merge(l3);
    // cout << "Linked list after merging: ";
    // l.Display();  // Display the linked list after merging
    // cout << endl;

    // Check for loop in the linked list
    cout << "Checking for loop in the linked list: ";
    l.checkLoop();
    cout << endl;

    return 0;
}