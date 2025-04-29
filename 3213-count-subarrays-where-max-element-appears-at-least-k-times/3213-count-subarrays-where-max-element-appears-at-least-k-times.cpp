class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=nums[0];
        for(int i=0;i<n;++i) mx=max(mx,nums[i]);

        vector<int>indc;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==mx) indc.push_back(i);
        }

        int len=indc.size();
        if(len<k) return 0;

        long long ans=0;
        for(int i=0;i<=(len-k);++i)          //Traverse the 'indc' vector
        {
            int prev=indc[i];
            if(i>0) prev-=(indc[i-1]+1);     // subtracting the earlier contribution so that we don't count duplicates
            prev++;
            int next=(n-indc[i+k-1]);

            ans+=(prev*1LL * 1LL*next); // Any of the subarray can start from '0'th index to this i'th index value and can end on any of 'i+k+1' th and further values. so, just multiplying the cnt.
        }
        return ans;
    }
};