class Solution {
public:
    // Check if A[i] == A[i - 1] or A[i] == A[i - 2]
    // If so, we return A[i]
    // If not, it must be [x, x, y, z] or [x, y, z, x].
    // We return A[0]
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=2;i<n;++i)
        {
            if((nums[i]==nums[i-1]) || (nums[i]==nums[i-2])) return nums[i];
        }
        return nums[0];
    }
};