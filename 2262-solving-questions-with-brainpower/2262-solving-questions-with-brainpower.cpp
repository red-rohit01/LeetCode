class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n);
        dp[n-1]=1LL*questions[n-1][0];
        
        for(int i=n-2;i>=0;--i)
        {
            auto temp=questions[i];
            int points=temp[0];
            int skip=temp[1];
            dp[i]=1LL*points;
            if((i+skip+1)<n)
            {
                dp[i]+=dp[i+skip+1];
            }
            dp[i]=max(dp[i],dp[i+1]);
        }

        long long ans=dp[0];
        for(int i=1;i<n;++i) ans=max(ans,dp[i]);

        return ans;
    }
};