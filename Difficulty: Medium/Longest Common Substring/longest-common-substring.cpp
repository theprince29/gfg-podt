//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    private:
    int fun(int ind1, int ind2, string &str1, string &str2, vector<vector<int>>& dp, int &maxLength) {
        if (ind1 < 0 || ind2 < 0) return 0;
    
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
    
        if (str1[ind1] == str2[ind2]) {
            dp[ind1][ind2] = 1 + fun(ind1 - 1, ind2 - 1, str1, str2, dp, maxLength);
            maxLength = max(maxLength, dp[ind1][ind2]);
            return dp[ind1][ind2];
        } else {
            dp[ind1][ind2] = 0; 
            return dp[ind1][ind2];
        }
    }
    
    
    
    
    
  public:
    int longestCommonSubstr(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    int maxLength = 0; 

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            fun(i, j, str1, str2, dp, maxLength);
        }
    }

    return maxLength; 
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