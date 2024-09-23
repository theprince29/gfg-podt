//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
    long long n = arr.size();
    

    long long sum_n = n * (n + 1) / 2;                
    long long sum_sq_n = n * (n + 1) * (2 * n + 1) / 6;

    
    long long sum_arr = 0, sum_sq_arr = 0;
    
    for (int i = 0; i < n; i++) {
        sum_arr += arr[i];                    
        sum_sq_arr += (long long)arr[i] * arr[i];
    }

    
    long long diff = sum_n - sum_arr;               
    long long sq_diff = sum_sq_n - sum_sq_arr;      

    
    long long sum_AB = sq_diff / diff; 

    int A = (diff + sum_AB) / 2;  
    int B = sum_AB - A;           

    return {B, A};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends