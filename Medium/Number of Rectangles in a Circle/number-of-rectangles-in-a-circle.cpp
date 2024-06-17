//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   
  
    int rectanglesInCircle(int r) {
     int rectangles = 0;

        int diameter = 2 * r;
        int diameterSquare = diameter * diameter;

        for (int a = 1; a < 2 * r; a++) {
            for (int b = 1; b < 2 * r; b++) {
                int diagonalLengthSquare = a * a + b * b;
                    if (diagonalLengthSquare <= diameterSquare) {
                rectangles++;
                    }
                }
            }

        return rectangles;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends