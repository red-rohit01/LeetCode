class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;

        while(l<h)
        {
            if(nums[l]<nums[h]) return nums[l];

            int mid=l+(h-l)/2;
            if(nums[mid]>=nums[l]) l=mid+1;
            
            else h=mid;
        }

        return nums[l];

        // int ans=INT_MAX;
        // int index=-1;           // The number of times nums has been rotated equal the index value of the lowest element in '0' based
        // while(low<=high) 
        // {
        //     int mid=(low+high)/2;
        //     //search space is already sorted
        //     //then nums[low] will always be
        //     //the minimum in that search space:
        //     if(nums[low]<=nums[high]) 
        //     {
        //         if(nums[low]<ans) 
        //         {
        //             index=low;
        //             ans=nums[low];
        //         }
        //         break;
        //     }

        //     //if left part is sorted:
        //     if(nums[low]<=nums[mid]) 
        //     {
        //         // keep the minimum:
        //         if(nums[low]<ans) 
        //         {
        //             index=low;
        //             ans=nums[low];
        //         }

        //         // Eliminate left half:
        //         low=mid+1;
        //     }
        //     else //if right part is sorted:
        //     {
        //         // keep the minimum:
        //         if(nums[mid]<ans) 
        //         {
        //             index=mid;
        //             ans=nums[mid];
        //         }

        //         // Eliminate right half:
        //         high=mid-1;
        //     }
        // }
        // return ans;
    }
};