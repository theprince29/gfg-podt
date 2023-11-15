// Problem Link:https://www.geeksforgeeks.org/problems/better-string/1





class Solution {
    private:
    int solve(string s){
        unordered_map<char,int>m;
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            char ch=s[i-1];
            dp[i]=2*dp[i-1];
            if(m.find(ch)!=m.end()){
                int ind=m[ch];
                dp[i]-=dp[ind-1];
            }
            m[ch]=i;
        }
        return dp[n];
    }
  public:
    string betterString(string str1, string str2) {
        // code here
        int a=solve(str1);
        int b=solve(str2);
        if(a>=b)return str1;
        else return str2;
        
    }
};
