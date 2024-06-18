//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    int f(int day, int last, vector<vector<int>>& dp, vector<vector<int>>& points) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; ++task) {
                if (task != last) {
                    maxi = max(maxi, points[day][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for (int i = 0; i < 3; ++i) {
            if (i != last) {
                maxi = max(maxi, points[day][i] + f(day - 1, i, dp, points));
            }
        }

        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1, 3, dp, points);
    }
        
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends