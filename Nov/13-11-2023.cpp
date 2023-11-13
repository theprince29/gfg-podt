// Problem Link : https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
      int shortestCommonSupersequence(string x, string y, int m, int n)
{
    // code here
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m ; i++)
    {
        for (int j = 1; j <= n ; j++)
        {
            int match = 0;
            int nm = 0;
            if (x[i-1] == y[j-1])
                match = 1 + dp[i-1][j-1];
            else
                nm = max(dp[i-1][j],dp[i][j-1]);
            dp[i][j] = max(match, nm);
        }
    }
    int val = dp[m][n];
    return ((m + n) - val);
}
};
