// probelm link: https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1




class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
          int sum1 = 0; // sum of lower triangle values
        int sum2 = 0; // sum of upper triangle values
        int diagnolSum = 0; // sum of diagnol entries
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                sum1 += matrix[i][j];
                sum2 += matrix[j][i];
            }
            diagnolSum += matrix[i][i];
        }
        sum1 += diagnolSum;
        sum2 += diagnolSum;
        return {sum1,sum2};
    }
    
};
