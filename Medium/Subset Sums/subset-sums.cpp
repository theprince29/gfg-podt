//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void func(int ind, int sum, vector<int>& arr, int N, vector<int>& v) {
        if (ind == N) {
            v.push_back(sum);
            return;
        }
        func(ind + 1, sum, arr, N, v);
        func(ind + 1, sum + arr[ind], arr, N, v);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> v;
        int sum = 0;
        func(0, sum, arr, N, v);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends