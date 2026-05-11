class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            string curr=to_string(nums[i]);
            //reverse(curr.begin(),curr.end());
            for(int j=0;j<curr.size();++j)
            {
                ans.push_back(curr[j]-'0');
            }
        }
        return ans;
    }
};