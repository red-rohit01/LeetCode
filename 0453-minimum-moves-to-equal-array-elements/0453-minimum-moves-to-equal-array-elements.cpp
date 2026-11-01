class Solution {
public:
    // Raising (n-1) elements by 1 is same as relative to the other element, as lowering that single remaining element by 1. 
    // Now, all that matters for making everything equal is the differences b/w elements and both operations changes those differences in exactly the same way.

    // Reframe each move as "decrement one element by 1". Every element must be brought down to the minimum of the array.
    // Total moves = sum (nums[i]-mn) == sum - n*mn
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int mn=nums[0];
        for(int i=0;i<n;++i)
        {
            sum+=1LL*nums[i];
            mn=min(nums[i],mn);
        }

        return (sum - n*mn);
    }
};