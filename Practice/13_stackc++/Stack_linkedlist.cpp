// C++ class for stack using linked list
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};

class Stack
{
    private:
    Node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    void Display();
    void push(int x);
    int pop();
    int peek(int pos);
    int stackTop();
    int isEmpty();
    int isFull();
};

void Stack::Display()
{
    Node *p;
    p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stack is full\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop()
{
    Node *t;
    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

int Stack::peek(int pos)
{
    Node *p=top;
    for(int i=0;p!=NULL && i<pos-1;i++)
        p=p->next;
    if(p!=NULL)
        return p->data;
    else
        return -1;
}

int Stack::stackTop()
{
    if(top!=NULL)
        return top->data;
    return -1;
}

int Stack::isEmpty()
{
    return top?0:1;
}

int Stack::isFull()
{
    Node *t=new Node;
    int r=t?0:1;
    delete t;
    return r;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.Display();
    cout<<stk.pop()<<endl;
    stk.Display();
    cout<<stk.peek(2)<<endl;
    cout<<stk.stackTop()<<endl;
    cout<<stk.isEmpty()<<endl;
    cout<<stk.isFull()<<endl;
    return 0;
}

// Output
// 50 40 30 20 10
// 50
// 40 30 20 10
// 30
// 40
// 0
// 0
    