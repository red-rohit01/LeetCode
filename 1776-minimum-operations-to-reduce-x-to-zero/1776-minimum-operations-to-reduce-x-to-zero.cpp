class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=-x;
        for(auto &x:nums) sum+=x;
        if(sum<0) return -1;

        int i=0;
        int curr=0;
        int ans=INT_MIN;
        int j=0;
        while(j<n)
        {
            curr+=nums[j]; 
            while(i<=j && curr>sum)
            {
                curr-=nums[i];
                i++;
            }
            if(curr==sum) ans=max(ans,j-i+1);
            j++;
        }
        return ans==INT_MIN?-1:(n-ans);
    }
};