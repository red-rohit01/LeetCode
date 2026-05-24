class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            unordered_map<int,int>currFreq;
            for(auto &x:freq)
            {
                int gcdVal=__gcd(x.first, nums[i]);
                if(gcdVal==k) ans+=freq[x.first];

                currFreq[gcdVal]+=freq[x.first];
            }
            if(nums[i]==k) ans++;
            currFreq[nums[i]]++;

            freq.clear();
            freq=currFreq;
        }
        return ans;
    }
};