// problem link :https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1 
// topic related : Dynamic Programming and algorithm 
// My approch
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n,0);
	    
	    dp[0]=arr[0];
	    
	    
	    for(int i=1; i<n; i++)
	    {
	        dp[i]=arr[i];
	        for(int j=0; j<i ; j++)
	        {
	            if(arr[i]>arr[j])
	            {
	                dp[i]=max(dp[i],arr[i]+dp[j]);
	                
	            }
	        }
	    }
	    
	    int maxsum=0;
	   
	    for(int i=0; i<n; i++)
	    {
	        maxsum = max(maxsum,dp[i]);
	    }
	    return maxsum;
	}  
};
