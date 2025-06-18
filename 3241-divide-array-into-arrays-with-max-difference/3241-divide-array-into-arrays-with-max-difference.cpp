class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i+=3)
        {
            int diff=nums[i+2]-nums[i];
            if(diff>k) return ans;
        }

        for(int i=0;i<n;i+=3)
        {
            vector<int>temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[i+1]);
            temp.push_back(nums[i+2]);
            ans.push_back(temp);
        }
        return ans;
    }
};