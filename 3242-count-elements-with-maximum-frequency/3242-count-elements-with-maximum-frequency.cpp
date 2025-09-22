class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(101);
        int res=0,cnt=1;
        for(auto &x:nums)
        {
            int ind=x-1;
            freq[ind]++;
            if(freq[ind]>res)
            {
                res=freq[ind];
                cnt=1;
            }
            else if(freq[ind]==res) cnt++;
        }
        return (cnt*res);
    }
};