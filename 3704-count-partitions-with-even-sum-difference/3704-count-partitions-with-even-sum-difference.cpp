class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        int ans=0;
        for(auto &x: nums) total+=x;

        int curr=0;
        for(int i=0;i<n-1;++i)
        {
            curr+=nums[i];
            if((total-2*curr)%2==0) ans++;
        }
        return ans;
    }
};