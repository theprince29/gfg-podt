//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int idx1, int idx2, string &s1, string &s2, int &maxLen, vector<vector<int>> &dp) {
        if (idx1 < 0 || idx2 < 0) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        helper(idx1 - 1, idx2, s1, s2, maxLen, dp);
        helper(idx1, idx2 - 1, s1, s2, maxLen, dp);
        
        if (s1[idx1] == s2[idx2]) {
            dp[idx1][idx2] = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, maxLen, dp);
            maxLen = max(maxLen, dp[idx1][idx2]);
            return dp[idx1][idx2];
        } else {
            dp[idx1][idx2] = 0;
            return 0;
        }
    }

    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        helper(n - 1, m - 1, str1, str2, maxLen, dp);
        return maxLen;
    }
};    
    

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends