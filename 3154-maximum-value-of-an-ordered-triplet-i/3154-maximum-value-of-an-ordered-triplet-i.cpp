class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre_mx(n),post_mx(n);
        pre_mx[0]=nums[0];
        post_mx[n-1]=nums[n-1];
        for(int i=1;i<n;++i)
        {
            pre_mx[i]=max(pre_mx[i-1],nums[i]);
            post_mx[n-i-1]=max(post_mx[n-i],nums[n-i-1]);
        }

        long long ans=0;
        for(int j=1;j<n-1;++j)
        {
            int prev=pre_mx[j-1];
            int nxt=post_mx[j+1];

            long long curr=(1LL*prev - 1LL*nums[j])* 1LL*nxt;
            ans=max(ans,curr);
        }
        return ans;
    }
};