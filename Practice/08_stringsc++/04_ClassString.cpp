#include<iostream>
#include<string>

using namespace std;


int main()
{
    // // Using string class to store and manipulate strings
    // string str="welcome";
    // cout<<"String is "<<str<<endl;
    // cout<<"Length of string is "<<str.length()<<endl;

    // // Using getline to read string will read the whole line including spaces
    // string str1;
    // cout<<"Enter a string "<<endl;
    // getline(cin,str1);
    // cout<<"String is "<<str1<<endl;
    // cout<<"Length of string is "<<str1.length()<<endl;

    // // Using cin to read string will read the one word and pass to the next word will be read in the next cin statement
    // string str2;
    // cout<<"Enter a string "<<endl;
    // cin>>str2;
    // cin>>str2;
    // cout<<"String is "<<str2<<endl;
    // cout<<"Length of string is "<<str2.length()<<endl;
    

    // Functions of string class
    string s="welcome";
    // length of string
    cout<<"Length of string is "<<s.length()<<endl;
    // size of string
    cout<<"Size of string is "<<s.size()<<endl;
    // empty string
    cout<<"Is string empty? "<<s.empty()<<endl;
    // clear string
    s.clear();
    cout<<"String after clear is "<<s<<endl;
    // capacity of string
    cout<<"Capacity of string is "<<s.capacity()<<endl;
    // resize string
    s.resize(10);
    cout<<"String after resize is "<<s<<endl;
    // append string
    s.append("hello");
    cout<<"String after append is "<<s<<endl;
    // insert string
    s.insert(0,"welcome");
    cout<<"String after insert is "<<s<<endl;
    // erase string
    s.erase(0,7);
    cout<<"String after erase is "<<s<<endl;
    // replace string
    s.replace(0,5,"hi");
    cout<<"String after replace is "<<s<<endl;
    // find string
    cout<<"Position of string is "<<s.find("hi")<<endl;
    // substr string
    cout<<"Substring is "<<s.substr(0,2)<<endl;
    // compare string
    string s1="hi";
    cout<<"Compare string is "<<s.compare(s1)<<endl;
    // max size of string
    cout<<"Max size of string is "<<s.max_size()<<endl;
    // swap string
    string s2="hello";
    s.swap(s2);
    cout<<"String after swap is "<<s<<endl;
    // c_str string
    cout<<"C string is "<<s.c_str()<<endl;
    // push back string
    s.push_back('!');
    cout<<"String after push back is "<<s<<endl;
    // pop back string
    s.pop_back();
    cout<<"String after pop back is "<<s<<endl;
    // to lower string
    for(int i=0;i<s.length();i++)    {
        s[i]=tolower(s[i]);
    }
    cout<<"String after to lower is "<<s<<endl;
    // to upper string
    for(int i=0;i<s.length();i++)    {
        s[i]=toupper(s[i]);
    }   
    cout<<"String after to upper is "<<s<<endl;
    // find first of string
    cout<<"Position of first of string is "<<s.find_first_of("E")<<endl;
    // find last of string
    cout<<"Position of last of string is "<<s.find_last_of("E")<<endl;
    // at string
    cout<<"Character at position 0 is "<<s.at(0)<<endl;
    // front string
    cout<<"Front character is "<<s.front()<<endl;
    // back string
    cout<<"Back character is "<<s.back()<<endl;
    // data string
    cout<<"Data string is "<<s.data()<<endl;
    // [] operator string
    cout<<"Character at position 0 is "<<s[0]<<endl;
    // + operator string
    string s3=" world";
    cout<<"String after + operator is "<<s+s3<<endl;
    // += operator string
    s+=s3;
    cout<<"String after += operator is "<<s<<endl;
    // == operator string
    string s4="HELLO WORLD";
    cout<<"String after == operator is "<<(s==s4)<<endl;
    // = operator string
    s=s4;
    cout<<"String after = operator is "<<s<<endl;


    return 0;
}
