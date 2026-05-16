class Solution {
public:
    // Approach-1:
    // for e.g., nums=[8,8,11,12,2,3,3,6,6,7,8,8]
    // In this case: Perform linear scan to skip initial values equal to the last element since these values do not affect the 
    // search direction. now nums=[11,12,2,3,3,6,6,7,8,8]
    // Then simply Binary search

    // Approach-2:
    // Instead of performing a linear scan within an indeterminate segment:
    // The algorithm recursively divides the region into subsegments until it hits the base case of a single element or a strictly sorted range.
    // It then aggregates the results using the minimum function.

    // In the best case, it can prune a large segment consisting of all duplicates except for the last element.
    // In the worst case (all elements equal) every segment is indeterminate:
    // Therefore, no branches get pruned, forcing the algorithm to split down to 1-element segments, which degrades the time complexity to linear time O(n).

    // Nice explanation: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/solutions/8244875/solution-by-la_castille-zqoe

    int findMin(vector<int>& nums) {
        int n=nums.size();
        // Approach 1:
        int last=nums[n-1];
        int left=0, right=n-1;

        while(left<n-1 && nums[left]==last) left++;

        while(left<right) 
        {
            int mid=left+(right-left)/2;

            if (nums[mid]>last) left=mid+1;
            else right=mid;
        }
        return nums[left];

        // Approach 2:
        //return dnc(0,n-1,nums);
    }

    int dnc(int left, int right, vector<int>&nums)
    {
        if(left==right) return nums[left];
        if(nums[left]<nums[right]) return nums[left];

        int mid=left+(right-left)/2;

        return min(dnc(left,mid,nums),dnc(mid+1,right,nums));
    }
};