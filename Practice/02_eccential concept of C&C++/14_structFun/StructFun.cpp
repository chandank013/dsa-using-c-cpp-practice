#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b)
{
    r->length=l;
    r->breadth=b;
}

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(Rectangle r)
{
    return 2 * (r.length + r.breadth);
}

int main()
{
    Rectangle r = {0, 0};

    int l,b;
    cout << "Enter the length and breadth: "; // Use cout
    cin >> l >> b;

    initialize(&r,l,b);

    int a = area(r);
    int peri = perimeter(r);

    cout << "Area: " << a << endl;
    cout << "Perimeter: " << peri << endl;

    return 0;
}