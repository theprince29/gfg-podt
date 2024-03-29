//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends



class Solution
{
public:
    // Function to sort a linked list using Bubble Sort
    void sort(Node **head)
    {
        if (*head == nullptr || (*head)->next == nullptr) {
            return; // If the list is empty or has only one element, it's already sorted
        }

        bool swapped;
        Node *temp;
        do {
            swapped = false;
            temp = *head;

            while (temp->next != nullptr) {
                if (temp->data > temp->next->data) {
                    // Swap data if the current element is greater than the next
                    int t = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = t;
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends