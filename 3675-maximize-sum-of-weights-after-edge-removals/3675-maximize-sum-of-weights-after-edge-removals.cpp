class Solution {
public:
    // Important concept of dp on edges not on nodes.
    
    long long solve(auto &adj, int &k,int st,int p,int is_parent_rem, auto &dp)
    {
        if(dp[st][is_parent_rem]!=-1) return dp[st][is_parent_rem];

        long long ans=0;
        int sz=adj[st].size();
        vector<pair<long long,long long>>candidates;
        for(auto &x:adj[st])
        {
            int v=x.first;
            int wt=x.second;
            if(v!=p)
            {
                long long dont_remove=solve(adj,k,v,st,0,dp)+ 1LL*wt;
                long long remove=solve(adj,k,v,st,1,dp);

                candidates.push_back({dont_remove,remove});
            }
        }

        sort(candidates.begin(),candidates.end(),[&](auto &a,auto &b)
        {
            long long d_remove1=a.first;
            long long remove1=a.second;
            long long d_remove2=b.first;
            long long remove2=b.second;

            return (remove1-d_remove1)>=(remove2-d_remove2);
        });

        int len=candidates.size();

        int req_remove=max(0, sz-k-is_parent_rem);

        for(int i=0;i<len;++i)
        {
            long long d_remove=candidates[i].first;
            long long remove=candidates[i].second;
            if(i<req_remove) ans+=remove;

            else ans+=max(d_remove,remove);
        }

        return dp[st][is_parent_rem]=ans;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int len=edges.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &x:edges)
        {
            int u=x[0];
            int v=x[1];
            int w=x[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<vector<long long>>dp(len+1,vector<long long>(2,-1));
        return solve(adj,k,0,-1,0,dp);
    }
};