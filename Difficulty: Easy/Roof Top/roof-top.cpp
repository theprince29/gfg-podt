//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0; 
    }

    int n = arr.size();
    int Steps = 0; 
    int maxSteps = 0; 
    int diff = 0;

    for (int i = 1; i < n; i++) {
        diff = arr[i] - arr[i-1];  

        if (diff > 0) {
            Steps++;  
            maxSteps = std::max(maxSteps, Steps);
        } else {
            Steps = 0; 
        }
    }

    return maxSteps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends