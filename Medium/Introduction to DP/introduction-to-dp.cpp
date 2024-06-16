//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution {
  public:
    int f(int n, vector<long long>& dp) {
        if (n <= 1) return n;
        
        if (dp[n] != -1) return dp[n];
        
        dp[n] = (f(n - 1, dp) + f(n - 2, dp)) % MOD;
        return dp[n];
    }
    
    int topDown(int n) {
        vector<long long> dp(n + 1, -1);
        return f(n, dp);
    }
    
    
    long long int bottomUp(int n) {
        // code here
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Initialize dp vector
        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        // Fill dp vector using the bottom-up approach
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends