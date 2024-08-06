//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    private:
    vector<string> splitz(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        
        stringstream ss(s);
    
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
    
        return tokens;
    }
  public:
    int isValid(string str) {
        // code here
        string s = str;
        vector<string> li = splitz(s,'.');
        
        for(auto x: li)
        {
            int n = stoi(x);
            if( !(n>=0 && n<=255) )
            {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends