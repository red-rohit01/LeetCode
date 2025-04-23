class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=nums[0];
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            ans=min(ans,nums[mid]);

            if(nums[l]<nums[h])             // It means 'nums' already in sorted order
            {
                ans=min(ans,nums[l]);
                return ans;
            }
            if(nums[mid]>nums[h]) l=mid+1;        // Right half is not sorted...so mnm must be on right side
            else h=mid-1;
            
        }
        return ans;
    }
};