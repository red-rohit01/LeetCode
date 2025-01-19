class Solution {
public:
    // The idea is that both of the path from 'src1' and 'src2' must intersect at any node and post that both will follow the same path
    // Thus, using Dijakstra calculate the required 'dist' from each of the point and check for each of the node as the intersection
    void dijakstra(vector<pair<int,int>>adj[],int src,vector<long long>&dist)
    {
        dist[src]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        pq.push({0,src});

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            long long cost=temp.first;
            int node=temp.second;

            for(auto &x:adj[node])
            {
                if(dist[x.first]>(cost+1LL*x.second))
                {
                    dist[x.first]=(cost+1LL*x.second);
                    pq.push({dist[x.first],x.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<pair<int,int>>adj[n];
        vector<pair<int,int>>rev_adj[n];
        int len=edges.size();
        sort(edges.begin(),edges.end());
        for(int i=0;i<len;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            int curr_len=adj[u].size();
            if(curr_len>0 && adj[u][curr_len-1].first==v) continue; //To remove the similarity cases as in Sample-1 to have higher weight 

            adj[u].push_back({v,wt});
            rev_adj[v].push_back({u,wt});
        }

        long long ans=1e15;
        vector<long long>dist1(n,1e15);
        vector<long long>dist2(n,1e15);
        vector<long long>dist3(n,1e15);
        dijakstra(adj,src1,dist1);
        dijakstra(adj,src2,dist2);
        dijakstra(rev_adj,dest,dist3);

        for(int i=0;i<n;++i)
        {
            long long cost1=dist3[i];
            long long cost2=dist1[i];
            long long cost3=dist2[i];

            if(cost1==1e15 || cost2==1e15 || cost3==1e15) continue;

            long long curr=cost1+cost2+cost3;
            ans=min(ans,curr);
        }
        if(ans==1e15) return -1;
        return ans;
    }
};