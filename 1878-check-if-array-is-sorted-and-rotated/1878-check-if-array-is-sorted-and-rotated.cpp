class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        for(int i=1;i<n;++i)
        {
            if(nums[i]<nums[i-1])
            {
                if(flag==false) return false;
                else
                {
                    flag=false;
                }
            }
        }

        if(flag==false) return (nums[n-1]<=nums[0]);
        return (nums[n-1]>=nums[0]);
    }
};