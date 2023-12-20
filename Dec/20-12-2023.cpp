// Date 20-dec-2023
// link: https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1
// problem:You are given an array A of n elements. There are two players player 1 and player 2.
// A player can choose any of element from an array and remove it. If the bitwise XOR of all remaining elements equals 0 after removal of the selected element, then that player loses. Find out the winner if player 1 starts the game and they both play their best.




class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int ans = A[0];
        for(int j =1 ; j<n;j++)
        {
            ans^=A[j];
        }
        if(ans==0){
            return 1;
        }
            else{ 
            return 2;
        }
    }
};
