//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    

    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int> prev(4, 0);
        
        // Base case initialization for the first day
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});
        
        // Iterating over each day
        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0);
            
            // Calculate the max points for each possible last task
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        temp[last] = max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            
            // Update prev to temp for the next iteration
            prev = temp;
        }
        
        // The result is the maximum points with no task constraint on the last day
        return prev[3];
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