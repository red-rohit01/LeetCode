class Solution {
public:
    int ans=INT_MAX;
    void dfs(vector<pair<int,int>>graph[],int st,int p,vector<int>&visited)
    {
        visited[st]=true;
        //int mn=INT_MAX;
        for(auto &x:graph[st])
        {
            int l=x.first;
            int wt=x.second;
            ans=min(ans,wt);
            if(l!=st && visited[l]==false)
            {
                dfs(graph,l,st,visited);
                // int temp=dfs(graph,l,st,visited);
                // wt=min(wt,temp);
                // mn=min(mn,wt);
            }
        }
        //return mn;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>graph[n+1];
        int m=roads.size();
        for(int i=0;i<m;++i)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        vector<int>visited(n+1);
        dfs(graph,1,0,visited);
        return ans;
    }
};