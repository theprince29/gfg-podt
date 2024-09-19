//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  private:
    int MOD  = 1e9+7;
    int fun(int ind, int target, vector<int>& arr,vector<vector<int>>&dp) {
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        
        if(ind == 0) {
            if(target == 0 && arr[ind] == 0) return 2; // Consider 2 cases: taking or not taking the zero
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        
        int nottake = fun(ind - 1, target, arr,dp);
        int take = 0;
        if(arr[ind] <= target) take = fun(ind - 1, target - arr[ind], arr,dp);
        
        return dp[ind][target] = (nottake + take)%MOD;
    }

  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int ts = 0;
        for(int i : arr) ts += i;
        
        
        // Check if (ts - d) is valid
        if(ts - d < 0 || (ts - d) % 2 != 0) return 0;
        
        int target = (ts - d) / 2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        
        return fun(n - 1, target, arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends