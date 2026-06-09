class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;

        int mx=nums[0],mn=nums[0];
        for(auto &x:nums)
        {
            mx=max(mx,x);
            mn=min(mn,x);
        }

        ans=1LL*(mx-mn)*1LL*k;
        return ans;
    }
};