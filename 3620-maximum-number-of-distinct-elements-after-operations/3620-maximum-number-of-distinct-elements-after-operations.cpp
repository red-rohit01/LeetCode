class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int notUsed=-1e9;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int mn=nums[i]-k;
            int mx=nums[i]+k;
            if(notUsed<mn)
            {
                notUsed=mn;
                ans++;
            }
            else if(notUsed<mx)
            {
                notUsed=notUsed+1;
                ans++;
            }
        }
        return ans;
    }
};