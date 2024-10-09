//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& arr) {
        //initializing first node
        Node* origin = new Node(arr[0][0]);
        Node* rowHead = origin;  
        Node* prevRowHead = origin; 
        Node* temp = origin;
        //initializing first row connecting to first node
        for (int j = 1; j < arr[0].size(); ++j) {
            temp->right = new Node(arr[0][j]);
            temp = temp->right;
        }
        //initializing remaining row
        for (int i = 1; i < arr.size(); ++i) {
            //initializing first node of a row
            rowHead = new Node(arr[i][0]);
            prevRowHead->down = rowHead;
            temp = rowHead;  
            Node* prevRow = prevRowHead->right;  
            //initializing  row connecting to above  node
            for (int j = 1; j < arr[i].size(); ++j) {
                temp->right = new Node(arr[i][j]);
                temp = temp->right;
                //check if above node in not null and point it down
                if (prevRow) {
                    prevRow->down = temp;
                    prevRow = prevRow->right; 
                }
            }
            //move last row downward
            prevRowHead = prevRowHead->down;
        }
        return origin;  
   
    }
};

//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends