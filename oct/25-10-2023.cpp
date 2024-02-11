Problem link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
topic related : DP
  




class Solution{
public:
    
        // code here
        int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> arr(N, vector<int>(W + 1, 0));
        
        for(int i=0;i<N;i++){
            for(int j=1;j<=W;j++) {
                int pick = 0, notPick = 0;
                if(wt[i]<=j) {
                    pick  = val[i] + arr[i][j-wt[i]];
                }
                if(i>0) notPick = arr[i-1][j];

                arr[i][j] = max(pick,notPick);
            }
        }
        return arr[N-1][W];
    }
};
