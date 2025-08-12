class Solution {
public:
    // Use Sliding Window Concept to expand 'j' till !(nums[j]>(k*nums[i]))
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans=n;
        while(j<n)
        {
            if((1LL*nums[j]>(1LL*k*nums[i]))) i++;

            int curr_del=n-(j-i+1);
            ans=min(ans,curr_del);
            j++;
        }
        return ans;
    }
};