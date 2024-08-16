//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int fun(int n, int x, int y, int z, vector<int>& dp) {
        
        if (n == 0) return 0;
        
        if (n < 0) return INT_MIN;
        
        if (dp[n] != -1) return dp[n];
        
        int cx = fun(n - x, x, y, z, dp);
        int cy = fun(n - y, x, y, z, dp);
        int cz = fun(n - z, x, y, z, dp);
        
        int maxCuts = max({cx, cy, cz});
        
        
        if (maxCuts == INT_MIN) return dp[n] = INT_MIN;
        
        return dp[n] = 1 + maxCuts;
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        int result = fun(n, x, y, z, dp);
        return result < 0 ? 0 : result;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends