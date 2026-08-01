class Solution {
public:
    int helper(int i,int j,int buy,vector<int>&nums,vector<vector<vector<int>>>&dp)
    {
        if(i>j) return 0;

        if(dp[i][j][buy]!=-1) return dp[i][j][buy];

        if(buy==1) dp[i][j][buy]=max(nums[i]+helper(i+1,j,0,nums,dp), nums[j]+helper(i,j-1,0,nums,dp));
        
        else dp[i][j][buy]=min(helper(i+1,j,1,nums,dp),helper(i,j-1,1,nums,dp));
        
        return dp[i][j][buy];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));

        int total=0;
        for(int i=0;i<n;++i) total+=nums[i];
        
        int temp=helper(0,n-1,1,nums,dp);
        return (temp>=(total-temp));
    }
};