class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<int>mx_r(n),mx_l(n);
        mx_r[n-1]=nums[n-1];
        mx_l[0]=nums[0];
        for(int i=n-2;i>=0;--i)
        {
            mx_r[i]=max(mx_r[i+1],nums[i+1]);
        }
        
        for(int i=1;i<n;++i)
        {
            mx_l[i]=max(mx_l[i-1],nums[i-1]);
        }
        
        for(int i=1;i<n-1;++i)
        {
            long long temp=(1LL*mx_l[i]-1LL*nums[i])* 1LL*mx_r[i];
            ans=max(ans,temp);
        }
        return ans;
    }
};