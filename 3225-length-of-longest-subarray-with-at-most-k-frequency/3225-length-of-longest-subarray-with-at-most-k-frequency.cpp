class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int i=0,j=0;
        map<int,int>rk;
        while(j<n)
        {
            rk[nums[j]]++;
            while(rk[nums[j]]>k)
            {
                rk[nums[i]]--;
                i++;
            }
            int len=(j-i+1);
            ans=max(ans,len);
            j++;
        }
        return ans;
    }
};