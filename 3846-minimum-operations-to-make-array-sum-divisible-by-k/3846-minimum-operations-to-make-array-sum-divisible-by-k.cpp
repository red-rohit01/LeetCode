class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=nums[i];
            ans%=k;
        }
        return ans;
    }
};