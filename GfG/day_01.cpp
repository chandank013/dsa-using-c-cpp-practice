#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
public:
    // Function to find the second largest element in the array
    int findSecondLargest(vector<int> arr) {
        int n = arr.size();
        if (n < 2) {
            return -1; // Not enough elements for a second largest
        }

        int first = INT_MIN, second = INT_MIN;
        bool foundSecond = false; // Flag to track if second largest is updated

        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
                foundSecond = true; // Second largest is updated
            } else if (arr[i] > second && arr[i] != first) {
                second = arr[i];
                foundSecond = true; // Second largest is updated
            }
        }

        // If no valid second largest element exists
        if (!foundSecond || second == INT_MIN) {
            return -1;
        }
        return second;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the number of test cases

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line of input
        stringstream ss(input);
        int num;

        // Parse the input into a vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int ans = ob.findSecondLargest(arr);
        cout << ans << endl;
    }

    return 0;
}