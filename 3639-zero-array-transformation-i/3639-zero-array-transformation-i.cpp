class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int len=nums.size();
        vector<int>action(len+1);

        int sz=queries.size();
        for(int i=0;i<sz;++i)
        {
            int l=queries[i][0];
            int r=queries[i][1];

            action[l]++;
            action[r+1]--;
        }

        int val=0;
        for(int i=0;i<len;++i)
        {
            val+=action[i];
            nums[i]-=val;
        }

        for(int i=0;i<len;++i)
        {
            if(nums[i]>0) return false;
        }
        return true;
    }
};