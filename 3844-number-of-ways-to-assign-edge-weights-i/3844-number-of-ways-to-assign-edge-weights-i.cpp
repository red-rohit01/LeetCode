class Solution {
public:
    // To ensure that the final sum is odd, we must select an odd number of edges to be assigned a weight of 1.
    // Let's suppose the distance from node '1' to mx_depth be 'k'
    // Among all 2^k assignments, exactly half have odd parity and half have even parity. Thus, number of valid assignments is:
    // 2^k/2 == 2^(k-1)

    const long long mod=1e9+7;
    long long modexpo(long long a, long long b) {
        if (b == 0)
            return 1;
        long long p = modexpo(a, b / 2) % mod;
        p = (p * p) % mod;
        return (b % 2 == 0) ? p : (a * p) % mod;
    }
    int dfs(vector<int>adj[],int src)
    {
        if(adj[src].size()==0) return 0;

        int mx=0;
        for(auto &x:adj[src])
        {
            mx=max(mx,dfs(adj,x));
        }
        return 1+mx;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>adj[n+2];
        for(auto &x: edges)
        {
            adj[x[0]].push_back(x[1]);
        }

        int k=dfs(adj,1);

        return modexpo(2,k-1);
    }
};