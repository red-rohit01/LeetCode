class Solution {
public:
    // The idea is to reverse the edge direction for each of the node and then check
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>outdegree(n),safe(n),ans;
        queue<int>q;
        for(int i=0;i<n;++i) 
        {
            for(int &v:graph[i]) 
            {
                adj[v].push_back(i);
                outdegree[i]++;
            }
        }
        for(int i=0;i<n;++i) 
        {
            if(outdegree[i]==0) q.push(i);
        }

        // for(auto &x:outdegree) cout<<x<<" ";
        
        while(!q.empty()) 
        {
            int u=q.front();
            q.pop();

            safe[u]=1;
            for(int v:adj[u]) 
            {
                if(--outdegree[v]==0) q.push(v);
            }
        }
        for (int i=0;i<n;++i) if(safe[i]) ans.push_back(i);

        return ans;
    }
};