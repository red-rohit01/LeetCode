class Solution {
public:
    
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int n=nums.size();
        map<int,int>rk;
        for(int i=0;i<n;++i)
        {
            rk[nums[i]+k+1]--;
            rk[nums[i]-k]++;
        }
        int sz=rk.size();
        auto it=rk.begin();
        int curr=0;
        for(int i=0;i<sz;++i)
        {
            int val=it->first;
            int freq=it->second;
            //cout<<val<<" "<<freq<<"\n";
            curr+=freq;
            ans=max(ans,curr);
            it++;
        }
        return ans;
    }
};