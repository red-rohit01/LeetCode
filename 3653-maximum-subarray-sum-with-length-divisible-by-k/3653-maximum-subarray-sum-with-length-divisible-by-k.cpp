class Solution {
public:
    // We can solve it normally with O(n) space to have dp of size 'n'. Now, Let's try to solve it with O(k) space 
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> dp(k);
        int n=nums.size();
        long long res=-1e15,currSum=0;
        for(int i=0;i<n;++i) 
        {
            currSum+=nums[i];
            if(i>=k) currSum-=nums[i-k];

            if((i+1)>=k)
            {
                dp[i%k]=max(currSum, currSum+dp[i%k]);
                res=max(res,dp[i%k]);
            }
        }
        return res;
    }
};