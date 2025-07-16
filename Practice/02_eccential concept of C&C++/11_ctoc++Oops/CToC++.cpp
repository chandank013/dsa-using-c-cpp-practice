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
        Rectangle(int l, int b)  // constructor that has the name same as the class name.
        {
            length=l;
            breadth=b;
        }

        int area()
        {
            return length*breadth;
        }

        void changeLength(int l)
        {
            length=l;
        }

};

int main()
{
    Rectangle r(10,5);

    printf("area is:%d\n", r.area());

    r.changeLength(25);
    printf("now area is:%d", r.area());

    return 0;
}