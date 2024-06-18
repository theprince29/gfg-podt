//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
   vector<bool> sieve_of_eratosthenes(int max_num) {
        vector<bool> is_prime(max_num + 1, true);
        is_prime[0] = is_prime[1] = false; 

        for (int p = 2; p * p <= max_num; ++p) {
            if (is_prime[p]) {
                for (int i = p * p; i <= max_num; i += p) {
                    is_prime[i] = false;
                }
            }
        }

        return is_prime;
    }
    
    
    vector<int> getPrimes(int n) {
        // code here
        vector<bool> is_prime = sieve_of_eratosthenes(n);

        for (int a = 2; a < n; ++a) {
            if (is_prime[a] && is_prime[n - a]) {
                return {a, n - a};
            }
        }

        
        return {-1, -1};
    }
        
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends