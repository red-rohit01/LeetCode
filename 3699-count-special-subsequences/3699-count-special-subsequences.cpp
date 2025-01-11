class Solution {
public:
    // The idea is to equate on both sides by (p/q)==(s/r)
    long long numberOfSubsequences(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<string,long long>freq;
        for(int r=4;r<n;++r)
        {
            for(int p=0,q=(r-2);p<(q-1);++p)
            {
                int g=__gcd(nums[p],nums[q]);
                string curr=to_string(nums[p]/g)+"#"+to_string(nums[q]/g);
                freq[curr]++;
            }

            for(int s=(r+2);s<n;++s)
            {
                int g=__gcd(nums[s],nums[r]);
                string curr=to_string(nums[s]/g)+"#"+to_string(nums[r]/g);
                ans+=freq[curr];
            }
        }
        return ans;
    }
};