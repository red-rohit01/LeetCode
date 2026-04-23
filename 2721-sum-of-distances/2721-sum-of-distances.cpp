class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans(n);
        
        unordered_map<int,vector<int>>rk;
        
        for(int i=0;i<n;++i) rk[nums[i]].push_back(i);
        
        for(auto &x:rk)
        {
            int val=x.first;
            vector<int>&temp=x.second;
            
            long long total_sm=0;
            for(auto &ind:temp) total_sm+=(long long)ind;

            long long pre_sm=0;
            int len=temp.size();

            for(int i=0;i<len;++i)
            {
                long long ind=temp[i];
                long long post_sm=total_sm-pre_sm-ind;

                ans[ind]+=(ind* 1LL*i);
                ans[ind]-=pre_sm;
                ans[ind]-= (ind * 1LL*(len-i-1));
                ans[ind]+=post_sm;

                pre_sm+=ind;
            }
        }
        return ans;
    }
};