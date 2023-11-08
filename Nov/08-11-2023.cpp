// Problem Link: https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1
// Given a matrix of size N x N. Print the elements of the matrix in the snake like pattern depicted below.

class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        vector<int>v;
        // code here
        for(int i=0; i<matrix.size(); i++)
        {
            if(i%2 == 1)
            {
                reverse(matrix[i].begin(),matrix[i].end());
            }
            for(int element : matrix[i])
            {
                v.push_back(element);
            }
        }
        return v;
    }
};
