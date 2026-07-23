class Solution {
public:
    // mask = nums[0] | nums[1] | ... | nums[n-1]
    // mask contains every bit that ever appears in the array.

    // For n >= 3, every value from
    // 0 ... mask is achievable as the XOR of some triplet.

    // Hence, the number of distinct XOR values is simply mask + 1
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        if(n<=2) return n;

        int mask=0;
        for(int num:nums) mask|=num;
    
        return (mask+1);
    }
};