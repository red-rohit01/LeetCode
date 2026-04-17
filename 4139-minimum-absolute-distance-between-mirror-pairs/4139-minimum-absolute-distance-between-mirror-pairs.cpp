class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int ans=n;
        for(int i=0;i<n;++i)
        {
            int val=nums[i];

            if(mp.find(val)!=mp.end()) ans=min(ans,i-mp[val]);

            int rev=0;
            while(val)
            {
                int rem=val%10;
                rev=rev*10+rem;
                val/=10;
            }

            mp[rev]=i;
        }
        if(ans==n) return -1;
        return ans;
    }
};