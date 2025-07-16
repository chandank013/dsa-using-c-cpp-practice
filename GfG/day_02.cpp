// {Driver Code Starts}
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
    public:
        void pushZerosToEnd(vector<int>& arr) {
            int n = arr.size();
            int j = 0; // Index for non-zero elements
    
            // Move non-zero elements to the front
            for (int i = 0; i < n; i++) {
                if (arr[i] != 0) {
                    if (i != j) {
                        swap(arr[i], arr[j]);
                    }
                    j++;
                }
            }
        }
    };  
         

// {Driver Code Starts}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int n = arr.size();
        Solution ob;
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
