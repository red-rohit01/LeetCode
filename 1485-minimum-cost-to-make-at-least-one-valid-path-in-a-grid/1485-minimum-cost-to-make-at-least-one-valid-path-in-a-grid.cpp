class Solution {
public:
    // The idea is simple when we are required to move in all the four directions, Treat the questions as 'Graph' and not as 'DP'
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;

        vector<pair<int,int>>adj[total];
        vector<int>dr={-1,0,1,0,-1};

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int curr=i*n+j;

                int val=grid[i][j];
                for(int k=0;k<4;++k)
                {
                    int ni=i+dr[k];
                    int nj=j+dr[k+1];

                    if(ni<0 || ni>=m || nj<0 || nj>=n) continue;

                    int nxt=(ni*n+nj);
                    if(val==1 && k==1) adj[curr].push_back({nxt,0});

                    else if(val==2 && k==3) adj[curr].push_back({nxt,0});

                    else if(val==3 && k==2) adj[curr].push_back({nxt,0});

                    else if(val==4 && k==0) adj[curr].push_back({nxt,0});

                    else adj[curr].push_back({nxt,1});
                }
            }
        }
        int ans=m*n;
        queue<int>q;
        vector<int>mn_cost(m*n,1e9);
        mn_cost[0]=0;
        q.push(0);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            if(node==(m*n-1))
            {
                ans=min(ans,mn_cost[node]);
                continue;
            }

            for(auto &x:adj[node])
            {
                if(mn_cost[x.first]>(mn_cost[node]+x.second))
                {
                    mn_cost[x.first]=mn_cost[node]+x.second;
                    q.push(x.first);
                }
            }
        }
        return ans;
    }
};