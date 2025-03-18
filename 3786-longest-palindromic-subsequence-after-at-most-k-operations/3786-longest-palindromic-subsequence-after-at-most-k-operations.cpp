class Solution {
public:
    // The idea is to Try out all the possibilities with the help of dp
    int helper(int i,int j,string &s,auto &dp,int curr)
    {
        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j][curr]!=-1) return dp[i][j][curr];

        int diff=abs(s[i]-s[j]);
        diff=min(diff,26-diff);
        int ans=0;
        if(diff<=curr) ans=max(ans,2+helper(i+1,j-1,s,dp,curr-diff));

        ans=max(ans,helper(i+1,j,s,dp,curr));
        ans=max(ans,helper(i,j-1,s,dp,curr));

        return dp[i][j][curr]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));

        return helper(0,n-1,s,dp,k);
    }
};