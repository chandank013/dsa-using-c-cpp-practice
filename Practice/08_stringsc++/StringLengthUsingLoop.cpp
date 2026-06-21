#include<iostream>
using namespace std;

int main()
{
	// Calculate the length of a string using a loop
	string str="welcome";
	int count=0;
	    
	for(int i=0;str[i]!='\0';i++)
	{
	    count++;
	}
	cout<<"Length is "<<count<<endl;
	    
	return 0;
	    
}
    
