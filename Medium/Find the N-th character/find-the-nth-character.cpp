//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
          unordered_map<char,string> m{{'0',"01"},{'1',"10"}};
        
        if(n==0) return s[0];
        
        int b_pow=pow(2,r);
        int idx=n/b_pow;
        n%=b_pow;
        string t1="";
        t1+=s[idx];
        while(r--)
        {
            string t="";
            for(int i=0;i<t1.size();i++)
            {
                t+=m[t1[i]];   
            }
            t1=t;
        }
        return t1[n];
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends