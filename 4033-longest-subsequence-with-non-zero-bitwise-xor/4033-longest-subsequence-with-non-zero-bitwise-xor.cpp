class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorValue=0;
        bool nonZero=false;

        for(auto &x:nums)
        {
            xorValue^=x;
            if(x!=0) nonZero=true;
        }

        if(xorValue!=0) return n;

        if(nonZero) return (n-1); // works because removing even one non-zero element will always change the xor value to be non-zero.

        return 0;
    }
};