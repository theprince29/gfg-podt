//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int subsequenceSum(string s) 
	{
	    // Your code goes here
	    int n = 0;
	    for(auto x:s) n+=(x -'0'); 
	    return n*pow(2,s.size()-1);
	}
};

//{ Driver Code Starts.



int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		Solution ob;

   		cout << ob.subsequenceSum(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends