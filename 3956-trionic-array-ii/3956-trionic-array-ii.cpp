class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        /*
                        dp[1]       /dp[3]
                       /  \        /
                      /    \      /
        ---dp[0]---- /     dp[2]
        

        dp[0] = start phase
        dp[1] = 1st increaseing phase
        dp[2] = 1st decreaseing phase
        dp[3] = 2nd increasing
        */
        long long ans=-1e18;
        vector<vector<long long>>dp(4,vector<long long>(n,-1e18));

        for(int i=0;i<n;++i)
        {
            dp[0][i]=1LL*nums[i];

            if(i>0)
            {
                // start increasing phase here OR we are already in increasing phase
                if(nums[i]>nums[i-1]) dp[1][i]=max(dp[0][i-1]+nums[i], dp[1][i-1]+nums[i]);

                // start decreasing phase here OR continue the decreasing phase from previous
                if(nums[i]<nums[i-1]) dp[2][i]=max(dp[1][i-1]+nums[i], dp[2][i-1]+nums[i]);

                // start 2nd increasing phase from here OR continue the increasing phase from previous
                if(nums[i]>nums[i-1]) dp[3][i]=max(dp[2][i-1]+nums[i], dp[3][i-1]+nums[i]);
            }
            ans=max(ans,dp[3][i]);
        }
        return ans;
    }
};