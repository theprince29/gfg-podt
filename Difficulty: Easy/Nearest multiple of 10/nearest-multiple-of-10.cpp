//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
     int last = str.length() - 1;

        
        int lastDigit = str[last] - '0';

        
        if (lastDigit > 5) {
            
            str[last] = '0';

            
            int i = last - 1;
            str[i]++; 

            
            while (i >= 0) {
                
                if (str[i] > '9') {
                    str[i] = '0'; 
                    i--;
                    if (i >= 0) {
                        str[i]++; 
                    }
                } else {
                    break; 
                }
            }
            if (i < 0) {
                str = '1' + str;
            }
        } else {

            str[last] = '0';
        }


        return str;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends