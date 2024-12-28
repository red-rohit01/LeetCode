class Solution {
public:
    int dp[201][201][201];
    const int mod=1e9+7;
    int helper(int i,int &n,int g1,int g2,vector<int>&nums)
    {
        if(i==n)
        {
            if(g1!=0) return (g1==g2);
            return 0;
        }

        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];

        int skip=helper(i+1,n,g1,g2,nums);

        int first=helper(i+1,n,__gcd(g1,nums[i]),g2,nums);
        int second=helper(i+1,n,g1,__gcd(g2,nums[i]),nums);

        return (dp[i][g1][g2]=(0LL+skip+first+second)%mod);
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return helper(0,n,0,0,nums);
    }
};