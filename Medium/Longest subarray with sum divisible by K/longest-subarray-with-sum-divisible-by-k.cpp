//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>mp;
	    
	    mp[0]=-1;
	    
	    
	    int ans =0;
	    int sum =0;
	     for(int i=0; i<n; i++)
	     {
	         sum +=arr[i];
	         int rem = sum%k;
	         if(rem<0)
	         {
	             rem = rem+k;
	         }
	         
	         if(mp.find(rem)!=mp.end())
	         {
	             int val= mp[rem];
	         ans=max(ans,i-val);
	         }
	         else{
	             mp[rem]=i;
	         }
	         
	     }
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends