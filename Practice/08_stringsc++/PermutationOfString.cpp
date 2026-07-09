#include<iostream>
#include<string>
#include<cstring>

using namespace std;

// Function to generate permutations of a string using recursion
void permutation(char *s, int k)
{
    static int A[10]={0};
    static char res[10];

    if(s[k]=='\0')
    {
        res[k]='\0';
        cout << res << endl;
    }
    else
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                permutation(s,k+1);
                A[i]=0;
            }
        }
    }
}


// function to generate permutations using swapping
void permute(char *a, int l, int h)
{
    if (l == h)
        cout << a << endl;
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, h);
            swap(a[l], a[i]); // backtrack
        }
    }
}

int main()
{
    char chr[100];
    cout << "Enter a string: "; 
    cin.getline(chr, 100);

    // Permutation of the string
    permutation(&chr[0], 0);

    // Alternative method using swapping
    cout << "Permutations using swapping:" << endl;
    permute(chr, 0, strlen(chr) - 1);

    return 0;
}