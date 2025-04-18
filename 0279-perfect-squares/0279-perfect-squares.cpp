class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1,(int)1e9);
        int i=0;
        dp[0]=0;

        for(int i=1;i<=n;++i)
        {
            int j=1;
            while((j*j)<=i)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
                j++;
            }
        }
        return dp[n];
    }
};