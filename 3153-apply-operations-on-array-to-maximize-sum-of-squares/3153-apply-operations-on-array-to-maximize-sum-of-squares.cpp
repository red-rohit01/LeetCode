class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        const int mod=1e9+7;
        vector<int>bits(32);
        for(int i=0;i<n;++i)
        {
            int val=nums[i];
            int j=0;
            while(val>0)
            {
                int temp=val&1;
                bits[j]+=temp;
                val/=2;
                j++;
            }
        }

        while(k--)
        {
            long long num=0;
            for(int i=31;i>=0;--i)
            {
                if(bits[i]>0)
                {
                    num=(num | (1<<i));
                    bits[i]--;
                }
            }
            ans=(ans%mod + (num%mod * num%mod)%mod)%mod;
        }
        return ans;
    }
};