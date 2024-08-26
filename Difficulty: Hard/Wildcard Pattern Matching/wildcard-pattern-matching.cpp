//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
int helper(int i,int j,string &str,string &pat,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        
        if(j<0 && i>=0) return false;
        
        if(i<0 && j>=0){
            for(int k=j;k>=0;k--){
                if(pat[k]!='*') return false;
            }
            
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int cond1=false;
        if(pat[j]=='*'){
            return dp[i][j]=helper(i-1,j,str,pat,dp) || helper(i,j-1,str,pat,dp);
        }
        
        else if(pat[j]=='?' || pat[j]==str[i])
            return dp[i][j]=helper(i-1,j-1,str,pat,dp);
        
        return dp[i][j]=false;
    }
    
    int wildCard(string pattern, string str) {
        // code here
        int pat=pattern.size(),s=str.size();
        vector<vector<int>>dp(s,vector<int>(pat,-1));
        return helper(s-1,pat-1,str,pattern,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends