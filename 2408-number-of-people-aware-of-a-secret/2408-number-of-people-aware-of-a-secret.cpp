class Solution {
public:
    const int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1);           // Number of people who knows the secret on i'th day
        dp[1]=1;
        int secret=0;
        for(int i=2;i<=n;++i)
        {
            secret=(secret % mod + dp[max(i-delay,0)]%mod)%mod;
            secret=(secret%mod -dp[max(i-forget,0)]%mod + mod)%mod;
            dp[i]=secret;
        }
        int ans=0;
        for(int i=n-forget+1;i<=n;++i)  // starting the loop from (n-forget+1) because person before this day would have forgot ans hence no contribution in the ans
        {
            ans=(ans%mod + dp[i]%mod)%mod;
        }
        return ans;
    }
};