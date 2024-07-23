# gfg-podt 23/07/2024
# "GFG PODT  with my approch!!"  -> [Solution](https://github.com/theprince29/gfg-podt/blob/main/Difficulty%3A%20Medium/Merge%20two%20BST%20's/merge-two-bst-s.cpp)


<h2><a href="https://www.geeksforgeeks.org/problems/merge-two-bst-s/1">Merge two BST 's</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two BSTs, return elements of merged BSTs in <strong>sorted </strong>form.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>BST1:
       5
&nbsp;    /   \
&nbsp;   3     6
&nbsp;  / \
&nbsp; 2   4  
BST2:<strong>
&nbsp;       </strong>2
&nbsp;     /   \
&nbsp;    1     3
&nbsp;           \
&nbsp;            7
&nbsp;           /
&nbsp;          6
<strong>Output: </strong>1 2 2 3 3 4 5 6 6 7<strong>
Explanation: </strong>After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>BST1:<strong>
&nbsp;      </strong>12
&nbsp;    /   
&nbsp;   9
&nbsp;  / \ &nbsp;  
&nbsp; 6   11
BST2:<strong>
&nbsp;     </strong>8
&nbsp;   /  \
&nbsp;  5    10
&nbsp; /
&nbsp;2
<strong>Output: </strong>2 5 6 8 9 10 11 12<strong>
Explanation: </strong>After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(m+n)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of BST1 + Height of BST2 + m + n)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ Number of Nodes ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;  


```
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    
    void func(Node *root,vector<int>& ans)
    {
        if(root == NULL)
         return;
         
        func(root->left,ans);
        ans.push_back(root->data);
        func(root->right,ans);
        
    }
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans;
        func(root1,ans);
        func(root2,ans);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
```
