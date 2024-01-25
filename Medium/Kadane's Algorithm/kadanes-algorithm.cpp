//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {
    // Check for empty array
    if (n == 0) {
        // Handle empty array case (returning 0 in this example)
        return 0;
    }

    long long res = arr[0];
    long long maxending = arr[0];

    for (long long i = 1; i < n; i++) {
        maxending = max(maxending + arr[i], static_cast<long long>(arr[i]));
        res = max(res, maxending);
    }

    return res;
}
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends