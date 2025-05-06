class Solution {
public:
    // O(1) space 
    // We noticed that the range of values of the elements in nums is [0,999] inclusive, which means that both the 'current value' and the 'final value' of each element in nums are within the closed interval [0,999].
    // Therefore, we can use a concept similar to the "1000-based system" to represent the "current value" and "final value" of each element. For each element, we use the quotient 
    // when it is divided by 1000 to represent its "final value," and the remainder to represent its "current value."

    // Therefore, we can use a concept similar to the "1000-based system" to represent the "current value" and "final value" of each element. 
    // For each element, we use the quotient when it is divided by 1000 to represent its "final value," 
    // and the remainder to represent its "current value."
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            nums[i]+=1000*(nums[nums[i]]%1000);
        }

        // Get the final value
        for(int i=0;i<n;++i) nums[i]/=1000;

        return nums;
    }
};