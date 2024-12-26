class Solution {
public:
    // The idea is to check out all of the different possibilities. Here I've initialized 'curr' with '1000' and not '0' because the 
    // given array consist of negative numbers too. so, It's not possible to denote any negative sum in 'dp' so, taken an offset of
    // '1000'. 
    int helper(vector<int>&nums,int i,int &n,int curr,int &target,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if((curr-1000)==target) return 1;
            else return 0;
        }

        if(dp[i][curr]!=-1) return dp[i][curr];

        int ways=0;
        ways+=helper(nums,i+1,n,curr+nums[i],target,dp);   // Trying out the '+' possibility

        ways+=helper(nums,i+1,n,curr-nums[i],target,dp);   // Trying out the '-' possibility

        return (dp[i][curr]=ways);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sm=0;
        for(auto &x:nums) sm+=x;
        if(target>sm || (sm+target)%2!=0) return 0;  // Why this (sm+target)%2 ? At the final configuration,(plus_sum-minus_sum==target)
        // Now, replacing minus_sum--> (sm-plus_sum) then  (plus_sum-(sm-plus_sum))==target) ==> (2*plus_sum-sm)==target ==> 2*plus_sm==(sm+target)
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sm+1001,-1));
        
        int curr=1000;
        int ans=helper(nums,0,n,curr,target,dp);
        return ans;
    }
};