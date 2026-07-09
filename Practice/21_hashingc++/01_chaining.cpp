#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }

    ~LinkedList()
    {
        Node *p = first;
        while (p)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }

    void SortedInsert(int x)
    {
        Node *t = new Node;
        t->data = x;
        t->next = NULL;

        if (first == NULL || x < first->data)
        {
            t->next = first;
            first = t;
            return;
        }

        Node *p = first;
        while (p->next != NULL && p->next->data < x)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }

    int Search(int key)
    {
        Node *p = first;

        while (p)
        {
            if (p->data == key)
                return 1;
            p = p->next;
        }

        return 0;
    }

    void Delete(int key)
    {
        Node *p = first;
        Node *q = NULL;

        while (p)
        {
            if (p->data == key)
            {
                if (q == NULL) // Deleting the first node
                {
                    first = p->next;
                }
                else
                {
                    q->next = p->next;
                }
                delete p;
                return;
            }
            q = p;
            p = p->next;
        }
    }

    void Display()
    {
        Node *p = first;

        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int Hash(int key)
{
    return key % 10;
}

void Insert(LinkedList HT[], int key)
{
    int index = Hash(key);
    HT[index].SortedInsert(key);
}

int Search(LinkedList HT[], int key)
{
    int index = Hash(key);
    return HT[index].Search(key);
}

void Delete(LinkedList HT[], int key)
{
    int index = Hash(key);
    HT[index].Delete(key);
}

int main()
{
    LinkedList HT[10];   // Hash table of 10 linked lists

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 32);
    Insert(HT, 42);
    Insert(HT, 15);
    Insert(HT, 25);

    cout << "Hash Table\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << " : ";
        HT[i].Display();
        cout << endl;
    }

    cout << "\nSearching 22 : ";
    if (Search(HT, 22))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\nSearching 50 : ";
    if (Search(HT, 50))
        cout << "Found";
    else
        cout << "Not Found";

    
    Delete(HT, 22);
    Delete(HT, 50);

    cout << "\nAfter deletion:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " : ";
        HT[i].Display();
        cout << endl;
    }

    return 0;
}