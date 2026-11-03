class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int total=0;
        for(auto &x: nums)
        {
            mx=max(mx,x);
            total+=x;
        }

        return (n*mx-total);
    }
};