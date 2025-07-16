#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*// converting c code to c++ code
01. converting struct in to class.
02. include all the function inside the class.
03. remove all the argument related to the structure.
04. make data members as private .
05. make all the function as public.
06. now, in main function remove r all that is parameter and call the function with r.function(name) becouse all the function are present inside the class.
07. we cannot pass the value of parameter becouse the data members are private so we initialise and declear the value at the time of object creation.
08. but we want to callled automatically at time of object initialisation so we make the functuion initialise to a constructor.

** monolithic programming
=> all code written inside the main sectionm
** modular programming 
=> in which all the user intruction part of code written inside the main section and process are defined as the function that should be callable any part of code to proform action.
*/

class Rectangle
{
    private:
        int length;
        int breadth;

    public:

        Rectangle()  // default constructor that has the name same as the class name.
        {
            length=0;
            breadth=0;
        }
        Rectangle(int l, int b)  // constructor that has the name same as the class name.
        {
            length=l;
            breadth=b;
        }
        int area();
        int perimeter();
        int getLength();
        int getBreadth();
        int setLength(int l);
        int setBreadth(int b);
        ~Rectangle();  // destructor that has the name same as the class name.
        
};
int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

int Rectangle::setLength(int l)
{
    length = l;
    return length;
}
int Rectangle::setBreadth(int b)
{
    breadth = b;
    return breadth;
}

int Rectangle::getLength()
{
    return length;
}
int Rectangle::getBreadth()
{
    return breadth;
}

Rectangle::~Rectangle()
{
    cout << "Destructor called" << endl;
}

int main()
{
    Rectangle r(10,5);

    cout << "Area of rectangle is: " << r.area() << endl;
    cout << "Perimeter of rectangle is: " << r.perimeter() << endl;
    cout << "Length of rectangle is: " << r.getLength() << endl;
    cout << "Breadth of rectangle is: " << r.getBreadth() << endl;
    r.setLength(20);
    r.setBreadth(10);
    cout << "New length of rectangle is: " << r.getLength() << endl;
    cout << "New breadth of rectangle is: " << r.getBreadth() << endl;

    // Destructor will be called automatically when the object goes out of scope.
    // No need to explicitly call the destructor.

    return 0;
}