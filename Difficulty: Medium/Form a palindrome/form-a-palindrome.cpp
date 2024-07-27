//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     int solveByDP(string &s, string &a, int i, int j, vector<vector<int>> &dp) {
        if(i >= s.size() || j >= a.size()) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s[i] == a[j]) {
            ans = 1 + solveByDP(s, a, i + 1, j + 1, dp);
        }
        else {
            ans = 0 + max(solveByDP(s, a, i, j + 1, dp), solveByDP(s, a, i + 1, j, dp));
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveByRec(string &s, string &a, int i, int j) {
        if(i >= s.size() || j >= a.size()) {
            return 0;
        }
        
        int ans = 0;
        if(s[i] == a[j]) {
            ans = 1 + solveByRec(s, a, i + 1, j + 1);
        }
        else {
            ans = 0 + max(solveByRec(s, a, i, j + 1), solveByRec(s, a, i + 1, j));
        }
        return ans;
    }
    
    int longestPalindromeSubseq(string &s) {
        string a = s;
        reverse(a.begin(), a.end());
        
        vector<vector<int>> dp(s.length() + 1, vector<int>(a.length() + 1, -1));
        
        // return solveByRec(s, a, 0, 0);
        return solveByDP(s, a, 0, 0, dp);
    }
    
    int countMin(string str){
        int len = longestPalindromeSubseq(str);
        
        int insertion = str.size() - len;
        
        return insertion;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends