class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int mn=nums[0];
        for(int i=0;i<n;++i)
        {
            if((nums[i]-mn)>k)
            {
                ans++;
                mn=nums[i];
            }
        }
        ans++;
        return ans;
    }
};