// Referance is nickname or alias given to a variable 
#include <iostream>

using namespace std;


int main()
{
    int a =10;
    int &r=a;

    r++;
    cout<<a<<endl;
    cout<<r<<endl;

    return 0;
}