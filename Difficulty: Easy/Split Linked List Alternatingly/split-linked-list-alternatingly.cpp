//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node* zero = NULL; 
        Node* one = NULL;     
        Node* zero_tail = NULL; 
        Node* one_tail = NULL;  
        
        
        bool is_zero_turn = true;
        
        
        while (head != NULL) {
            if (is_zero_turn) {
        
                if (zero == NULL) {
                    zero = head;
                    zero_tail = zero;
                } else {
                    zero_tail->next = head;
                    zero_tail = zero_tail->next;
                }
            } else {
        
                if (one == NULL) {
                    one = head;
                    one_tail = one;
                } else {
                    one_tail->next = head;
                    one_tail = one_tail->next;
                }
            }
        
            head = head->next;
            
        
            is_zero_turn = !is_zero_turn;
        }
        
        
        if (zero_tail != NULL) zero_tail->next = NULL;
        if (one_tail != NULL) one_tail->next = NULL;
        
        
        return {zero, one};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends