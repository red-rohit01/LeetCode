class Solution {
public:
    // dp[i][j]--> count of the subsequence from [0,j] in 't' from the string 's' in subsequence from [0,i]
    int helper(string &s,string &t,int i,int j,int &n,int &m,auto &dp)
    {
        if(j==m) return 1;

        if(i==n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int total=0;
        if(s[i]==t[j]) 
        {
            total+=helper(s,t,i+1,j+1,n,m,dp);
            total+=helper(s,t,i+1,j,n,m,dp);
        }
        else total+=helper(s,t,i+1,j,n,m,dp);

        return dp[i][j]=total;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return helper(s,t,0,0,n,m,dp);
    }
};