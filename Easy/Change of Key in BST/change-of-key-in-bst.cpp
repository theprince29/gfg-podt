//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;
	
	node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}


node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    node *root = new node(stoi(ip[0]));

    // Push the root to the queue
    queue<node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new node(stoi(currVal));

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
            currNode->right = new node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// Function to change a key value in Binary Search Tree
struct node *changeKey(struct node *root, int oldVal, int newVal);

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        struct node *root = NULL;
        int n, temp, oldKey, new_key;
        string s;
        getline(cin,s);
        
        
        cin>>oldKey;
        getchar();
        cin>>new_key;
        getchar();
        root = buildTree(s);
        
        root = changeKey(root, oldKey, new_key);
        inorder(root);
        printf("\n");
    }
	return 0;
}



// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct node
{
	int key;
	struct node *left, *right;
};
*/
// your task is to complete the Function
// Function is used to change a key value in the given BST
// Note: Function should return root node to the new modified BST
void building(struct node*root,vector<int>vt,int &index)
{
    if(root==NULL)
        return;
    if(index>=vt.size())
        return;
    building(root->left,vt,index);
    root->key = vt[index];
    index++;
    building(root->right,vt,index);
}
void inorder(struct node* root,int oldval,vector<int>&vt)
{
    if(root==NULL)
        return ;
    
    inorder(root->left,oldval,vt);
    if(root->key != oldval)
        vt.push_back(root->key);
    inorder(root->right,oldval,vt);
}
struct node *changeKey(struct node *root, int oldVal, int newVal)
{
    // Code here
    vector<int> vt;
    inorder(root,oldVal,vt);
    vt.push_back(newVal);
    sort(vt.begin(),vt.end());
    int index=0;
    building(root,vt,index);
    return root;
}

