class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        while(k--)
        {
            int mn=nums[0];
            int ind=0;
            for(int i=1;i<n;++i)
            {
                if(nums[i]<mn)
                {
                    mn=nums[i];
                    ind=i;
                }
            }
            nums[ind]*=multiplier;
        }
        return nums;
    }
};