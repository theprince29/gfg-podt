//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int  l = 0 , h = arr.size()- 1;
        int floore  =h ; 
        int ceile = 0 ;
        while(l<=h)
        {
           int mid = l + (h - l )/2;
            
            
            if(arr[mid] < x)
            {
                ceile = mid ; 
                l = mid +1;
            }
            else if(arr[mid] == x)
            {
                ceile = mid;
                floore = mid;
                break;
                
            }
            else
            {
                floore = mid;
                h = mid - 1 ; 
            }
        }
        int ans_ceile;
        int ans_floore;
        if(arr[0] > x) ans_ceile = -1;
        else ans_ceile = arr[ceile];
        if(arr[n-1]<x) ans_floore = -1;
        else ans_floore = arr[floore];
        
        return {ans_ceile,ans_floore };
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends