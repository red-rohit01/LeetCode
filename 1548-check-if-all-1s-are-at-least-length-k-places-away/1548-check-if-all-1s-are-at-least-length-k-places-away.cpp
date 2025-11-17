class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int prev=-1e9;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==1)
            {
                int diff=(i-prev-1);
                if(diff<k) return false;
                prev=i;
            }
        }
        return true;
    }
};