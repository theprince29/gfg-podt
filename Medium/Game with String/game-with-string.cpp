//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<int>pq;
        for(auto x:mp)
        {
            if(x.second != 0)
            {
                pq.push(x.second);
            }
        }
        
        
        for(int i=0;i<k;i++)
        {
            int a = pq.top();
            pq.pop();
            
            a--;
            if(a>0){
                pq.push(a);
                
            }
        }
        
        
      int minValue = 0;
        while(!pq.empty()) {
            minValue += pq.top() * pq.top();
            pq.pop();
        }
      return minValue;  
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends