//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
   void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
    
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') {
        return;
    }
    
    
    grid[i][j] = '0';
    
    
    vector<int> rowDir = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> colDir = {0, 0, -1, 1, -1, 1, -1, 1};
    
    for (int k = 0; k < 8; ++k) {
        dfs(grid, i + rowDir[k], j + colDir[k], n, m);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    
    int numOfIslands = 0;
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            
            if (grid[i][j] == '1') {
                ++numOfIslands;
                dfs(grid, i, j, n, m);
            }
        }
    }
    
    return numOfIslands;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends