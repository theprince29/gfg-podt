//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
        int fun(int ind , int W , int val[],int wt[],vector<vector<int>>&dp) 
        {
            if(ind == 0) 
            {
                return W/wt[ind] * val[ind];
            }
            
            if(dp[ind][W] != -1) return dp[ind][W];
            
            int nottake = fun(ind-1,W,val,wt,dp);
            int take  = INT_MIN;
            
            if(wt[ind] <= W) take = val[ind] + fun(ind,W-wt[ind] , val ,wt,dp);
            
            return dp[ind][W] =  max(nottake,take);
            
            
        }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return fun(N-1,W,val ,wt,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends