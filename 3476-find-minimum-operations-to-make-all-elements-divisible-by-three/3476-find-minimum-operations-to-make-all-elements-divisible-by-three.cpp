class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto &x:nums)
        {
            int val=x%3;
            ans+=min(val,3-val);
        }

        return ans; 
    }
};