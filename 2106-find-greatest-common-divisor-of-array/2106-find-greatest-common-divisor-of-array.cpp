class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=nums[0],mn=nums[0];
        for(auto &x:nums)
        {
            mx=max(mx,x);
            mn=min(mn,x);
        }

        return __gcd(mx,mn);
    }
};