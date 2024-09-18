//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
  
    vector<vector<int>> dp;
    
    
    int f(int ind, vector<int>& wt, vector<int>& val, int W) {
        // Base case
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }
        
       
        if (dp[ind][W] != -1) return dp[ind][W];
        
        // Option 1: Not take the current item
        int nottake = f(ind - 1, wt, val, W);
        
        // Option 2: Take the current item (if it can fit into the knapsack)
        int take = 0;
        if (wt[ind] <= W) {
            take = val[ind] + f(ind - 1, wt, val, W - wt[ind]);
        }
        
        // Store and return the maximum of taking and not taking the item
        return dp[ind][W] = max(take, nottake);
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        
        // Initialize the memoization table with -1 (indicating uncalculated states)
        dp = vector<vector<int>>(n, vector<int>(W + 1, -1));
        
        // Call the recursive function starting from the last item
        return f(n - 1, wt, val, W);
    }
};






//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends