class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        int len=nums.size();
        vector<int>freq(len+3);
        for(int i=0;i<len;++i)
        {
            if(freq[nums[i]]>0)
            {
                ans.push_back(nums[i]);
                if(ans.size()==2) return ans;
            }
            freq[nums[i]]++;
        }
        return ans;
    }
};