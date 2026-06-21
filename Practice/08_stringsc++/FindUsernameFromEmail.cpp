#include<iostream>
#include<string>

using namespace std;

int main() {

    string email;
    cout<< "Enter the email: ";
    getline(cin, email);
    string userName;

    // check the username is valid or not only contains lowercase letters, digits and underscores
    for(int i=0; i<email.length(); i++){
        if(email[i]=='@'){
            break;
        }
        if((email[i]>='a' && email[i]<='z') || (email[i]>='0' && email[i]<='9') || email[i]=='_'){
            continue;
        }
        else{
            cout<< "Invalid username";
            return 0;
        }
    }

    // code to find the username from the email
    for(int i=0; i<email.length(); i++){
        if(email[i]=='@'){
            userName = email.substr(0,i);
            break;
        }
    }


    // int i=(int)email.find('@');
    // userName = email.substr(0,i);

    cout<< "User name is: "<<userName;

    

    return 0;
}