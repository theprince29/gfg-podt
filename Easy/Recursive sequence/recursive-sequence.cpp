//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
int mod = 1e9+7;
    long long sequence(int n){
        // code here
       
        long long sum =0;
        int j=0;
       for(int i=1;i<=n;i++)
       {
           
           long long mul =1;
           for(int k=1;k<=i;k++)
           {
               mul = ((++j)*mul)%mod;
           }
           sum=(sum+mul)%mod;
       }
       return sum%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends