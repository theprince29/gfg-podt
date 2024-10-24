//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
         int n = arr.size();

    // Step 1: Traverse the array and apply the modifications
    for (int i = 0; i < n - 1; ++i) {
        // If the current number and next number are valid (non-zero) and equal
        if (arr[i] != 0 && arr[i] == arr[i + 1]) {
            arr[i] *= 2;      // Double the current number
            arr[i + 1] = 0;   // Set the next number to 0
        }
    }

    // Step 2: Rearrange the array, moving non-zero elements to the front
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            result.push_back(arr[i]);  // Collect non-zero elements
        }
    }

    // Add the necessary number of zeros at the end
    while (result.size() < n) {
        result.push_back(0);
    }

    return result;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends