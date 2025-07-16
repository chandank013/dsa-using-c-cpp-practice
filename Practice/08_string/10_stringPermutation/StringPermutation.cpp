#include <iostream>
using namespace std;

// function to permute a string
void permute(char *str, int k)
{
    static int A[10] = {0};
    static char res[10];
    if (str[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = str[i];
                A[i] = 1;
                permute(str, k + 1);
                A[i] = 0; // backtrack
            }
        }
    }
}

// function for permutations of a string
void permute(char *str, int l, int r)
{
    int i;
    if (l == r)
        cout << str << endl;
    else
    {
        for (i = l; i <= r; i++)
        {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]); // backtrack
        }
    }
}



int main()
{
    char str[] = "ABC";
    cout << "Permutations using static array:" << endl;
    permute(str, 0);
    cout << "Permutations using swapping:" << endl;
    permute(str, 0, 2); // length of str is 3, so r = 2
    return 0;
}