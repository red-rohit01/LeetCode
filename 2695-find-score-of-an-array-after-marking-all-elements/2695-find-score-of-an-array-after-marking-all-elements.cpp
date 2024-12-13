class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;++i)
        {
            pq.push({nums[i],i});
        }
        
        long long ans=0;
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            long long val=1LL*(x.first);
            int ind=x.second;
            if(vis[ind]==1) continue;

            ans+=val;
            vis[ind]=1;
            if((ind-1)>=0) vis[ind-1]=1;
            if((ind+1)<n) vis[ind+1]=1;
        }
        return ans;
    }
};