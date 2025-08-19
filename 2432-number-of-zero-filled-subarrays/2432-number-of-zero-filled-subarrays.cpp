class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        long long freq=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) freq++;
            else
            {
                ans+=1LL*(freq*(freq+1))/2;
                freq=0;
            }
            if(i==n-1)     // Handling the last case explicitly
            {
                ans+=1LL*(freq*(freq+1))/2;
                freq=0;
            }
        }
        return ans;
    }
};