//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


    void help(vector<int> nums,vector<int>& res, int l,int r)
    {
        if(l>r) return;
        
        int mid = (l+r)/2;
        
        res.push_back(nums[mid]);
        
        help(nums,res,l,mid-1);
        help(nums,res,mid+1,r);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>res;
        help(nums,res,0,nums.size()-1);
        return res;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends