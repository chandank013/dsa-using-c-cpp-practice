#include <iostream>

using namespace std;


// Code for template Class

template <class T> // for creating generic array to coverting in to template class


class Array
{
private:
    T *A; // for dynamically ceate an array
    int size;
    int length;

public:
    Array() // non-parameterised constructure
    {
        size=10;
        A=new T[10];
        length=0;
    }
    Array(int sz)  // parameterised constructure
    {
        size=sz;
        length=10;
        A=new T[10];
    }

    ~Array()
    {
        delete[]A;
    }

    void Display();
    void Insert(int index,T element);
    T Delete(int index);

};

template<class T>

void Array<T>::Display()
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    cout<<endl;

    }
}

template <class T>
void Array<T>::Insert(int index,T element)
{
    if (index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)
            A[i+1]=A[i];
        A[index]=element;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T x=0;
    if (index>=0 && index<length)
    {
        x=A[index];
        for(int i=index;i<length-1;i++)
        A[i]=A[i+1];
        length--;
    }
}

// Menu driven funtion of int function
int main()
{
    Array <int> arr(10);   // we can take any data type
    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);
    arr.Insert(3,11);
    arr.Insert(4,63);

    // Display the array
    arr.Display();

    // Delete an element at a specific index
    cout << "Deleted element: " << arr.Delete(2) << endl;

    return 0;
}