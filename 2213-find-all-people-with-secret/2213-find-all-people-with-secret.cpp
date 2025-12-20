class Solution {
public:
    void dfs(vector<vector<int>>adj[],int st,vector<int>&vis)
    {
        for(auto &x:adj[st])
        {
            if(x[1]<vis[st]) continue;

            vis[x[0]]=min(vis[x[0]],x[1]);
            dfs(adj,x[0],vis);
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // vector<int>vis(n,1e6);
        // vis[0]=0;
        // vis[firstPerson]=0;
        // vector<vector<int>>adj[n];
        // for(int i=0;i<meetings.size();++i)
        // {
        //     int u=meetings[i][0];
        //     int v=meetings[i][1];
        //     int t=meetings[i][2];
        //     adj[u].push_back({v,t});
        //     adj[v].push_back({u,t});
        // }

        // dfs(adj,firstPerson,vis);
        // vector<int>ans;
        // for(int i=0;i<n;++i) 
        // {
        //     if(vis[i]!=1e6) ans.push_back(i);
        // }
        // return ans;

        vector<bool>vis(n); 
        vis[0]=vis[firstPerson]=true;

        map<int,vector<pair<int,int>>>mp;

        for (auto& meeting : meetings) 
            mp[meeting[2]].emplace_back(meeting[0], meeting[1]); 

        for (auto& [k, v] : mp) 
        {
            unordered_map<int, vector<int>> graph;  
            unordered_set<int> st;  

            for (auto& [x, y] : v) 
            {
                graph[x].push_back(y); 
                graph[y].push_back(x); 
                if (vis[x]) st.insert(x); 
                if (vis[y]) st.insert(y); 
            }

            queue<int>q; 

            for (auto& x:st) q.push(x); 
            
            while (q.size()) 
            {
                auto x = q.front(); 
                q.pop(); 
                for (auto& y : graph[x]) 
                    if (vis[y]==false) 
                    {
                        vis[y] = true; 
                        q.push(y); 
                    }
            }
        }
        vector<int> ans; 

        for(int i=0;i<n;++i) 
            if (vis[i]) ans.push_back(i); 

        return ans;  
    }
};