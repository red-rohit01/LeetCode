class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=nums[0];
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && nums[j]==nums[j-1]+1) j++;

            int curr=nums[j-1]+1;
            while(j<n && curr!=nums[j])
            {
                ans.push_back(curr);
                curr++;
            }
            i=j-1;
        }
        return ans;
    }
};