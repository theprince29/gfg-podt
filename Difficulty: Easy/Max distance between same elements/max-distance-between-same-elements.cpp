//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
         unordered_map<int, int> first_occurrence;
        int max_distance = 0;  
    
        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {
            
            if (first_occurrence.find(arr[i]) != first_occurrence.end()) {
                int distance = i - first_occurrence[arr[i]];
                max_distance = max(max_distance, distance);
            } else {
            
                first_occurrence[arr[i]] = i;
            }
        }
    
        return max_distance;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends