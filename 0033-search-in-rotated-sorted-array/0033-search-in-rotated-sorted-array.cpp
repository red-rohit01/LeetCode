class Solution {
public:
    // Binary search can be applied normally even if only one part is sorted because we know very well to handle with sorted
    // array and can take appropriate decision to the sorted part for sure.
    // One of the other solution would be to find the pivot element and then Two Binary search, one from low--> Pivot and 
    // other from Pivot->high
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return mid;
            
            // I'm sure that left part is sorted
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<=nums[mid]) h=mid-1;
                else l=mid+1;
            }
            else // Only right part is sorted
            {
                if(nums[mid]<=target && target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};