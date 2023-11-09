// Problem Link:https://www.geeksforgeeks.org/problems/predict-the-column/1

// Given a matrix(2D array) M of size N*N consisting of 0s and 1s only. The task is to find the column with maximum number of 0s.
// If more than one column exists, print the one which comes first. If the maximum number of 0s is 0 then return -1.

class Solution{
    public:
        int columnWithMaxZeros(vector<vector<int>>arr,int n){
        int col = 0, num = 0;
        for(int i = 0 ; i < n ;i++){
            int count = 0;
            for(int j = 0 ; j < n; j++){
                if(arr[j][i] == 0) count += 1;
            }
            if(count > num) {
                col = i; num = count;
            }
        }
        return num == 0 ? -1 : col;
    }
};
