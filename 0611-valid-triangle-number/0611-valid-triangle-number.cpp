class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());

        int ans=0;
        for(int i=n-1;i>1;--i)
        {
            int r=i-1;
            int l=0;
            while(l<r)
            {
                int curr=nums[r]+nums[l];
                if(curr>nums[i])
                {
                    ans+=(r-l);
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};