class Solution {
public:
    int minPair(vector<int> nums)
    {
        int minSum=1e9;
        int pos=-1;
        for(int i=0;i<(int)nums.size()-1;++i)
        {
            if((nums[i]+nums[i+1])<minSum)
            {
                minSum=nums[i]+nums[i+1];
                pos=i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &nums, int pos)
    {
        nums[pos]+=nums[pos+1];
        nums.erase(nums.begin()+pos+1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end()))
        {
            mergePair(nums, minPair(nums));
            ops++;
        }
        return ops;
    }
};