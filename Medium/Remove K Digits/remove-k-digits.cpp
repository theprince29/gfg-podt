//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char>st;
        for(int i=0;i<S.size();i++){
            // basically we have to maintain the non-decreasing order for the digits
            // so we will try to do this using stack data structure ;
            while(!st.empty() && K && st.top()>S[i]){
                st.pop();
                K--;
            }
            st.push(S[i]);
        }
        // check if we had removed all the digits or not if yes then return "0";
        if(st.empty()) return "0";
        // we have the min but we have only limited to K digits only so remove the digits untill we have as much digits we had as the value of K
        while(K--) st.pop();
    
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // remove the leading zero from ans string
        int i=0;
        while(ans[i]=='0') i++;
        return (i==ans.length()?"0":ans.substr(i));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends