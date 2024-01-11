//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>,greater<long long>>pq;
        
        for(long long i=0; i<n;i++)
        {
            pq.push(arr[i]);
        }
        
        
        long long  res = 0;
        
        while(pq.size() >1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            
            long long curr = first+second;
            
            res+= curr;
            pq.push(curr);
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends