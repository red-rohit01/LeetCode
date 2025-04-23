class Solution {
public:
    // Binary Search would work here even if the arrays are not sorted because We're not shrink the search space to find a certain solution, 
    // but to avoid going into a search space where it's possibly no solution exists.
    // Because As per the problem, we can report any of the peak element.

    // e.g., Suppose, 4 is in the middle. _ _ _ 5 4 6 _ _ _. So, whichever side we move in this case, we are guaranteed to find a peak. 
    // Let's take the left side first, the number previous to 5 can either be smaller or greater than 5. If it's smaller, 5 is a peak. 
    // Or if it's larger, similarly look at the number previous to it. If the numbers keep on increasing on the left side,
    // i.e. 8 7 6 5 4 6 _ _ _, the left-most would be a peak.

    int findPeakElement(vector<int>& nums) {
       int n=nums.size();

       if(n==1) return 0;

       if(nums[0]>nums[1]) return 0;

       if(nums[n-1]>nums[n-2]) return (n-1);

       int l=1,h=n-2;

       while(l<=h)
       {
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

            else if(nums[mid]<nums[mid-1]) h=mid-1;
            else l=mid+1;
       }
       return -1;
    }
};