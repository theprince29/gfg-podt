//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     vector<vector<int>> create_adj_list(vector<vector<int>> &graph, int n) {
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && i != j) {
                    adj_list[i].push_back(j);
                }
            }
        }
        return adj_list;
    }

    void dfs(int node, vector<vector<int>> adjc, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adjc[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjc, visited);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int n) { 
    
        vector<vector<int>> adjc = create_adj_list(adj, n);
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adjc, visited);
                count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends