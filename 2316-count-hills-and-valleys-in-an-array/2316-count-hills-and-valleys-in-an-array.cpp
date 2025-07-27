class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int>uniq;
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && nums[i]==nums[j]) j++;
            uniq.push_back(nums[i]);
            i=j-1;
        }

        int ans=0;
        int len=uniq.size();
        for(int i=1;i<len-1;++i)
        {
            if(uniq[i-1]<uniq[i] && uniq[i]>uniq[i+1]) ans++;

            else if(uniq[i-1]>uniq[i] && uniq[i]<uniq[i+1]) ans++;
        }
        return ans;
    }
};