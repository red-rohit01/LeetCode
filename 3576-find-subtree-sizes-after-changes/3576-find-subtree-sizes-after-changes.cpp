class Solution {
public:
    // One of the solution can be to create a new adj and then check the subtree other way is we can straight away
    // calculate the number of subtree rooted for each node 'i'

    int dfs(int st,vector<int>adj[],vector<int>&ans,vector<int>&last_node,string &s)
    {
        int curr_sz=1;
        int prev=last_node[s[st]-'a'];
        last_node[s[st]-'a']=st;
        for(auto &x:adj[st])
        {
            curr_sz+=dfs(x,adj,ans,last_node,s);
        }

        ans[st]+=curr_sz;
        last_node[s[st]-'a']=prev;
        if(prev!=-1) 
        {
            ans[prev]+=ans[st];
            return 0;      // If it's not the part of it's current parent, return it's contribution to be 0
        }
        return ans[st];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        
        vector<int>adj[n];
        for(int i=1;i<n;++i)
        {
            adj[parent[i]].push_back(i);
        }

        vector<int>ans(n);
        //vector<int>new_adj[n];
        vector<int>last_node(26,-1);

        dfs(0,adj,ans,last_node,s);
        return ans;
    }
};