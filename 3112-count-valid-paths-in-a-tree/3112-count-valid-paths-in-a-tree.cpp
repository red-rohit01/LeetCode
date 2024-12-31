class Solution {
public:
    // Count how many zero-paths and one-paths at current node
    // zero-path: a path from current node to any subtree node contains zero prime
    // one-path: a path from current node to any subtree node contains one prime

    pair<int,int> dfs(vector<int>adj[],int st,int p,vector<bool>&sieve,long long &ans)
    {
        pair<int,int> my_result={!sieve[st],sieve[st]};   // no. of paths from me "goes down" that has no prime numbers i.e., zero
        // no. of paths from me that has only one prime number i.e., ones

        // If 'root' is a prime number then clearly 
        // root_A=0
        // root_B= Summation of 'A' on all children of 'root'

        // If 'root' is not a prime number, then:
        // root_A= Summation of 'A' on all children
        // root_B= Summation of 'B' on all children

        for(auto &x:adj[st])
        {
            if(x!=p)
            {
                auto child_res=dfs(adj,x,st,sieve,ans);

                int child_res_zero=child_res.first;
                int child_res_one=child_res.second;

                ans+= 1LL*my_result.first* 1LL*child_res_one;
                ans+= 1LL*my_result.second* 1LL*child_res_zero;

                if(sieve[st]==true) my_result.second+=child_res_zero;

                else
                {
                    my_result.first+=child_res_zero;
                    my_result.second+=child_res_one;
                }
            }
        }

        return my_result;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool>sieve(n+1,1);
        sieve[0]=0;
        sieve[1]=0;

        for(int i=2;i*i<=n;++i)
        {
            for(int j=i*i;j<=n;j+=i) sieve[j]=0;
        }

        vector<int>adj[n+1];
        int m=edges.size();
        for(int i=0;i<m;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans=0;
        dfs(adj,1,0,sieve,ans);
        return ans;
    }
};