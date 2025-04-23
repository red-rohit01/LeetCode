class Solution {
public:
    // This problem is different from LC-33, As it contains duplicates too.
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return true;
            
            // The only difference is that due to the existence of duplicates, we can have nums[l]==nums[mid] and in that case, the first half
            // could be out of order(i.e., not ascending [3,1,2,3,3,3]). In this case, It is guaranteed that nums[right] also equals to nums[mid]
            // so, we can have this check before the original logic to move both left and right towards mid by '1'
            if(nums[mid]==nums[l] && nums[mid]==nums[h])
            {
                l++;
                h--;
                continue;
            }
            if(nums[mid]>=nums[l])
            {
                if(target<=nums[mid] && target>=nums[l]) h=mid-1;
                else l=mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
        }
        return false;
    }
};