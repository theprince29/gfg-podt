//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int f(vector<int>& height, vector<int>& dp, int ind) {
        if (ind == 0) {
            return 0;
        }

        if (dp[ind] != -1) return dp[ind];

        int left = f(height, dp, ind - 1) + abs(height[ind] - height[ind - 1]);
        int right = INT_MAX;
        if (ind > 1) {
            right = f(height, dp, ind - 2) + abs(height[ind] - height[ind - 2]);
        }

        dp[ind] = min(left, right);
        return dp[ind];
    }

    int minimumEnergy(vector<int>& height, int n) {
        // Initialize dp vector with -1
        vector<int> dp(n, -1);
        return f(height, dp, n - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends