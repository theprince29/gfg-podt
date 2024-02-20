//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings
class Solution
{
public:
    int help(int i,string s,set<string>&dis){
        if(i==s.size())return 1;
        string temp;
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(dis.find(temp)!=dis.end()){
                if(help(j+1,s,dis))return 1;
            }
        }
        return 0;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        set<string>st;
        for(auto a:dictionary){
            st.insert(a);
        }
        return help(0,s,st);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends