// Problem Link:https://www.geeksforgeeks.org/problems/c-letters-collection4552/1


class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int>ans;
        int loop=0;
        while(loop <q){
            int sum=0;
            int i=queries[loop][1];
            int j=queries[loop][2];
            int hop=queries[loop][0];
            if(i-hop>=0) for(int k=j-hop;k<=j+hop;k++) if(k>=0 && k<m) sum+=mat[i-hop][k];
            if(i+hop<n) for(int k=j-hop;k<=j+hop;k++) if(k>=0 && k<m) sum+=mat[i+hop][k];
            if(j-hop>=0) for(int k=i-hop+1;k<i+hop;k++) if(k>=0 && k<n) sum+=mat[k][j-hop];
            if(j+hop<m) for(int k=i-hop+1;k<i+hop;k++) if(k>=0 && k<n) sum+=mat[k][j+hop];
            ans.push_back(sum);
            loop++;
        }
        return ans;
    }
};
