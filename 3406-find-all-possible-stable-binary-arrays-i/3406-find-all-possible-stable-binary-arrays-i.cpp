class Solution {
public:
    const int mod=1e9+7;
    int dp[201][201][2];
    int helper(int zero,int one,bool flag,int limit)
    {
        if(zero==0 && one==0) return 1;

        int ans=0;
        if(dp[zero][one][flag]!=-1) return dp[zero][one][flag];

        if(flag)   // It means I've last time filled '1'
        {
            for(int i=1;i<=min(zero,limit);++i) ans=(ans%mod + helper(zero-i,one,0,limit)%mod)%mod;
        }
        else
        {
            for(int i=1;i<=min(one,limit);++i) ans=(ans%mod + helper(zero,one-i,1,limit)%mod)%mod;
        }
        return (dp[zero][one][flag]=ans%mod);
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int a=helper(zero,one,0,limit);
        int b=helper(zero,one,1,limit);
        return (a%mod + b%mod)%mod;
    }
};