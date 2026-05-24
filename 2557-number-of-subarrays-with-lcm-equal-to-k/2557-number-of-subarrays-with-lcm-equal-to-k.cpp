class Solution {
public:
    // The idea is to store the frequency of all the lcm values ending at each index 'i'.
    // The HCF of a set of numbers can never be larger than the smallest number in that set.
    // The LCM of a set of numbers can never be smaller than the largest number in that set.
    
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            unordered_map<int,int>currFreq;
            for(auto &x:freq)
            {
                int lcmVal=lcm(x.first, nums[i]);
                if(lcmVal==k) ans+=freq[x.first];
                if(lcmVal<=1000) currFreq[lcmVal]+=freq[x.first];
            }
            if(nums[i]==k) ans++;
            currFreq[nums[i]]++;

            freq.clear();
            freq=currFreq;
        }
        return ans;
    }
};