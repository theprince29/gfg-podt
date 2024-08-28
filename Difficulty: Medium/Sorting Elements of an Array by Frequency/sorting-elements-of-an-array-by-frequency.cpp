//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        pair<int,int>p;
        int n = arr.size();
        unordered_map<int, int> freqMap;
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]]++;
        }
        
        
        vector<pair<int, int>> freqVec;
        for (auto& it : freqMap) {
            freqVec.push_back({it.second, it.first});  
        }
        
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
        return a.first > b.first;
    });
        
        
        vector<int> result;
        for (auto& it : freqVec) {
            for (int i = 0; i < it.first; i++) {
                result.push_back(it.second);
            }
        }
     
     
     return result;   
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends