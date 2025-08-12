class Solution {
public:
    const int mod=1e9+7;
    long long modexpo(long long a, long long b) 
    {
        if (b==0) return 1;
        
        long long p = modexpo(a, b / 2) % mod;
        p = (p * p) % mod;
        return (b % 2 == 0) ? p : (a * p) % mod;
    }

    int helper(vector<vector<int>>&dp,int n,int x,int i)
    {
        if(n==0) return 1;
        
        if(n<0) return 0;
        
        if(modexpo(i,x)>n) return 0;
        
        if(dp[n][i]!=-1) return dp[n][i];
        
        int temp=modexpo(i,x);
        int val1=helper(dp,n,x,i+1);
        int val2=helper(dp,n-temp,x,i+1);
        
        return dp[n][i]=(val1%mod + val2%mod)%mod;
    }
    int numberOfWays(int n, int x) {
//          vector<int>dp(n+1);
//          dp[1]=1;
//          dp[0]=1;
        
//         for(int i=2;i<=n;++i)
//         {
//             int j=1;
//             while(j<=n/x)
//             {
//                 int val=modexpo(j,x);
//                 if((j-val)>=0)
//                 {
//                     dp[i]=(dp[i]%mod+dp[j-val]%mod)%mod;
//                 }
//                 j++;
//             }
//         }
//         return dp[n];

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(dp,n,x,1);
    }
};