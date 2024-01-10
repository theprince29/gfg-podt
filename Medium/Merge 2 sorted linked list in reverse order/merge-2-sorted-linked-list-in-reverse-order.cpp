//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    void push(Node** headr,int new_data)
    {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*headr);
        (*headr) = new_node;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        vector<int>v;
        while(node1 !=NULL)
        {
            v.push_back(node1->data);
            node1 = node1 ->next;
        }
        while(node2 !=NULL)
        {
            v.push_back(node2->data);
            node2 = node2 ->next;
        }
        
        sort(v.begin(),v.end());
        
        
        Node* head =NULL;
        
        for(int i=0;i<v.size();i++)
        {
            push(&head,v[i]);
        }
        
        
        return head;
        
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends