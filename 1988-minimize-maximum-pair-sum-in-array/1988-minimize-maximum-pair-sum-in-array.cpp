class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j)
        {
            int val=nums[i]+nums[j];
            ans=max(val,ans);
            i++;
            j--;
        }
        return ans;
    }
};