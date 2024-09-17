//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int MOD = 1e9 + 7;
class Solution{

    // private:
    // int fun(int ind, int arr[], int target, vector<vector<int>> &dp) {
    //     if (ind == 0) {
    //         // Check if the element itself can form the target sum
    //         if (target == 0 && arr[0] == 0) return 2; // Two ways: include or exclude 0
    //         if (target == 0 || arr[0] == target) return 1; // Either empty subset or the single element equals target
    //         return 0;
    //     }
    //     if (target == 0) return 1;

    //     if (dp[ind][target] != -1) return dp[ind][target]; 

    //     int nottake = fun(ind - 1, arr, target, dp);
    //     int take = 0;
    //     if (arr[ind] <= target) take = fun(ind - 1, arr, target - arr[ind], dp);

    //     return dp[ind][target] = (take + nottake)%MOD;
    // }

    public:
    int perfectSum(int arr[], int n, int sum) {
        const int MOD = 1e9 + 7;
        
        // dp[j] will be the number of subsets with sum exactly j
        vector<int> dp(sum + 1, 0);
        
        // Base case: one way to make sum 0 (empty subset)
        dp[0] = 1;
        
        // Iterate over all elements in the array
        for (int i = 0; i < n; i++) {
            // Traverse backwards to avoid overwriting results in dp array
            for (int j = sum; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }
        
        return dp[sum];
    
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends