//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{ 
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
    int firstOccurrence(int arr[], int n, int k) {
        int low = 0, high = n - 1;
        int first = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (arr[mid] == k) {
                first = mid;
                
                high = mid - 1;
            }
            else if (arr[mid] < k) {
                low = mid + 1; 
            }
            else {
                high = mid - 1;
            }
        }
        return first;
    }

int lastOccurrence(int arr[], int n, int k) {
        int low = 0, high = n - 1;
        int last = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (arr[mid] == k) {
                last = mid;
                
                low = mid + 1;
            }
            else if (arr[mid] < k) {
                low = mid + 1; 
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }		
		
	int count(int arr[], int n, int x) {
	    // code here
	    int first = firstOccurrence(arr, n, x);
        int last = lastOccurrence(arr, n, x);
        
        // If x is not found in the array
        if (first == -1 || last == -1) {
            return 0;
        }
        
        // Calculate the number of occurrences
        return last - first + 1;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends