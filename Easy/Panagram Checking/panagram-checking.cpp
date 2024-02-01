//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s) {
        // Convert all characters to lowercase
        for (auto& ch : s) {
            ch = tolower(ch);
        }

        set<char> c;

        for (auto x : s) {
            // Check if the character is a lowercase letter
            if ('a' <= x && x <= 'z') {
                c.insert(x);
            }
        }

        return c.size() == 26;
    }
};



//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends