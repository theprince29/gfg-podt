//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        
        pair<int, int> meetings[n];
        for (int i = 0; i < n; ++i) {
            meetings[i] = make_pair(end[i], start[i]);
        }
        
        
        sort(meetings, meetings + n);
        
        
        int count = 0;
        int last_end_time = 0; 
        
        
        for (int i = 0; i < n; ++i) {
            
            
            if (meetings[i].second > last_end_time) {
                count++;            
                last_end_time = meetings[i].first;  
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends