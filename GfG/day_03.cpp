// {Driver Code Starts}
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
    public:
      void reverseArray(vector<int> &arr) {
          int n = arr.size();
          for (int i = 0; i < n / 2; i++) {
              swap(arr[i], arr[n - i - 1]);
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

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
} // } Driver Code Ends
