//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    
   void merge(int arr[], int low, int mid, int high)
    {
       vector<int>temp;
        int left = low;
        int right = mid+1;
        
        
        while(left<=mid&&right<=high){
            if(arr[left]<=arr[right]){
             temp.push_back(arr[left]);
             left++;
        }
        else{
             temp.push_back(arr[right]);
             right++;
        }
    }
    
    while(left<=mid){
         temp.push_back(arr[left]);
             left++;
     }
     while(right<=high){
         temp.push_back(arr[right]);
             right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
    }
    
    
    public:
    void mergeSort(int arr[], int low, int right)
    {
        //code here
        if(low>=right) return;
        
        int mid = (low+right)/2;
        
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,right);
        
        
        merge(arr,low , mid ,right);
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends