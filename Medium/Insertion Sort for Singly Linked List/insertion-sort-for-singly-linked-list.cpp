//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    void push(Node** head, int new_data)
    {
        Node* new_node = new Node(new_data);
        new_node->next = (*head);
        (*head) = new_node;
    }
    Node* insertionSort(struct Node* head_ref)
    {
        vector<int>v;
        //code here
        while(head_ref != NULL)
        {
            v.push_back(head_ref->data);
            head_ref = head_ref->next;
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        Node* head = NULL;
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
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends