class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=nums[n-1]-nums[0];
        for(int i=0;i<=(n-k);++i)
        {
            int curr=nums[i+k-1]-nums[i];
            ans=min(ans,curr);
        }
        return ans;
    }
};