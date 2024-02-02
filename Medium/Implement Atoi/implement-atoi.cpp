//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        
        int res=0;
        int a =0 ;
        int n = s[0] == '-';
        for(int i=0; i<s.size()-1; i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z' )) return -1;
        }
        
         for(int i=s.size()-1; i>0; i--){
            if(s[i]>='0' && s[i]<='9' ) res+=((s[i]-'0')*(int)pow(10,a)), a++;
            else if(s[i]>='a' && s[i]<='z') return -1;
            else if(s[i]=='-') return -1;
        }
        
        if(n) res*=-1;
        else if (s[0]>='0' && s[0]<='9' ) res += ((s[0]-'0')*(int)pow(10,a));
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends