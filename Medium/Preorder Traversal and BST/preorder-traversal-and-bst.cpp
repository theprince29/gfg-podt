//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


  
class Solution {
  public:
    
    int preIndex = 0;
    
    int canRepresentBST(int arr[], int N) {
        
        buildBST_helper(N, arr);
        
        return (preIndex == N);
    }
    
    void buildBST_helper(int n, int arr[], int min=INT_MIN, int max=INT_MAX) {
        
        if(preIndex >= n)
            return;
            
        if(min < arr[preIndex] && arr[preIndex] < max) {
            
            int rootNode = arr[preIndex];
            preIndex++;
        
            buildBST_helper(n, arr, min, rootNode);
            buildBST_helper(n, arr, rootNode, max);
            
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends