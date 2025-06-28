class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        multimap<int,int>freq;
        for(int i=0;i<n;++i) freq.insert({nums[i],i});

        int ind=0;
        for(auto &x:freq)
        {
            x.second=ind;
            ind++;
        }

        for(int i=0;i<n;++i)
        {
            auto it=freq.find(nums[i]);
            int ind=(n-(it->second));
            freq.erase(it);
            if(ind<=k) ans.push_back(nums[i]);
        }
        return ans;
    }
};