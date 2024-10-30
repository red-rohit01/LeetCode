class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>>dp(k+1,vector<int>(n+1)); // Maximum points earn if on the end of i'th day I'm at j'th city

        for(int i=1;i<=k;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int l=1;l<=n;++l)
                {
                    if(j==l)   // If we are staying in the same city on the i'th day 
                    {
                        dp[i][j]=max(dp[i][j],stayScore[i-1][j-1]+dp[i-1][j]);
                    }
                    else dp[i][j]=max(dp[i][j],dp[i-1][l]+travelScore[l-1][j-1]);
                }
            }
        }
        int ans=0;
        for(int j=1;j<=n;++j) ans=max(ans,dp[k][j]);

        return ans;
    }
};