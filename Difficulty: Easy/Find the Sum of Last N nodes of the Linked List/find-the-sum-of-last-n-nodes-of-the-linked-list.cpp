//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        
        
            if (head == NULL || n <= 0) {
                return 0;
            }

    struct Node* current = head;
    int total = 0;
    int count = 0;

    while (current != NULL) {
        total += current->data;
        current = current->next;
        count++;
    }

    if (n >= count) {
        return total;
    }

    current = head;
    int sumLastN = 0;
    int nodesToSkip = count - n;

    while (nodesToSkip > 0) {
        current = current->next;
        nodesToSkip--;
    }

    while (current != NULL) {
        sumLastN += current->data;
        current = current->next;
    }

    return sumLastN;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends