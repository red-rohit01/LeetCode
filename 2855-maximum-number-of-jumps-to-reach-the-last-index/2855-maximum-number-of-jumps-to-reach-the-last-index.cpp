class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;++i)
        {
            int val=nums[i];
            for(int j=i-1;j>=0;--j)
            {
                int val2=nums[j];
                if(abs(val-val2)<=target)
                {
                    if(dp[j]!=-1) dp[i]=max(dp[i],1+dp[j]);
                } 
            }
        }
        if(dp[n-1]==0) return -1;
        return dp[n-1];
    }
};